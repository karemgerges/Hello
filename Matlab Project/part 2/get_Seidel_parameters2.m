    function [EquationsNumber,equ,symstr,precision,max] = get_Seidel_parameters(NumOfEquations,symbolstring)
    EquationsNumber = str2double(NumOfEquations);
    n = 0;
    prompt1 = {'Enter The Equation:'};
    prompt2 = {'Enter the precision:'};
    prompt3 = {'Enter The number of iterations:'};
    dlg_title = 'equations';
    num_lines = 1;
    defaultans = {''};
    defaultans2 = {'0.00001'};
    defaultans3 = {'50'};
    equations = {''};
    while n < EquationsNumber
        answer1 = inputdlg(prompt1,dlg_title,num_lines,defaultans);
         if(n > 0 && n < (EquationsNumber))
            equations = strcat(equations,' \n ',{' '});
        end
            equations = strcat(equations,answer1);
            n = n+1;
    end
    answer2 = inputdlg(prompt2,dlg_title,num_lines,defaultans2);
    answer3 = inputdlg(prompt3,dlg_title,num_lines,defaultans3);
    precision = str2double(answer2);
    max = str2double(answer3);
    symstr = char(symbolstring);
    equ = char(equations);
