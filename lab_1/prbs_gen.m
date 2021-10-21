plant_id
close all
clearvars -except th

T = 20;

t = 0.02:0.02:T;
prbs = idinput(length(t), 'prbs', [0 0.1]);
u_prbs.time = t.';
u_prbs.signals.values = prbs;
u_prbs.signals.dimensions = 1;

clear T
clear t

yh = idsim ([0 prbs], th);

plot(u_prbs.time, u_prbs.signals.values,...
     u_prbs.time, yh)
 
