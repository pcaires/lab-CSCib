close all
clear all
clc

figure(1)
load('lab_1/lab_1_calpot.mat')
plot(input.time,input.signals.values,'linewidth',1,...
     tensao_pot.time,tensao_pot.signals.values,'linewidth',1)
legend('Tensão de entrada','Tensão no potenciómetro',...
       'location','northwest')
xlim([0 3])
ylim([-0.2 5.5])
ylabel('Tensão (V)')
xlabel('Tempo (s)')

print(1,'motorDC1.tex')

figure(2)

m = min(tensao_pot.signals.values);
M = max(tensao_pot.signals.values);
min_max = [[1 1]'*m [1 1]'*M]

plot(input.time,input.signals.values,'linewidth',1,...
     tensao_pot.time,tensao_pot.signals.values,'linewidth',1,...
     [0;10],min_max,'--r')


legend('Tensão de entrada','Tensão no potenciómetro',...
       'location','southwest')
ylabel('Tensão (V)')
xlabel('Tempo (s)')


xlim([0 10])
ylim([-10 7])    

text(6,-6, ['min: ' num2str(m) ' V $\implies 180^o$ '])
text(6, 6, ['max: ' num2str(M) ' V $\implies -180^o$ '])  
   
       
print(2,'motorDC2.tex')
