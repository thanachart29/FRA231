main_dir = pwd;
hw_zip = dir(fullfile(pwd,'*.zip'));
file_name = {hw_zip.name};
testcase = cell(1,17);
grade = zeros(80,17,2);
for i = 1:17
    if i<10
        testcase{i} = sprintf('testcase_0%d',i);
    else
        testcase{i} = sprintf('testcase_%d',i);
    end
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
                if ismember(j,[1 3 5 7 9 10 11 12 13 14 16])
                    [P_test,p_f_test,flag_test] = trackBot(p_i,c,W);
                elseif ismember(j,[2 4 5 6 8 15 17])
                    [P_test,p_f_test,flag_test] = trackBot(p_i,c);
                end
                isCorrect = true;
                if j<14
                    isCorrect = isCorrect && all(abs(flag-flag_test)<0.000001,'all');
                else
                    isCorrect = isCorrect && all(abs(flag-flag_test)<0.000001,'all');
                    isCorrect = isCorrect && all(abs(P-P_test)<0.00000001,'all');
                    isCorrect = isCorrect && all(abs(p_f-p_f_test)<0.00000001,'all');
                end
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
            grade(ID(k),j,class) = false;
        end
    end
end

your_ID = 36;
class = 1;  % รุ่น 7
% class = 2; % รุ่น 6
weight = [0.5*ones(1,13) 5*ones(1,2) 0.5*ones(1,2)];
homework_grade = (grade(your_ID,:,class)*weight')*10/sum(weight);
disp(sprintf('Your HW1 grade (ID==%d) is %.2f out of 10',your_ID,homework_grade));