function x = LUDecomp(eqnStr,symStr, n)
%LUDecomp(eqnStr,symStr, n) solves the n-by-n linear system of equations using partial
%pivoting
%A is the coeficient matrix
%b the right-hand column vector

%Author: Mohamed Raafat 
%Date: May 2017

[A,b] = getEqnsMatrices(eqnStr,symStr,n);

%A = [A,b];      %produces the augmented matrix

% An n-element array for storing scaling factors
s = zeros(n,1);  

% Use as indexes to pivot rows.
o = zeros(n,1);

x = zeros(n,1);

[A,o] = Decompose( A,n,s,o );


 x = Substitute_LU( A, o, n, b); 
 

end

