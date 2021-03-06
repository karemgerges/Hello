function [root,iterations,precision,execution_time,allUpper,allLower,allroots,errors,allvalue]  = false_position( low,upp,err,func,max )
%UNTITLED7 Summary of this function goes here
%   Detailed explanation goes here
now=tic();

f = func;
if(f(low)*f(upp)>=0 || low>upp)
    iterations =0;
    root= 0;
precision=0;
execution_time=0;
allUpper=0;
allLower=0;
allroots=0;
allvalue=0;
errors=0;

    return
end

counter=1;
es(counter)=50;
lower(counter)=low;
upper(counter)=upp;

  fu=f(upp);
    fl=f(low);
    xr(counter)=((fu*low)-(fl*upp))/(fu-fl);
    values(counter)=f(xr(counter));
while(abs(es(counter))>err & f(lower(counter))~=0 & f(upper(counter))~=0 &f(xr(counter))~=0& counter<=max)
    if(fl*f(xr(counter))<0)
        upper(counter+1)=xr(counter);
        lower(counter+1)=lower(counter);
    else
        lower(counter+1)=xr(counter);
        upper(counter+1)=upper(counter);
    end
  counter=counter+1;
      fu=f(upper(counter));
      fl=f(lower(counter));
      xr(counter)=(fu*lower(counter)-fl*upper(counter))/(fu-fl);
      values(counter)=f(xr(counter));
      es(counter)=((xr(counter)-xr(counter-1))/xr(counter));
	  er(counter)=abs(double((xr(counter)-xr(counter-1))));
end
last=toc(now);
root= xr(counter);
iterations=counter;
precision=es(counter);
execution_time=last;
allUpper=upper;
allLower=lower;
allroots=xr;
allvalue=values;
errors=er;
