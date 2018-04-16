function [root,iterations,precision,execution_time,allroots,allValues,errors]  = fixed_point( point,err,G,max )
%UNTITLED7 Summary of this function goes here
%   Detailed explanation goes here
now=tic();
f = G;
syms x
fd(x)=diff(f,x);
if(abs(fd(point))>1)
    root= 0;
iterations=0;
precision=0;
execution_time=0;
allValues=0;
allroots=0;
errors=0;
 
    return
end
counter=1;
es(counter)=50;
xr(counter)=f(point);
values(counter)=f(xr(counter));
while(abs(es(counter))>err  &f(xr(counter))~=0 &counter<=max)
  counter=counter+1;
  xr(counter)=f(xr(counter-1));
  values(counter)=f(xr(counter));
  es(counter)=((xr(counter)-xr(counter-1))/xr(counter));
  er(counter)=abs(double((xr(counter)-xr(counter-1))));
end
last=toc(now);
root= xr(counter);
iterations=counter;
precision=es(counter);
execution_time=last;
allValues=values;
allroots=xr;
errors=er;
