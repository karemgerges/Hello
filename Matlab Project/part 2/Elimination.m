function [ A,err ] = Elimination( A, n ,s ) 
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
err = 0;
for k = 1: n-1
    
    [A,s] = Pivoting( A,n,s,k ); % Partial Pivoting

    if abs(A(k,k)/s(k)) < realmin('double') % Check for singularity
          disp('No unique solution');
          err = -1;
        return;
    end

    % Forward Elimination
    for i = k+1 : n
        factor = A(i,k)/ A(k,k);
        for j = k+1 : n+1
            A(i,j) = A(i,j) - factor * A(k,j);
        end        
    end
    
    if abs(A(n,n)/s(n) )< realmin('double')  % Check for singularity
           disp('No unique solution');
           err = -1;
    end
    
    
end

