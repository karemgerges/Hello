function [root,iterations,precision,execution_time,allroots,allValues,errors]  = newton( point,err,func,max )
%UNTITLED7 Summary of this function goes here
%   Detailed explanation goes here
now=tic();
syms x
f = func;
fd(x)=diff(f,x);
counter=1;
es(counter)=50;
xr(1)=1;
      xr(counter)=point-((f(point))/(fd(point)));
values(counter)=f(xr(counter));
while(abs(es(counter))>err  &f(xr(counter))~=0 &counter<=max)
 
  counter=counter+1;
      xr(counter)=xr(counter-1)-(f(xr(counter-1))/fd(xr(counter-1)));
      values(counter)=f(xr(counter));
      es(counter)=((xr(counter)-xr(counter-1))/xr(counter));
	  er(counter)=abs(double((xr(counter)-xr(counter-1))));
end
last=toc(now);
root= xr(counter);
iterations=counter;
precision=es(counter);
execution_time=last;
allroots=xr;
allValues=values;
errors=er;
