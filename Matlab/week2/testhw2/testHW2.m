function isCorrect = testHW2(var)
t_max = var.t_max;
t_i = var.t_i;
t_f = var.t_f;
q_i = var.q_i;
q_f = var.q_f;
model_name = 'test_model';
open_system([pwd '\' model_name],'loadonly');
dt = 0.01;
set_block_param(model_name,[],'SolverType','Fixed-step')
set_block_param(model_name,[],'SolverName','FixedStepAuto')
set_block_param(model_name,[],'FixedStep',dt)
set_block_param(model_name,[],'StopTime',t_max)
set_block_param(model_name,'q_i','Value',q_i)
set_block_param(model_name,'q_f','Value',q_f)
set_block_param(model_name,'t_i','Value',t_i)
set_block_param(model_name,'t_f','Value',t_f)
out = sim(model_name);

f_test = out.simout.Data;
save_system([pwd '\' model_name]);
close_system([pwd '\' model_name]);
isCorrect = all(abs(var.f-f_test)<0.000001,'all');
plot(out.simout.Time,f_test)
end
function set_block_param(model,block,param_name,value)
if isempty(block)
    actual_block = model;
else
    actual_block = [model '/' block];
end
if isa(value,'double')
    str = '';
    for i = 1:numel(value)
        str = [str num2str(value(i),12) ';'];
    end
    actual_value = ['[' str ']'];
else
    actual_value = value;
end
set_param(actual_block,param_name,actual_value);
end