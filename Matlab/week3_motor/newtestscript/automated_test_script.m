grade = automated_test_function(@testHW3);
close_system(find_system)

ID = 21;
class = 1; % class = 2 ถ้าเป็นรุ่น 6
weight = [0.5*ones(1,7) 1*ones(1,7)];
your_grade = grade(ID,:,class)*weight'*10/sum(weight);
fprintf('Your grade is %f\n',your_grade);

