prbs.time = input.time

values = idinput(50,'prbs',[0 1],[-2,2]);
l = length(prbs.time);

for i = 1:l
    prbs.signals.values(i) = values(int8(i*49/l)+1);
end