function [root,iterations,precision,execution_time,allroots,allValues,errors]  = secant( point1,point2,err,func,max )
%UNTITLED7 Summary of this function goes here
%   Detailed explanation goes here
now=tic();
syms x
f = func;
counter=1;
es(counter)=50;

      xr(counter)=point2-((f(point2)*(point1-point2))/(f(point1)-f(point2)));
values(counter)=f(xr(counter));
while(abs(es(counter))>err  &f(xr(counter))~=0 &counter<=max)
  
  counter=counter+1;
  if(counter<3)
            xr(counter)=xr(counter-1)-((f(xr(counter-1))*(point2-xr(counter-1)))/(f(point2)-f(xr(counter-1))));
  else
            xr(counter)=xr(counter-1)-((f(xr(counter-1))*(xr(counter-2)-xr(counter-1)))/(f(xr(counter-2))-f(xr(counter-1))));

  end
      es(counter)=((xr(counter)-xr(counter-1))/xr(counter));
	  er(counter)=abs(double((xr(counter)-xr(counter-1))));
      values(counter)=f(xr(counter));

end
last=toc(now);
root= xr(counter);
iterations=counter;
precision=es(counter);
execution_time=last;
allroots=xr;
allValues=values;
errors=er;
