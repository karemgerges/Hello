function [upper,lower,max,precision] = get_parameters(x)
if(x==1)
	prompt1 = {'Enter The upper bound:'};
    prompt2 = {'Enter The lower bound:'};
else
	prompt1 = {'Enter The first point :'};
    prompt2 = {'Enter The second point:'};
end
	prompt3 = {'Enter The max number of iterations:'};
    prompt4 = {'Enter The precision:'};
    dlg_title = 'inputs';
    num_lines = 1;
    defaultans = {''};
    defaultanswer1={'50'};
    defaultanswer2={'0.00001'};
    answer1 = inputdlg(prompt1,dlg_title,num_lines,defaultans);
    answer2 = inputdlg(prompt2,dlg_title,num_lines,defaultans);
    answer3 = inputdlg(prompt3,dlg_title,num_lines,defaultanswer1);
    answer4 = inputdlg(prompt4,dlg_title,num_lines,defaultanswer2);
    if isempty(answer3)
        answer3 = '50';
    end
    if isempty(answer4)
        answer4 = '0.00001';
    end
    upper = str2double(answer1);
    lower = str2double(answer2);
    max = str2double(answer3);
    precision = str2double(answer4);
