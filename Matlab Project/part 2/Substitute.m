function [x] = Substitute(A,n)
%UNTITLED5 Summary of this function goes here
%   Detailed explanation goes here

x(n) =double( A(n,n+1)/A(n,n));

for i = n - 1:-1:1
    sum = 0;
    for j = i+1 : n
        sum = sum + A(i,j)* x(j);        
    end
    x(i)= double((A(i,n+1) - sum) / A(i,i));
end

end

