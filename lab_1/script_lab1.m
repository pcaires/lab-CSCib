clear all

load('lab_1_calpot.mat')
kp = -360/(max(tensao_pot.signals.values)-min(tensao_pot.signals.values));


load('lab_1_calext.mat')
L = 38.1  %cm  %ENCONTRAR VALOR CERTO (18!!!)


%           cm(pente)                  V
cal_ex_0 = [0 mean(tensao_extens_0.signals.values)];
cal_ex_1 = [-0.635 mean(tensao_extens_1.signals.values)];
cal_ex_2 = [-0.635*2 mean(tensao_extens_2.signals.values)];
cal_ex_3 = [-0.635*3 mean(tensao_extens_3.signals.values)];
cal_ex_4 = [-0.635*4 mean(tensao_extens_4.signals.values)];
cal_ex_5 = [-0.635*5 mean(tensao_extens_5.signals.values)]; %sentido horario

cal_ex_1_ = [1 mean(tensao_extens_1_.signals.values)];
cal_ex_2_ = [1 mean(tensao_extens_2_.signals.values)]; 
cal_ex_3_ = [1 mean(tensao_extens_3_.signals.values)];
cal_ex_4_ = [1 mean(tensao_extens_4_.signals.values)]; %RETIRAR MEDICõES
cal_ex_5_ = [1 mean(tensao_extens_5_.signals.values)]; %sentido antihorario

data = [cal_ex_0; cal_ex_1; cal_ex_2; cal_ex_3; cal_ex_4; cal_ex_5];
ang = atan2(data(:,1),L)*180/pi

c = polyfit(ang,data(:,2),1);
fittedY = polyval(c,ang);
plot(ang,data(:,2),'o',...
     ang,fittedY);
grid on
xlabel('deg')
ylabel('V')

kb = 1/c(1)
