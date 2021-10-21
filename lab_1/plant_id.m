script_lab1

clearvars -except kp kb

load('plant_data_1.mat')

ang_mot = tensao_pot.signals.values * kp;
dang_barra = tensao_ext.signals.values * kb;

ang_barra = ang_mot + dang_barra;

t = input.time;
utrend = input.signals.values;
%u = detrend(utrend);

figure(1)
plot(t,ang_barra,...
     t,utrend)
legend('ang_{barra} (deg)', 'input (V)')

af = 0.65;
Afilt = [1 -af];
Bfilt = (1-af)*[1 -1];


y = dtrend(ang_barra);
yf = filter(Bfilt,Afilt,y);

cut = 30;

yf = yf(cut:end);
utrend = utrend(cut:end);
t = t(cut:end);

figure(2)
plot(t,yf,...
     t,utrend);
legend('ang-detrend_{barra} (deg/s)', 'input (V)');


z = [yf utrend];
na = 4;   % AR part < 5  
nb = 3;   % X part
nc = na;  % MA part
nk = 2;   % Atraso puro - pure delay 

nn = [na nb nc nk];
th = armax (z, nn);

[den1, num1]= polydata(th)

yh = filter (num1,den1, utrend);

figure(3)
plot(t,[yf yh]);

[num, den] = eqtflength(num1, conv(den1, [1 -1]));

[A, B, C, D] = tf2ss (num, den)



