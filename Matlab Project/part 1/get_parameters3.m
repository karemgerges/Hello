    function [upperbis,lowerbis,upperfalse,lowerfalse,fixedpoint,newtonpoint,secantpoint1,secantpoint2,biergepoint,maximum,prec] = get_parameters3
	prompt = {'Enter The Initial Point:'};
    prompt1 = {'Enter The upper bound:'};
    prompt2 = {'Enter The lower bound:'};
    prompt5 = {'Enter The first Point:'};
    prompt6 = {'Enter The second Point:'};
    prompt3 = {'Enter The Maximum number of iterations:'};
    prompt4 = {'Enter The precision:'};
    num_lines = 1;
    defaultans = {''};
    defaultanswer1={'50'};
    defaultanswer2={'0.00001'};
    %bisection
    dlg_title = 'For Bisection';
    bisection1 = inputdlg(prompt1,dlg_title,num_lines,defaultans);
    bisection2 = inputdlg(prompt2,dlg_title,num_lines,defaultans);
    %false_position
    dlg_title = 'For False-position';
    false1 = inputdlg(prompt1,dlg_title,num_lines,defaultans);
    false2 = inputdlg(prompt2,dlg_title,num_lines,defaultans);
    %fixed point
    dlg_title = 'For Fixed point';
    fixed = inputdlg(prompt,dlg_title,num_lines,defaultans);
    %newton raphson
    dlg_title = 'For newton raphson';
    newton = inputdlg(prompt,dlg_title,num_lines,defaultans);
    %secant
    dlg_title = 'For secant';
    secant1 = inputdlg(prompt5,dlg_title,num_lines,defaultans);
    secant2 = inputdlg(prompt6,dlg_title,num_lines,defaultans);
    %bierge-vieta
    dlg_title = 'For bierge-vieta';
    bierge = inputdlg(prompt,dlg_title,num_lines,defaultans);
    %max_iterations
    dlg_title = 'max iterations';
    max = inputdlg(prompt3,dlg_title,num_lines,defaultanswer1);
    if isempty(max)
        max = '50';
    elseif all(ismember(max, ' '))
        max = '50';
    end
    %precision
    dlg_title = 'max iterations';
    precision = inputdlg(prompt4,dlg_title,num_lines,defaultanswer2);
    if isempty(precision)
         precision = '0.00001';
    elseif all(ismember(precision, ' '))
         precision = '0.00001';
    end
	upperbis = str2double(bisection1);
    lowerbis = str2double(bisection2);
	upperfalse = str2double(false1);
    lowerfalse = str2double(false2);
    fixedpoint = str2double(fixed);
    newtonpoint = str2double(newton);
    biergepoint = str2double(bierge);
	secantpoint1 = str2double(secant1);
    secantpoint2 = str2double(secant2);
    maximum = str2double(max);
    prec = str2double(precision);
    
