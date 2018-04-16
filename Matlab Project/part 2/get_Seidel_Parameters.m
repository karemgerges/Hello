    function [EquationsNumber,equ,symstr,precesion,max] = get_Seidel_Parameters(data)
    EquationsNumber = data.data(1);
    n = 0;
    equations = {''};
    while n < EquationsNumber
         if(n > 0 && n <= (EquationsNumber))
            equations = strcat(equations,' \n ',{' '});
        end
            equations = strcat(equations,data.textdata(n + 3));
            n = n+1;
    end
    symbolstring = data.textdata(2);
    symstr = char(symbolstring);
    equ = char(equations);
    max = data.data(2);
    precesion = data.data(3);
