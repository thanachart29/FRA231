t = (0:100)';
u = sin(t/5);

A = [1   0.01    (0.01^2)/2 
     0    1         0.01 
     0    0         1];
B = [0 
     0 
     0];
C = [0 1 0];
D = 0;
Q = 2.3; 
R = 1; 

Ts = -1; %set discrete time without a specific sample time
sys = ss(A,[B B],C,D,Ts,'InputName',{'u' 'w'},'OutputName','y');

[kalmf,L,~,Mx,Z] = kalman(sys,Q,R);
% kalmf = kalmf(1,:);
% 
% w = sqrt(Q)*randn(length(t),1);
% v = sqrt(R)*randn(length(t),1);
% out = lsim(SimModel,[u,w,v]);
% yt = out(:,1);   % true response
% ye = out(:,2);  % filtered response
% y = yt + v;     % measured response
% 
% P = B*Q*B';         % Initial error covariance
% x = zeros(3,1);     % Initial condition on the state
% 
% ye = zeros(length(t),1);
% ycov = zeros(length(t),1); 
% errcov = zeros(length(t),1); 
% 
% for i=1:length(t)
%   % Measurement update
%   Mxn = P*C'/(C*P*C'+R);
%   x = x + Mxn*(y(i)-C*x);   % x[n|n]
%   P = (eye(3)-Mxn*C)*P;     % P[n|n]
% 
%   ye(i) = C*x;
%   errcov(i) = C*P*C';
% 
%   % Time update
%   x = A*x + B*u(i);        % x[n+1|n]
%   P = A*P*A' + B*Q*B';     % P[n+1|n] 
% end