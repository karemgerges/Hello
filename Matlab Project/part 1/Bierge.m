function [ root,iterations,precision,execution_time,allroots,errors ] = Bierge( point,err,func,ma)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
now=tic();
syms x
f = func;
counter=1;
es(counter)=50;
degree=feval(symengine, 'degree', f);
degree=degree+1;
g=sym(f);
a= sym2poly(g);
count=2;
xr(counter)=point;
b(1)=a(1);
c(1)=a(1);
while( counter<=ma & abs(es(counter))>err)
   
  while  (count<= degree)
     b(count)=a(count)+xr(counter)*b(count-1);
     count=count+1;
  end
count=2;
  while (count< degree)
    c(count)=b(count)+xr(counter)*(c(count-1));
      count=count+1;
  end
  counter=counter+1;
  xr(counter)=double(xr(counter-1)-(b(degree)/c(degree-1)));
  es(counter)=double(((xr(counter)-xr(counter-1))/xr(counter)));
  er(counter)=abs(double((xr(counter)-xr(counter-1))));
        if(b(degree)==0)
                break;
        end
  count=2;
end
last=toc(now);
root=double(xr(counter));
iterations=counter;
precision=es(counter);
execution_time=last;
allroots=double(xr);
errors=double(er);
