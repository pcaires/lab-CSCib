
script_lab1
clearvars -except kp kb

load lab_1_model_test.mat

ang_mot = tensao_pot.signals.values * kp;
dang_barra = tensao_ext.signals.values * kb;

ang_barra = ang_mot + dang_barra;

t = input.time;
utrend = input.signals.values;

af = 0.65;
Afilt = [1 -af];
Bfilt = (1-af)*[1 -1];


y = dtrend(ang_barra);
yf = filter(Bfilt,Afilt,y);


cut = 4/0.02;

plot(t(cut:end),[yf(cut:end) yh(cut:end)]);
legend('Real response','Simulated Response')
