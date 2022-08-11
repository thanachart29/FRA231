function isCorrect = testHW3(var)
type = var.test_type;
if type == 1
    u = var.u;
    d = var.d;
    r = var.r;
    
    model_name = 'test_signal_gen';
    
    open_system(model_name,'loadonly');
    set_block_param(model_name,'Constant','Value',u);
    out = sim(model_name);
    save_system(model_name);
    close_system(model_name);
    d_test = out.signal_test.Data(end,1);
    r_test = out.signal_test.Data(end,2);
    
    isCorrect = ((d-d_test)<0.0001)&&((r-r_test)<0.0001);
    
else
    u = var.u;
    w = var.w;
    tau = var.tau;
    model_name = 'test_dcmotor';
    option2 = 'ee.enum.dcparam_option.torque_speed';
    open_system(model_name,'loadonly');
    isOption2 = strcmp(option2,get_param([model_name '/No-load Condition/DC Motor'],'parameterization'));
    isOption2 = isOption2 && strcmp(option2,get_param([model_name '/No-load Condition/DC Motor'],'parameterization'));
    
    set_block_param(model_name,'Step','After',u);
    
    out = sim(model_name);
    save_system(model_name);
    close_system(model_name);
    w_test = out.motor_test.w.Data(end,:);  % the no-load speed for all 3 cases should be relatively close to one another
    tau_test = out.motor_test.tau.Data(end,:);    % the stall torque for all 3 cases should be relatively close to one another
    
    isCorrect = isOption2 && ((w-w_test)<0.0001)&&((tau-tau_test)<0.0001);
end
end
function set_block_param(model,block,param_name,value)
if isa(value,'double')
    actual_value = num2str(value,12);
else
    actual_value = value;
end
set_param([model '/' block],param_name,actual_value);
end