function [x,iterNum,absErr,precision,exeTime,iterations] = GaussSeidel(eqnStr,symStr, n,es,maxit)
% GaussSeidel: Gauss Seidel method
% x = GaussSeidel(A,b): Gauss Seidel without relaxation
% input:
% A = coefficient matrix
% b = right hand side vector
% es = stop criterion (default = 0.00001%)
% maxit = max iterations (default = 50)
% output:
% x = solution vector

[A,b] = getEqnsMatrices(eqnStr,symStr,n);

C = A;
for i = 1:n
C(i,i) = 0;
x(i) = 0;
end
x = x';
for i = 1:n
C(i,1:n) = C(i,1:n)/A(i,i);
end
for i = 1:n
d(i) = b(i)/A(i,i);
end

now = tic();
iter = uint32(0);
while (1)
xold = x;
for i = 1:n    
x(i) = d(i)-C(i,:)*x;
%x(i) = roundDecimal(x(i) , 8);
if x(i) ~= 0
absErr(iter+1,i) = abs(x(i) - xold(i));
ea(i) = abs((x(i) - xold(i))/x(i)) * 100;
end
end
iterations(iter+1,:) = x; % To retrun each iteration values
iter = iter+1;
if max(ea)<=es | iter >= maxit, break, end
end
precision = ea;
exeTime = toc(now);
iterNum = iter;