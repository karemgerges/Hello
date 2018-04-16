function x = GaussElim(eqnStr,symStr, n)
%GaussElimination(eqnStr,symStr, n) solves the n-by-n linear system of equations using partial
%pivoting
%A is the coeficient matrix
%b the right-hand column vector

%Author: Mohamed Raafat 
%Date: May 2017

[A,b] = getEqnsMatrices(eqnStr,symStr,n);

A = [A,b];      %produces the augmented matrix

s = zeros(n,1);

for i = 1:n
    s(i) = abs(A(i,1));
    for j = 2:n    
      if (abs(A(i,j)) > s(i))
          s(i)= abs(A(i,j));
      end
    end
end

[A,err] = Elimination( A, n ,s );

% If singular system
if err == -1
   x = -1;
   return;
end

format SHORT;

x = Substitute(A,n);

end

