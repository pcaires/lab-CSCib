close all
clear all
clc

load('lab_1/deadzone.mat');

dead = [[1;1]*0.3 [-1;-1]*0.3]

figure(1)

plot(input.time,input.signals.values,'linewidth',1,...
     tensao_pot.time,tensao_pot.signals.values,'linewidth',1,...
     [0;20],dead,'--r')
     
     
legend('Tens�o de entrada','Tens�o no potenci�metro','deadzone',...
       'location','southwest')
ylabel('Tens�o (V)')
xlabel('Tempo (s)')
xlim([0 10])
ylim([-3 4])

print(1,'deadzone.tex')