    function [initial,precision,max] = get_parameters2
    prompt = {'Enter The Initial Point:'};
    prompt2 = {'Enter The max number of iterations:'};
    prompt3 = {'Enter The precision:'};
    dlg_title = 'inputs';
    num_lines = 1;
    defaultans = {''};
    defaultanswer1={'50'};
    defaultanswer2={'0.00001'};
    answer = inputdlg(prompt,dlg_title,num_lines,defaultans);
    answer2 = inputdlg(prompt2,dlg_title,num_lines,defaultanswer1);
    answer3 = inputdlg(prompt3,dlg_title,num_lines,defaultanswer2);
    if isempty(answer2)
        answer2 = '50';
    elseif all(ismember(answer2, ' '))
        answer2 = '50';
    end
    if isempty(answer3)
        answer3 = '0.00001';
    elseif all(ismember(answer3, ' '))
       answer3 = '0.00001';
    end
    initial = str2double(answer);
    max = str2double(answer2);
    precision = str2double(answer3);
    
