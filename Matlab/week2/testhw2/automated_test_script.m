grade = automated_test_function(@testHW2);
ID = 21;
class = 1; % class = 2 ถ้าเป็นรุ่น 6
your_grade = sum(grade(ID,:,class));
fprintf('Your grade is %f\n',your_grade);
