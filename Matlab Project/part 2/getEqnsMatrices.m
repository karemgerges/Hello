function [A,b] = getEqnsMatrices( eqnStr,symStr, n )
% getEqnsMatrices( eqnStr,symStr, n ) convert string of N equations
% separated by return character into Matrix of Coefficients 
% eqnStr : The string of N equations separated by return characters.
% symStr : The string of symbols of N variables used (Hint: They are
%          separated by spaces e.g: x y z). The symbols must be consistent with the
%          eqns symbols .

% A : Matrix of Coefiicients 
% b : Matrix of right hand side values of the equations

 Tokens = {};
while ~isempty(eqnStr)
    [Tokens{end+1}, eqnStr] = strtok(eqnStr,'\n');
end

for i=1:n 
    eqnVector(i) =sym(Tokens(i));
end
Tokens2 = {};
while ~isempty(symStr)
    [Tokens2{end+1}, symStr] = strtok(symStr,' ');
end

for i=1:n 
    symVector(i) =sym(Tokens2(i));
end

[A, b] = equationsToMatrix(eqnVector,symVector);







