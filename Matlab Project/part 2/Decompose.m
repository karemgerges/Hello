function [A,o] = Decompose( A,n,s,o )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

%err = 0; % if still zero at the end then no error if -1 then there is an error
% Find scaling factors
for i = 1 : n  
    o(i) = i;
    s(i) = abs(A(i,1));
    for j = 2 : n
        if (abs(A(i,j)) > s(i))
            s(i) = abs(A(i,j));
        end
    end
end

for k = 1: n-1 
 % Locate the kth pivot row
 [A,s,o] = Pivoting_LU(A,n,s,o,k);
% Check for singular or near-singular cases
if (abs(A(o(k),k)) / s(o(k))) < realmin('double') 
   %err = -1;
return
end
    for i = k+1 : n 
    factor = A(o(i),k) / A(o(k),k);
    % Instead of storing the factors
    %in another matrix (2D array) L,
    %We reuse the space in A to store
    % the coefficients of L.
    A(o(i),k) = factor;
    % Eliminate the coefficients at column j
    % in the subsequent rows
        for j = k+1 : n
        A(o(i),j) = A(o(i),j) - factor * A(o(k),j);
        end
    end
end
% Check for singular or near-singular cases
if abs(A(o(n),n) / s(o(n))) < realmin('double')
%err = -1;
end
end 



