function[ x ,err] = EliminationJordan( A, n ,s )  
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
err = 0;
for k = 1: n
    
    [A,s] = Pivoting( A,n,s,k ); % Partial Pivoting

    if abs(A(k,k)/s(k)) < realmin('double') % Check for singularity
          disp('No unique solution');
          err = -1;
        return;
    end

    % Forward Elimination
    
    for i=1:n
        if i == k
            continue
        end
            m=A(i,k)/A(k,k);
           for j=k+1:n+1 % From k+1 to reduce the number of operations as at (j=k) the columns results = zero 
              A(i,j)=A(i,j)-m*A(k,j);
           end        
    end
   
    
    if abs(A(n,n)/s(n) )< realmin('double')  % Check for singularity
           disp('No unique solution');
           err = -1;
    end
    
    %Normalization
    for i = 1 : n
    A(i,:) = A(i,:)/A(i,i);    
   end    
    x =double( A(:,n+1));
    
    % determine the significant digits
    for i= 1:n
    x(i) = roundDecimal(x(i),6);
    end
end

