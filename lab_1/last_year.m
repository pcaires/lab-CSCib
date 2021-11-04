script_lab1

close all
clearvars -except kp kb

% load('plant_data_1.mat')
load('square100.mat')
close all

Ts = 0.02;
ang_mot = tensao_pot.signals.values * kp;
dang_barra = tensao_ext.signals.values * kb;

ang_barra = ang_mot + dang_barra;

t = input.time;
utrend = input.signals.values;

%cut1 = int16(2/Ts);
cut1 = int16(20/Ts);
ang_barra = ang_barra(cut1:end);
t = t(cut1:end);
utrend = utrend(cut1:end);

figure
plot(t,ang_barra,...
     t,utrend)
legend('ang_{barra} (deg)', 'input (V)')
grid on

af = 0.8;
Afilt = [1 -af];
Bfilt = (1-af)*[1 -1];

yf = filter(Bfilt,Afilt,ang_barra);
yf = dtrend(yf);

figure
plot(t,yf,...
     t,utrend);
legend('ang-detrend_{barra} (deg/s)', 'input (V)');

z = [yf utrend];


load('plant_data_1.mat')
ang_mot2 = tensao_pot.signals.values * kp;
dang_barra2 = tensao_ext.signals.values * kb;
ang_barra2 = ang_mot2 + dang_barra2;
utrend2 = input.signals.values;

cut2 = int16(10/Ts);
ang_barra2 = ang_barra2(cut2:end);
utrend2 = utrend2(cut2:end);

yf2 = filter(Bfilt,Afilt,ang_barra2);
yf2 = dtrend(yf2);

z2 = [yf2 utrend2];

nk = 1;   % Atraso puro - pure delay 2, 2, 1  
% nn = [1 1 1 1];
fit = 0;
max = 5;
% 
% for na = 1:max % AR part < 5 (foi o prof que disse) 4, 5, 5
%     for nb = 1:max  % X part 3, 4, 5
%         nc = na;  % MA part
%         nn = [na nb nc nk];
%         th = armax (z, nn);
%         a = fit;
%         [~,fit,~] = compare(z2,th);
%         if (fit>a)
%             a = fit;
%             b = nn;
%         end
%     end
% end

b = [5 5 5 1];
th = armax (z, b);
figure
compare(z2,th)


[den1, num1]= polydata(th);
figure
zplane(num1, den1)

yh = filter (num1,den1, utrend);

figure
plot(t,[yf yh]);

[num, den] = eqtflength(num1, conv(den1, [1 -1]));
figure
zplane(num, den)

[A, B, C, D] = tf2ss (num, den);
figure
dbode(A,B,C,D,Ts);
grid on

%% Validate the model
% load('prbs40.mat')
% load('plant_data_1.mat')
load('square100.mat')
% load('plant_data_prbs.mat')

ang_mot = tensao_pot.signals.values * kp;
dang_barra = tensao_ext.signals.values * kb;
y_real = ang_mot + dang_barra;
% cut3 = int16(10/Ts);
% y_real = y_real(cut3:end);

t_in = (0:Ts:100)';
% u_in = idinput(size(t_in, 1), 'prbs', [0 0.1]);
u_in = -1*square(2*pi*0.5*t_in); 
y_est = dlsim(A,B,C,D,u_in); %-99.3
% t_in = t_in(cut3:end);
% u_in = u_in(cut3:end);
% y_est = y_est(cut3:end);

% figure
% plot(t, utrend)

figure, hold on, grid on
% yyaxis left
% plot(t_in, u_in, 'b')
% ylabel('amplitude (V)')
% yyaxis right, grid on
plot(t_in, y_est, 'r')
plot(t_in, y_real, 'k')
% xlim([15 35])
xlim([40 90])
xlabel('time (s)')
ylabel('amplitude (deg)')
% legend('u', 'y_{est}', 'y_{real}', 'Location', 'best', 'fontsize', 12)
legend('y_{est}', 'y_{real}', 'Location', 'best', 'fontsize', 12)
