close all
clear all
clc

cd lab_1 
script_lab1
cd ..

fittedY = polyval(c,sort(ang));
figure(1)
plot(sort(ang),fittedY,'--','linewidth',1,...
     ang,data(:,2),'.','MarkerSize',12)
     
xlabel('Deflexão da barra (deg)')
ylabel('Tensão do extensómetro (V)')

legend('Regressão linear','Dados recolhidos',...
       'location','southeast')

print(1,'linreg_ext.tex')