function isCorrect = testHW4(var)
%{
  System Requirement :
  1.) Linearity : R-squared must be no larger than 0.999 
  2.) Range : Output must stay between 0 [V] and 5 [V]
  3.) Resolution : Resolution must be no larger than 0.0005 [N/bit] for
                      10-bit ADC with 5 [V] reference voltage
  4.) Standard Resistor : all resistor in Signal Conditioning Circuit must
  have standard values E24
  5.) LM358 : the op-amps in Signal Conditioning Circuit must be used via
  the provided LM358 IC.
%}

model_name = 'HW4_template_model';
open_system(model_name,'loadonly');

N = 10;
f_min = 0.5;
f_max = 1;

f = linspace(f_min,f_max,N+1);
y_o = zeros(size(f));
for i = 1:(N+1)
    set_block_param(model_name,'force','Value',f(i));
    out = sim(model_name);
    y_o(i) = out.simout.Data(end);
end
save_system(model_name);
close_system(model_name);

% check linearity
[R2,~] = linReg(f,y_o);
isLinear = R2>0.999;

open_system(model_name,'loadonly');
set_block_param(model_name,'force','Value',f(1));
out = sim(model_name);
y_min = out.simout.Data(end);
set_block_param(model_name,'force','Value',f(end));
out = sim(model_name);
save_system(model_name);
% 
y_max = out.simout.Data(end);

% output must stay within 0 [V] and 5 [V]
isInMinimumRange = y_min >= 0;
isInMaximumRange = y_max<= 5;
isInOutputInRange = isInMinimumRange && isInMaximumRange; 

% resolution must be less than 0.0005 [N/bit]
bitADC = 10;
v_ADC = 5;
resolution = (f_max-f_min)/((y_max-y_min)/v_ADC*2^bitADC);
required_resolution = 0.0005;
isSufficientRes = resolution <= required_resolution;

% check circuit implementation
SCC = [model_name '/Signal Conditioning Circuit'];
resistor_block = 'fl_lib/Electrical/Electrical Elements/Resistor';
opamp_block = 'fl_lib/Electrical/Electrical Elements/Op-Amp';
resistors = find_system(SCC,'ReferenceBlock',resistor_block);
opamps = find_system(SCC,'ReferenceBlock',opamp_block);


% 5-percent Standard Values (EIA E24)
R_val = [10 11 12 13 15 16 18 20 22 24 27 30 33 36 39 43 47 51 56 62 68 75 82 91];% * 0.001 ;
R_standard = reshape((10.^[-2:6]')*R_val,1,[]);
R_system = zeros(1,numel(resistors));
for r = resistors
    R_system = str2double(get_param(r,'R'));
end

% must use standard values
isAllRStandard = all(ismembertol(R_system, R_standard)) && ~isempty(resistors);

% must use provided LM358
isOpAmpInLM358 = true;
for i = 1:numel(opamps)
    parent = get_param(opamps{i},'Parent');
%     isOpAmpInLM358 = isOpAmpInLM358 && contains(parent(end-5:end),'/LM358');
    isOpAmpInLM358 = isOpAmpInLM358 && contains(parent(48:52),'LM358');
end

isCircuitOK = isAllRStandard && isOpAmpInLM358;
isFunctionOK = isLinear && isInOutputInRange && isSufficientRes;
isCorrect = isFunctionOK && isCircuitOK ;
if isAllRStandard == true
    disp("[1] All R standard = True")
else
    disp("[1] All R standard = False")
end
if isOpAmpInLM358 == true
    disp("[2] LM359 in circuit == True")
else
    disp("[2] LM359 in circuit == False")
end
if isLinear == true
    disp("[3] Linearity == True")
else
    disp("[3] Linearity == False")
end
if isInOutputInRange == true
    disp("[4] Output in range == True")
else
    disp("[4] Output in range == False")
end
if isSufficientRes == true
    disp("[5] Sufficient Resolution == True")
else
    disp("[5] Sufficient Resolution == False")
end
disp("--------------------------------------------")
if isCorrect == true
    disp("Correct solution")
else
    disp("wrong solution")
end
disp("--------------------------------------------")
close_system(model_name);
end

function set_block_param(model,block,param_name,value)
if isa(value,'double')
    actual_value = num2str(value,12);
else
    actual_value = value;
end
set_param([model '/' block],param_name,actual_value);
end

function [R2,y_hat] = linReg(x,y)
Y = y';
X = [ones(numel(x),1) x'];
B = X\Y;
y_hat = B(2)*x+B(1);
R2 = 1 - sum((y - y_hat).^2)/sum((y - mean(y)).^2);

end
