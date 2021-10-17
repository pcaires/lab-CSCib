script_lab1
load('plant_data.mat')

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


y = detrend(ang_barra);
yf = filter(Bfilt,Afilt,y);

cut = 30;

yf = yf(cut:end);
utrend = utrend(cut:end);
t = t(cut:end);

figure(2)
plot(t,yf,...
     t,utrend);
legend('ang-detrend_{barra} (deg)', 'input (V)');


z = [yf utrend];
na = 4;
nb = 1;
nc = na;
nk = nb;
nn = [na nb nc nk];
th = armax (z, nn);

[den1, num1]= polydata(th)

yh = idsim (utrend, th);

figure(3)
plot(t,[yf yh]);

[num, den] = eqtflength(num1, conv(den1, [1 -1]));

[A, B, C, D] = tf2ss (num, den)



