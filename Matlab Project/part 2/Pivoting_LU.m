function [A,s,o] = Pivoting_LU(A,n,s,o,k)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

% Find the largest scaled coefficient in column k
% p is the index to the pivot row
p = k ;
big = abs(A(o(k),k)) / s(o(k));
for i = k+1 : n 
    dummy = abs(A(o(i),k) / s(o(i)));
    if (dummy > big) 
        big = dummy;
        p = i;
    end
end

% Swap row k with the pivot row by swapping the
% indexes. The actual rows remain unchanged
if  p ~= k 
dummy = o(p);
o(p) = o(k);
o(k) = dummy;
end
end

