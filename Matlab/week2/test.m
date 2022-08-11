q_i = [-7;1;3;-2;7;7;10;7];
q_f = [-7;-6;-4;-3;0;5;6;7];
t_i = 1 ;
t_f = 7 ;
c = zeros(numel(q_i),4);
ax = axes;
hold on ;
t1 = 0:0.01:t_i-0.01;
t2 = t_i:0.01:t_f;
t3 = t_f-0.01:0.01:t_f+t_i;
t = [t1 t2 t3]';
z = zeros(numel(t),numel(q_i));
for i = 1:numel(q_i)
    RHS = [q_i(i) ; q_f(i) ; 0 ; 0 ];
    A = [1 t_i (t_i^2) (t_i^3) ; 1 t_f (t_f^2) (t_f^3) ; 0 1 (2*t_i) (3*(t_i^2)) ;  0 1 (2*t_f) (3*(t_f^2))] ;
    ac0 = A ;
    ac0(:,1) = RHS';
    c_0 = det(ac0)/ det(A) ;
    ac1 = A ;
    ac1(:,2) = RHS';
    c_1 = det(ac1)/ det(A) ;
    ac2 = A ;
    ac2(:,3) = RHS';
    c_2 = det(ac2)/ det(A) ;
    ac3 = A ;
    ac3(:,4) = RHS';
    c_3 = det(ac3)/ det(A) ;
    c(i,:) = [c_3 c_2 c_1 c_0];
    %g_t = c_0 + c_1*t + c_2*(t.^2) + c_3*(t.^3)
    for j = 1:numel(t)
        if t(j) < t_i
            z(j,i) = q_i(i);
        elseif t(j) >= t_i && t(j) <= t_f
            z(j,i) = c_0 + c_1*t(j) + c_2*(t(j)^2) + c_3*(t(j)^3) ;
        else
            z(j,i) = q_f(i);
        end
    end
    %plot(ax,t,z(:,i));
end
