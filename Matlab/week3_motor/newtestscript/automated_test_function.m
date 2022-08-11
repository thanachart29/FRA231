function grade = automated_test_function(testFunction)
main_dir = pwd;
hw_zip = dir(fullfile(main_dir,'*.zip'));
file_name = {hw_zip.name};
testcase_file = dir(fullfile(pwd,'testcase*.mat'));
testcase = {testcase_file.name};
num_test = numel(testcase);
grade = zeros(80,num_test,2);
for i = 1:num_test
    testcase{i} = sprintf('testcase_%d',i);
end
for i = 1:numel(file_name)
    name = file_name{i};
    if name(14)=='H'
        class = 1;
    elseif name(14)=='c'
        class = 2;
    else % numeric
        if name(17)=='H'
            class = 1;
        elseif name(17)=='c'
            class = 2;
        end
    end
    ID = sort([str2num(name([8 9])) str2num(name([11 12])) str2num(name([14 15]))]);
    
    try
        unzip(name,[num2str(class) sprintf('_%d',ID)])
        
        test_folder = [main_dir '\' [num2str(class) sprintf('_%d',ID)]];
        for j = 1:numel(testcase)
            var = load(testcase{j});
            cd(test_folder)
            try
                isCorrect = testFunction(var);
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