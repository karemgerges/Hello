function x = Substitute_LU( A, o, n, b)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here

y = zeros(n,1);

x= zeros(n,1);

y(o(1)) = b(o(1));
for i = 2 : n 
    sum = b(o(i));
    for j = 1 : i-1
        sum = sum - A(o(i),j) *y(o(j)); 
    end    
        y(o(i)) = sum;
end

x(n) = roundDecimal(double(y(o(n)) / A(o(n),n)),6);

for i = n-1 :-1: 1 
    sum = 0;
    for j = i+1 : n
        sum = sum + A(o(i),j) * x(j);
    end    
        z = (y(o(i)) - sum) / A(o(i),i);   
        x(i) = double(z);
        x(i) = roundDecimal(x(i),6);
end

end

