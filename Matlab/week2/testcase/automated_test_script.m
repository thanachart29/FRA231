main_dir = pwd;
hw_zip = dir(fullfile(pwd,'*.zip'));
file_name = {hw_zip.name};
num_test = 10;
testcase = cell(1,num_test);
grade = zeros(80,num_test,2);
for i = 1:num_test
    testcase{i} = sprintf('testcase_%d',i);
end
for i = 1:numel(file_name)
    name = file_name{i};
    if name(14)=='H'
        n = 2;
        class = 1;
    elseif name(14)=='c'
        n = 2;
        class = 2;
    else % numeric
        if name(17)=='H'
            n = 3;
            class = 1;
        elseif name(17)=='c'
            n = 3;
            class = 2;
        end
    end
    ID = sort([str2num(name([8 9])) str2num(name([11 12])) str2num(name([14 15]))]);
    
    try
        unzip(name,[num2str(class) sprintf('_%d',ID)])
        
        test_folder = [main_dir '\' [num2str(class) sprintf('_%d',ID)]];
        for j = 1:numel(testcase)
            load(testcase{j});
            cd(test_folder)
            try
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
                isCorrect = all(abs(f-f_test)<0.000001,'all');
                plot(out.simout.Time,f_test)
                fprintf('case %d is %d\n',j,isCorrect);
                for k = 1:numel(ID)
                    grade(ID(k),j,class) = isCorrect;
                end
            catch
                for k = 1:numel(ID)
                    grade(ID(k),j,class) = false;
                end
            end
            cd ..;
        end
    catch
        disp('error unzipping')
        disp([class ID])
        for k = 1:numel(ID)
            grade(ID(k),:,class) = false;
        end
    end
end

your_ID = 21;
class = 1;  % รุ่น 7
% class = 2; % รุ่น 6
homework_grade = sum(grade(your_ID,:,class));
disp(sprintf('Your HW1 grade (ID==%d) is %.2f out of 10\n',your_ID,homework_grade));

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