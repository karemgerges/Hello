function [ A,s] = Pivoting( A,n,s,k )
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here

% Assume row k is the pivot row
p = k;   

%Find the largest scaled coefficient in column k
big = abs(double(A(k,k)/ s(k)));

for i = k+1 : n 
    dummy = abs(double(A(i,k)/ s(i)));    
    if  dummy > big
       big = dummy;
       % Record new pivoting row
       p = i ;  
    end
end

% Next: Swap row p and row k if p != k

if  p ~= k 
 % Swap row p and row k
    dummy = A(p,:);
    A(p,:)= A(k,:);
    A(k,:)= dummy;

% swap spand sk
    dummy = s(p);
    s(p)= s(k);
    s(k)= dummy;
end

end

