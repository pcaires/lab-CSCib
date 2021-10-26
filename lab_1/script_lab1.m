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

cal_ex_1_ = [0.3  mean(tensao_extens_1_.signals.values)];
cal_ex_2_ = [1.1  mean(tensao_extens_2_.signals.values)]; 
cal_ex_3_ = [1.9  mean(tensao_extens_3_.signals.values)];
cal_ex_4_ = [2.54 mean(tensao_extens_4_.signals.values)]; 
cal_ex_5_ = [3.15 mean(tensao_extens_5_.signals.values)]; %sentido antihorario

data = [cal_ex_0; cal_ex_1; cal_ex_2; cal_ex_3; cal_ex_4; cal_ex_5;...
        cal_ex_1_; cal_ex_2_; cal_ex_3_; cal_ex_4_; cal_ex_5_];
ang = atan2(data(:,1),L)*180/pi

c = polyfit(ang,data(:,2),1);

kb = 1/c(1);
