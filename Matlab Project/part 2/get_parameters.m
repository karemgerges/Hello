function [EquationsNumber,equ,symstr] = get_parameters(NumOfEquations,symbolstring)
    EquationsNumber = str2double(NumOfEquations);
    n = 0;
    prompt1 = {'Enter The Equation:'};
    dlg_title = 'equations';
    num_lines = 1;
    defaultans = {''};
    equations = {''};
    while n < EquationsNumber
        answer1 = inputdlg(prompt1,dlg_title,num_lines,defaultans);
         if(n > 0 && n < (EquationsNumber))
            equations = strcat(equations,' \n ',{' '});
        end
            equations = strcat(equations,answer1);
            n = n+1;
    end
    symstr = char(symbolstring);
    equ = char(equations);