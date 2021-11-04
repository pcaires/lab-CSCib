% plant_id
clearvars -except A B C D
close all
clc


% S = zeros(6,6);
G = eye(6); % ganho do ruído
Q = C'*C;
R = 100; % experimentar R = 100
% f = A'*S*A - A'*S*B*(B'*S*B+R)^(-1)*B'*S*A +  Q == 0;
% syms S
% sol = solve(f, S)

[K,S,e] = dlqr(A,B,Q,R);

% K = (B'*S*B + R)^(-1)*B'*S*A;
% N = inv([A-eye(6,6), B; C, 0]) * [zeros(6,1);1];
N = ([A-eye(6), B; C, 0]) \ [zeros(6,1);1];
Nx = N(1:6,:);
Nu = N(6,:);
Nbar = Nu+K*Nx;

[M,~] = dlqe(A,G,C,100*eye(6),1);