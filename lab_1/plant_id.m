script_lab1

clearvars -except kp kb

%load('plant_data_prbs.mat')
load('prbs40.mat')
close all

ang_mot = tensao_pot.signals.values * kp;
dang_barra = tensao_ext.signals.values * kb;

ang_barra = ang_mot + dang_barra;

t = input.time;
utrend = input.signals.values;

cut1 = int16(2/0.02);
ang_barra = ang_barra(cut1:end);
t = t(cut1:end);
utrend = utrend(cut1:end);

figure(1)
plot(t,ang_barra,...
     t,utrend)
legend('ang_{barra} (deg)', 'input (V)')
grid on

af = 0.65;
Afilt = [1 -af];
Bfilt = (1-af)*[1 -1];


y = dtrend(ang_barra);
yf = filter(Bfilt,Afilt,y);

cut2 = 30;%int16(1/0.02);

yf = yf(cut2:end);
utrend = utrend(cut2:end);
t = t(cut2:end);

figure(2)
plot(t,yf,...
     t,utrend);
legend('ang-detrend_{barra} (deg/s)', 'input (V)');


z = [yf utrend];

nk = 1;   % Atraso puro - pure delay 2, 2, 1  
nn = [1 1 1 1];
fit = 0;
max = 5;

for na = 1:max% AR part < 5 (foi o prof que disse) 4, 5, 5
    for nb = 1:max  % X part 3, 4, 5
        b = nn;
        nc = na;  % MA part
        nn = [na nb nc nk];
        th = armax (z, nn);
        a = fit;
        [~,fit,~] = compare(z,th);
        if (fit<a)
            fit = a;
            nn = b;
        end
        fit
        nn
    end
end

th = armax (z, nn);
compare(z,th);


[den1, num1]= polydata(th);

yh = filter (num1,den1, utrend);

figure(3)
plot(t,[yf yh]);

[num, den] = eqtflength(num1, conv(den1, [1 -1]));

[A, B, C, D] = tf2ss (num, den);



