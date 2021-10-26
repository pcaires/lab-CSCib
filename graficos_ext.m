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
     
xlabel('Deflex�o da barra (deg)')
ylabel('Tens�o do extens�metro (V)')

legend('Regress�o linear','Dados recolhidos',...
       'location','southeast')

print(1,'linreg_ext.tex')