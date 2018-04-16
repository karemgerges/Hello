function varargout = project(varargin)
% PROJECT MATLAB code for project.fig
%      PROJECT, by itself, creates a new PROJECT or raises the existing
%      singleton*.
%
%      H = PROJECT returns the handle to a new PROJECT or the handle to
%      the existing singleton*.
%
%      PROJECT('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in PROJECT.M with the given input arguments.
%
%      PROJECT('Property','Value',...) creates a new PROJECT or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before project_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to project_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help project

% Last Modified by GUIDE v2.5 13-May-2017 01:16:32

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @project_OpeningFcn, ...
                   'gui_OutputFcn',  @project_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT

% --- Executes just before project is made visible.
function project_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to project (see VARARGIN)

% Choose default command line output for project
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes project wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = project_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on selection change in Methods.
function Methods_Callback(hObject, eventdata, handles)
% hObject    handle to Methods (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns Methods contents as cell array
%        contents{get(hObject,'Value')} returns selected item from Methods


% --- Executes during object creation, after setting all properties.
function Methods_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Methods (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


function input_Callback(hObject, eventdata, handles)
% hObject    handle to input (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
 x = get(handles.input,'String'); %edit1 being Tag of ur edit box
 if isempty(x)
   fprintf('Error: Enter Text first\n');
 else
   % Write code for computation you want to do 
 end
% Hints: get(hObject,'String') returns contents of input as text
%        str2double(get(hObject,'String')) returns contents of input as a double


% --- Executes during object creation, after setting all properties.
function input_CreateFcn(hObject, eventdata, handles)
% hObject    handle to input (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on key press with focus on input and none of its controls.
function input_KeyPressFcn(hObject, eventdata, handles)
% hObject    handle to input (see GCBO)
% eventdata  structure with the following fields (see UICONTROL)
%	Key: name of the key that was pressed, in lower case
%	Character: character interpretation of the key(s) that was pressed
%	Modifier: name(s) of the modifier key(s) (i.e., control, shift) pressed
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in button.
function button_Callback(hObject, eventdata, handles)
% hObject    handle to button (see GCBO)
a = get(handles.menu,'value');
global matrix;
global input1;
global input2;
global input3;
global input4;
global input5;
global ROOTSTR;
global output;
global rootsvalue;
global numberofiterations;
global approximateerror;
if (a == 1)
    set(handles.text3,'string', 'Bisection');
	b = 1;
    [upper,lower,max,precision] = get_parameters(b);
    equation = get(handles.input,'String');
    z = sprintf('%s%s','@(x) ',equation);
    func = str2func(z);
    if(lower < upper)
        [root,iter,prec,exe_time,allUpper,allLower,allroots,errors,allvalue,needed] = bis(lower,upper,precision,func,max);
        if(iter == 0 &&prec == 0 )
             set(handles.text3,'string','No root In The Given Interval');   
        else
            axes(handles.axes1);
            ezplot(func,[lower,upper]);
            input1 = num2str(upper);
            input2 = num2str(lower);
            input3 = num2str(iter);
            input4 = num2str(prec);
            input5 = num2str(exe_time);
            ROOTSTR = num2str(root);
            need = num2str(needed);
            matrix = vertcat(allvalue,errors,allroots,allLower,allUpper);
			output = 1;
            set(handles.text5,'string',allUpper);
            set(handles.text6,'string',allLower);
            set(handles.text7,'string',allroots);
            set(handles.text8,'string',errors);
            set(handles.text9,'string',allvalue);
            set(handles.text10,'string','Upper');
            set(handles.text11,'string','Lower');
            set(handles.text12,'string','all Roots');
            set(handles.text13,'string','Errors');
            set(handles.text14,'string','all Value');
            newstring = sprintf('%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n','The Root is :',ROOTSTR,'The UpperBound is : ', input1,'The LowerBound is : ', input2,'The Number of iterations : ',input3,'The precision is : ',input4,'The Execution time is : ',input5,'the number of iteration needed is : ',need);
            set(handles.text3,'string',newstring);    
        end
    else
        set(handles.text3,'string','error');
    end

elseif (a == 2)
    set(handles.text3,'string', 'False-Position');
	b = 1;
    [upper,lower,max,precision] = get_parameters(b);
    equation = get(handles.input,'String');
    z = sprintf('%s%s','@(x) ',equation);
    func = str2func(z);
    if(lower < upper)
        [root,iter,prec,exe_time,allUpper,allLower,allroots,errors,allvalue] = false_position(lower,upper,precision,func,max);
        if(iter == 0 &&prec == 0)
             set(handles.text3,'string','No root In The Given Interval');   
        else
            axes(handles.axes1);
            ezplot(func,[lower,upper]);
            input1 = num2str(upper);
            input2 = num2str(lower);
            input3 = num2str(iter);
            input4 = num2str(prec);
            input5 = num2str(exe_time);
            ROOTSTR = num2str(root);
            matrix = vertcat(allvalue,errors,allroots,allLower,allUpper);
			output = 1;
            set(handles.text5,'string',allUpper);
            set(handles.text6,'string',allLower);
            set(handles.text7,'string',allroots);
            set(handles.text8,'string',errors);
            set(handles.text9,'string',allvalue);
            set(handles.text10,'string','Upper');
            set(handles.text11,'string','Lower');
            set(handles.text12,'string','all Roots');
            set(handles.text13,'string','Errors');
            set(handles.text14,'string','all Value');
            newstring = sprintf('%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n','The Root is :',ROOTSTR,'The UpperBound is : ', input1,'The LowerBound is : ', input2,'The Number of iterations : ',input3,'The precision is : ',input4,'The Execution time is : ',input5);
            set(handles.text3,'string',newstring);
        end
    else
        set(handles.text3,'string','Error');
    end
elseif (a == 3)
    %fixed-point
    set(handles.text3,'string', 'Fixed point');
    [initial,precision,max] = get_parameters2();
    equation = get(handles.input,'String');
    func = edit_fixed(equation);
    [root,iterations,precision,execution_time,allroots,allValues,errors]  = fixed_point(initial,precision,func,max);
    if(iterations == 0 && precision == 0)
         set(handles.text3,'string','No root In The Given Interval');   
    else
        axes(handles.axes1);
        ezplot(func);
        input1 = num2str(initial);
        input2 = num2str(iterations);
        input3 = num2str(precision);
        input4 = num2str(execution_time);
        input5 = -1;
        ROOTSTR = num2str(root);
        matrix = vertcat(allValues,errors,allroots);
		output = 2;
        set(handles.text5,'string',allroots);
        set(handles.text6,'string',errors);
        set(handles.text7,'string',allValues);
        set(handles.text8,'string',' ');
        set(handles.text9,'string',' ');
        set(handles.text10,'string','all Roots');
        set(handles.text11,'string','Errors');
        set(handles.text12,'string','all Value');
        set(handles.text13,'string',' ');
        set(handles.text14,'string',' ');
        newstring = sprintf('%s%s\n%s%s\n%s%s\n%s%s\n%s%s','The Root is ',ROOTSTR,'The initial point is ', input1,'The Number of  iterations is : ',input2,'The precision is : ',input3,'The Execution time is : ',input4);
        set(handles.text3,'string',newstring);
    end

elseif (a == 4)
    set(handles.text3,'string', 'Newton-Raphson');
    [initial,precision,max] = get_parameters2();
    equation = get(handles.input,'String');
    z = sprintf('%s%s','@(x) ',equation);
    func = str2func(z);
    [root,iterations,precision,execution_time,allroots,allValues,errors]  = newton( initial,precision,func,max );
    if(iterations == 0 && precision == 0)
         set(handles.text3,'string','No root In The Given Interval');   
    else
        axes(handles.axes1);
        syms x
        fd(x)=diff(func,x);
        ezplot(fd(x));
        input1 = num2str(initial);
        input2 = num2str(iterations);
        input3 = num2str(precision);
        input4 = num2str(execution_time);
        input5 = -1;
        ROOTSTR = num2str(root);
        matrix = vertcat(allValues,errors,allroots);
        output = 2;
		set(handles.text5,'string',allroots);
        set(handles.text6,'string',errors);
        set(handles.text7,'string',allValues);
        set(handles.text8,'string',' ');
        set(handles.text9,'string',' ');
        set(handles.text10,'string','all Roots');
        set(handles.text11,'string','Errors');
        set(handles.text12,'string','all Value');
        set(handles.text13,'string',' ');
        set(handles.text14,'string',' ');
        newstring = sprintf('%s%s\n%s%s\n%s%s\n%s%s\n%s%s','The Root is ',ROOTSTR,'The initial point is ', input1,'The Number of  iterations is : ',input2,'The precision is : ',input3,'The Execution time is : ',input4);
        set(handles.text3,'string',newstring);
    end
elseif (a == 5)
    set(handles.text3,'string', 'secant');
	b = 0;
    [point1,point2,max,precision] = get_parameters(b);
    equation = get(handles.input,'String');
    z = sprintf('%s%s','@(x) ',equation);
    func = str2func(z);
	[root,iterations,precision,execution_time,allroots,allValues,errors]  = secant( point1,point2,precision,func,max );
	if(iterations == 0 &&precision == 0 )
		 set(handles.text3,'string','No root In The Given Interval');   
	else
		axes(handles.axes1);
        syms x
        fd(x)=diff(func,x);
        ezplot(fd(x));
		input1 = num2str(point1);
		input2 = num2str(point2);
		input3 = num2str(iterations);
		input4 = num2str(precision);
		input5 = num2str(execution_time);
		ROOTSTR = num2str(root);
		matrix = vertcat(allValues,errors,allroots);
		output = 3;
		set(handles.text5,'string',allroots);
		set(handles.text6,'string',errors);
		set(handles.text7,'string',allValues);
		set(handles.text8,'string',' ');
		set(handles.text9,'string',' ');
		set(handles.text10,'string','all Roots');
		set(handles.text11,'string','Errors');
		set(handles.text12,'string','all Value');
		set(handles.text13,'string',' ');
		set(handles.text14,'string',' ');
		newstring = sprintf('%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n','The Root is :',ROOTSTR,'The FirstPoint is : ', input1,'The Second Point is : ', input2,'The Number of iterations : ',input3,'The precision is : ',input4,'The Execution time is : ',input5);
		set(handles.text3,'string',newstring);    
	end
    
elseif (a == 6)
    set(handles.text3,'string', 'Bierge-Vieta');
    [initial,precision,max] = get_parameters2();
    equation = get(handles.input,'String');
    z = sprintf('%s%s','@(x) ',equation);
    func = str2func(z);
    [root,iterations,precision,execution_time,allroots,errors]  = Bierge(initial,precision,func,max);
    if(iterations == 0 && precision == 0)
         set(handles.text3,'string','No root In The Given Interval');   
    else
        axes(handles.axes1);
        syms x
        fd(x)=diff(func,x);
        ezplot(fd(x));
        input1 = num2str(initial);
        input2 = num2str(iterations);
        input3 = num2str(precision);
        input4 = num2str(execution_time);
        input5 = -1;
        ROOTSTR = num2str(root);
        matrix = vertcat(errors,allroots);
        output = 2;
		set(handles.text5,'string',allroots);
        set(handles.text6,'string',errors);
        set(handles.text7,'string',' ');
        set(handles.text8,'string',' ');
        set(handles.text9,'string',' ');
        set(handles.text10,'string','all Roots');
        set(handles.text11,'string','Errors');
        set(handles.text12,'string',' ');
        set(handles.text13,'string',' ');
        set(handles.text14,'string',' ');
        newstring = sprintf('%s%s\n%s%s\n%s%s\n%s%s\n%s%s','The Root is ',ROOTSTR,'The initial point is ', input1,'The Number of  iterations is : ',input2,'The precision is : ',input3,'The Execution time is : ',input4);
        set(handles.text3,'string',newstring);
    end
elseif (a == 7)
    set(handles.text3,'string', 'All-Methods');
	[upperbis,lowerbis,false1,false2,fixedpoint,newtonpoint,secantpoint1,secantpoint2,biergepoint,max,precision] = get_parameters3();
	equation = get(handles.input,'String');
    z = sprintf('%s%s','@(x) ',equation);
    func = str2func(z);
    func2 = edit_fixed(equation);
    output = 4;
    [rootbis,iterbis,precbis,exe_timebis,allUpperbis,allLowerbis,allrootsbis,errorsbis,allvaluebis,needed] = bis(lowerbis,upperbis,precision,func,max);
    [rootfalse,iterfalse,precfalse,exe_timefalse,allUpperfalse,allLowerfalse,allrootsfalse,errorsfalse,allvaluefalse] = false_position(false2,false1,precision,func,max);
    [rootfixed,iterationsfixed,precisionfixed,execution_timefixed,allrootsfixed,allValuesfixed,errorsfixed]  = fixed_point(fixedpoint,precision,func2,max);
    [rootnewton,iterationsnewton,precisionnewton,execution_timenewton,allrootsnewton,allValuesnewton,errornewtons]  = newton( newtonpoint,precision,func,max );
	[rootsecant,iterationssecant,precisionsecant,execution_timesecant,allrootssecant,allValuessecant,errorssecant]  = secant( secantpoint1,secantpoint2,precision,func,max );
    [rootbierge,iterationsbierge,precisionbierge,execution_timebierge,allrootsbierge,errorsbierge ]  = Bierge( biergepoint,precision,func,max );
    method = sprintf('%s\n%s\n%s\n%s\n%s\n%s','bisection', 'false', 'fixed', 'newton', 'secant','bierge');
    rootsvalue = [allrootsbis(size(allrootsbis,2)) allrootsfalse(size(allrootsfalse,2)) allrootsfixed(size(allrootsfixed,2)) allrootsnewton(size(allrootsnewton,2)) allrootssecant(size(allrootssecant,2)) allrootsbierge(size(allrootsbierge,2))];
    numberofiterations = [size(allrootsbis,2) size(allrootsfalse,2) size(allrootsfixed,2) size(allrootsnewton,2) size(allrootssecant,2) size(allrootsbierge,2)];
    approximateerror = [errorsbis(size(allrootsbis,2)) errorsfalse(size(allrootsfalse,2)) errorsfixed(size(allrootsfixed,2)) errornewtons(size(allrootsnewton,2)) errorssecant(size(allrootssecant,2)) errorsbierge(size(allrootsbierge,2))];
    axes(handles.axes1);
    plot(numberofiterations,approximateerror);
    xlabel('number of iterations');
    ylabel('approximate Error');
    set(handles.axes2,'visible','on');
    axes(handles.axes2);
    plot(numberofiterations,rootsvalue);
    xlabel('number of iterations');
    ylabel('Obtained Root');
    set(handles.text3,'string',' ');
    set(handles.text5,'string',method);
    set(handles.text6,'string',numberofiterations);
    set(handles.text7,'string',rootsvalue);
    set(handles.text8,'string',approximateerror);
    set(handles.text9,'string',' ');
    set(handles.text10,'string','method');
    set(handles.text11,'string','# of iteration');
    set(handles.text12,'string','rootvalue');
    set(handles.text13,'string','Error');
    set(handles.text14,'string',' ');
end

% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
prompt = {'Enter The File Path:'};
dlg_title = 'File';
num_lines = 1;
defaultans = {'C:\Users\karem\Desktop\Matlab Project\test_1\1.txt'};
path = inputdlg(prompt,dlg_title,num_lines,defaultans);
str = char(path);
data = file_reader(str);
method = data.textdata(1);
met = char(method);
tf = strcmp(met,'bisection');
a = 0;
if(tf == 1)
a = 1;
end
tf = strcmp(met,'falseposition');
if(tf == 1)
a = 2;
end
tf = strcmp(met,'fixedpoint');
if(tf == 1)
a = 3;
end
tf = strcmp(met,'newton');
if(tf == 1)
a = 4;
end
tf = strcmp(met,'secant');
if(tf == 1)
a = 5;
end
tf = strcmp(met,'bierge');
if(tf == 1)
a = 6;
end
tf = strcmp(met,'allmethods');
if(tf == 1)
a = 7;
end
global matrix ;
global input1;
global input2;
global input3;
global input4;
global input5;
global ROOTSTR;
global output;
global rootsvalue;
global numberofiterations;
global approximateerror;
if (a == 0)
    set(handles.text3,'string','Un Defined Method');
elseif(a == 1)
    %Bisection
    upper = data.data(1);
    lower = data.data(2);
    max = data.data(3);
    precision = data.data(4);
    equation = data.textdata(2);
    y = char(equation);
    z = sprintf('%s%s','@(x) ',y);
    func = str2func(z);
    if(lower < upper)
        [root,iter,prec,exe_time,allUpper,allLower,allroots,errors,allvalue,needed] = bis(lower,upper,precision,func,max);
        if(iter == 0 &&prec == 0 )
             set(handles.text3,'string','No root In The Given Interval');   
        else
            axes(handles.axes1);
            ezplot(func,[lower,upper]);
            input1 = num2str(upper);
            input2 = num2str(lower);
            input3 = num2str(iter);
            input4 = num2str(prec);
            input5 = num2str(exe_time);
            ROOTSTR = num2str(root);
            need = num2str(needed);
            matrix = vertcat(allvalue,errors,allroots,allLower,allUpper);
            output = 1;
			set(handles.text5,'string',allUpper);
            set(handles.text6,'string',allLower);
            set(handles.text7,'string',allroots);
            set(handles.text8,'string',errors);
            set(handles.text9,'string',allvalue);
            set(handles.text10,'string','Upper');
            set(handles.text11,'string','Lower');
            set(handles.text12,'string','all Roots');
            set(handles.text13,'string','Errors');
            set(handles.text14,'string','all Value');
            newstring = sprintf('%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n','The Root is :',ROOTSTR,'The UpperBound is : ', input1,'The LowerBound is : ', input2,'The Number of iterations : ',input3,'The precision is : ',input4,'The Execution time is : ',input5,'the number of iteration needed is : ',need);
            set(handles.text3,'string',newstring);    
        end
    else
        set(handles.text3,'string','error');
    end

elseif (a==2)
    %False-Position
    upper = data.data(1);
    lower = data.data(2);
    max = data.data(3);
    precision = data.data(4);
    equation = data.textdata(2);
    y = char(equation);
    z = sprintf('%s%s','@(x) ',y);
    func = str2func(z);
    if(lower < upper)
        [root,iter,prec,exe_time,allUpper,allLower,allroots,errors,allvalue] = false_position(lower,upper,precision,func,max);
        if(iter == 0 &&prec == 0)
             set(handles.text3,'string','No root In The Given Interval');   
        else
            axes(handles.axes1);
            ezplot(func,[lower,upper]);
            input1 = num2str(upper);
            input2 = num2str(lower);
            input3 = num2str(iter);
            input4 = num2str(prec);
            input5 = num2str(exe_time);
            ROOTSTR = num2str(root);
            matrix = vertcat(allvalue,errors,allroots,allLower,allUpper);
            output = 1;
			set(handles.text5,'string',allUpper);
            set(handles.text6,'string',allLower);
            set(handles.text7,'string',allroots);
            set(handles.text8,'string',errors);
            set(handles.text9,'string',allvalue);
            set(handles.text10,'string','Upper');
            set(handles.text11,'string','Lower');
            set(handles.text12,'string','all Roots');
            set(handles.text13,'string','Errors');
            set(handles.text14,'string','all Value');
            newstring = sprintf('%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n','The Root is :',ROOTSTR,'The UpperBound is : ', input1,'The LowerBound is : ', input2,'The Number of iterations : ',input3,'The precision is : ',input4,'The Execution time is : ',input5);
            set(handles.text3,'string',newstring);
        end
    else
        set(handles.text3,'string','Error');
    end

elseif (a==3)
	%FIXED_POINT
    initial = data.data(1);
    max = data.data(2);
    precision = data.data(3);
    equation = data.textdata(2);
    func = edit_fixed(equation);
	[root,iterations,precision,execution_time,allroots,allValues,errors]  = fixed_point(initial,precision,func,max);
    if(iterations == 0 && precision == 0)
         set(handles.text3,'string','No root In The Given Interval');   
    else
        axes(handles.axes1);
        ezplot(func);
        input1 = num2str(initial);
        input2 = num2str(iterations);
        input3 = num2str(precision);
        input4 = num2str(execution_time);
        input5 = -1;
        ROOTSTR = num2str(root);
        matrix = vertcat(allValues,errors,allroots);
        output = 2;
		set(handles.text5,'string',allroots);
        set(handles.text6,'string',errors);
        set(handles.text7,'string',allValues);
        set(handles.text8,'string',' ');
        set(handles.text9,'string',' ');
        set(handles.text10,'string','all Roots');
        set(handles.text11,'string','Errors');
        set(handles.text12,'string','all Value');
        set(handles.text13,'string',' ');
        set(handles.text14,'string',' ');
        newstring = sprintf('%s%s\n%s%s\n%s%s\n%s%s\n%s%s','The Root is ',ROOTSTR,'The initial point is ', input1,'The Number of  iterations is : ',input2,'The precision is : ',input3,'The Execution time is : ',input4);
        set(handles.text3,'string',newstring);
    end

elseif (a==4)
%NewtonRaphson
    initial = data.data(1);
    max = data.data(2);
    precision = data.data(3);
    equation = data.textdata(2);
    y = char(equation);
    z = sprintf('%s%s','@(x) ',y);
    func = str2func(z);
    [root,iterations,precision,execution_time,allroots,allValues,errors]  = newton( initial,precision,func,max );
    if(iterations == 0 && precision == 0)
         set(handles.text3,'string','No root In The Given Interval');   
    else
        axes(handles.axes1);
        syms x
        fd(x)=diff(func,x);
        ezplot(fd(x));
        input1 = num2str(initial);
        input2 = num2str(iterations);
        input3 = num2str(precision);
        input4 = num2str(execution_time);
        input5 = -1;
        ROOTSTR = num2str(root);
        matrix = vertcat(allValues,errors,allroots);
        output = 2;
		set(handles.text5,'string',allroots);
        set(handles.text6,'string',errors);
        set(handles.text7,'string',allValues);
        set(handles.text8,'string',' ');
        set(handles.text9,'string',' ');
        set(handles.text10,'string','all Roots');
        set(handles.text11,'string','Errors');
        set(handles.text12,'string','all Value');
        set(handles.text13,'string',' ');
        set(handles.text14,'string',' ');
        newstring = sprintf('%s%s\n%s%s\n%s%s\n%s%s\n%s%s','The Root is ',ROOTSTR,'The initial point is ', input1,'The Number of  iterations is : ',input2,'The precision is : ',input3,'The Execution time is : ',input4);
        set(handles.text3,'string',newstring);
    end
elseif (a==5)
    %Secant    
    point1 = data.data(1);
    point2 = data.data(2);
    max = data.data(3);
    precision = data.data(4);
    equation = data.textdata(2);
    y = char(equation);
    z = sprintf('%s%s','@(x) ',y);
    func = str2func(z);
	[root,iterations,precision,execution_time,allroots,allValues,errors]  = secant( point1,point2,precision,func,max );
	if(iterations == 0 &&precision == 0 )
		 set(handles.text3,'string','No root In The Given Interval');   
	else
		axes(handles.axes1);
        syms x
        fd(x)=diff(func,x);
        ezplot(fd(x));
		input1 = num2str(point1);
		input2 = num2str(point2);
		input3 = num2str(iterations);
		input4 = num2str(precision);
		input5 = num2str(execution_time);
		ROOTSTR = num2str(root);
		matrix = vertcat(allValues,errors,allroots);
		output = 3;
		set(handles.text5,'string',allroots);
		set(handles.text6,'string',errors);
		set(handles.text7,'string',allValues);
		set(handles.text8,'string',' ');
		set(handles.text9,'string',' ');
		set(handles.text10,'string','all Roots');
		set(handles.text11,'string','Errors');
		set(handles.text12,'string','all Value');
		set(handles.text13,'string',' ');
		set(handles.text14,'string',' ');
		newstring = sprintf('%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n','The Root is :',ROOTSTR,'The FirstPoint is : ', input1,'The second point is : ', input2,'The Number of iterations : ',input3,'The precision is : ',input4,'The Execution time is : ',input5);
		set(handles.text3,'string',newstring);    
	end
elseif (a==6)
    %Bierge-Vieta
    initial = data.data(1);
    max = data.data(2);
    precision = data.data(3);
    equation = data.textdata(2);
    y = char(equation);
    z = sprintf('%s%s','@(x) ',y);
    func = str2func(z);
    [ root,iterations,precision,execution_time,allroots,errors ]  = Bierge( initial,precision,func,max );
    if(iterations == 0 && precision == 0)
         set(handles.text3,'string','No root In The Given Interval');   
    else
        axes(handles.axes1);
        syms x
        fd(x)=diff(func,x);
        ezplot(fd(x));
        input1 = num2str(initial);
        input2 = num2str(iterations);
        input3 = num2str(precision);
        input4 = num2str(execution_time);
        input5 = -1;
        ROOTSTR = num2str(root);
        matrix = vertcat(errors,allroots);
        output = 2;
		set(handles.text5,'string',allroots);
        set(handles.text6,'string',errors);
        set(handles.text7,'string',' ');
        set(handles.text8,'string',' ');
        set(handles.text9,'string',' ');
        set(handles.text10,'string','all Roots');
        set(handles.text11,'string','Errors');
        set(handles.text12,'string',' ');
        set(handles.text13,'string',' ');
        set(handles.text14,'string',' ');
        newstring = sprintf('%s%s\n%s%s\n%s%s\n%s%s\n%s%s','The Root is ',ROOTSTR,'The initial point is ', input1,'The Number of  iterations is : ',input2,'The precision is : ',input3,'The Execution time is : ',input4);
        set(handles.text3,'string',newstring);
    end
elseif (a==7)
    %all-methods
    upperbis = data.data(1);
    lowerbis = data.data(2);
	upperfalse = data.data(3);
    lowerfalse = data.data(4);
    fixedpoint = data.data(5);
    newtonpoint = data.data(6);
	secantpoint1 = data.data(7);
    secantpoint2 = data.data(8);
    biergepoint = data.data(9);
    max = data.data(10);
    precision = data.data(11);
    equation = data.textdata(2);
    y = char(equation);
    z = sprintf('%s%s','@(x) ',y);
    func = str2func(z);
    func2 = edit_fixed(equation);
    output = 4;
    [rootbis,iterbis,precbis,exe_timebis,allUpperbis,allLowerbis,allrootsbis,errorsbis,allvaluebis,needed] = bis(lowerbis,upperbis,precision,func,max);
    [rootfalse,iterfalse,precfalse,exe_timefalse,allUpperfalse,allLowerfalse,allrootsfalse,errorsfalse,allvaluefalse] = false_position(lowerfalse,upperfalse,precision,func,max);
    [rootfixed,iterationsfixed,precisionfixed,execution_timefixed,allrootsfixed,allValuesfixed,errorsfixed]  = fixed_point(fixedpoint,precision,func2,max);
    [rootnewton,iterationsnewton,precisionnewton,execution_timenewton,allrootsnewton,allValuesnewton,errornewtons]  = newton( newtonpoint,precision,func,max );
	[rootsecant,iterationssecant,precisionsecant,execution_timesecant,allrootssecant,allValuessecant,errorssecant]  = secant( secantpoint1,secantpoint2,precision,func,max );
    [rootbierge,iterationsbierge,precisionbierge,execution_timebierge,allrootsbierge,errorsbierge ]  = Bierge( biergepoint,precision,func,max );
    method = sprintf('%s\n%s\n%s\n%s\n%s\n%s','bisection', 'false', 'fixed', 'newton', 'secant','bierge');
    rootsvalue = [allrootsbis(size(allrootsbis,2)) allrootsfalse(size(allrootsfalse,2)) allrootsfixed(size(allrootsfixed,2)) allrootsnewton(size(allrootsnewton,2)) allrootssecant(size(allrootssecant,2)) allrootsbierge(size(allrootsbierge,2))];
    numberofiterations = [size(allrootsbis,2) size(allrootsfalse,2) size(allrootsfixed,2) size(allrootsnewton,2) size(allrootssecant,2) size(allrootsbierge,2)];
    approximateerror = [errorsbis(size(allrootsbis,2)) errorsfalse(size(allrootsfalse,2)) errorsfixed(size(allrootsfixed,2)) errornewtons(size(allrootsnewton,2)) errorssecant(size(allrootssecant,2)) errorsbierge(size(allrootsbierge,2))];
    axes(handles.axes1);
    plot(numberofiterations,approximateerror);
    xlabel('number of iterations');
    ylabel('approximate Error');
    set(handles.axes2,'visible','on');
    axes(handles.axes2);
    plot(numberofiterations,rootsvalue);
    xlabel('number of iterations');
    ylabel('Obtained Root');
    set(handles.text3,'string',' ');
    set(handles.text5,'string',method);
    set(handles.text6,'string',numberofiterations);
    set(handles.text7,'string',rootsvalue);
    set(handles.text8,'string',approximateerror);
    set(handles.text9,'string',' ');
    set(handles.text10,'string','method');
    set(handles.text11,'string','# of iteration');
    set(handles.text12,'string','rootvalue');
    set(handles.text13,'string','Error');
    set(handles.text14,'string',' ');
end

% --- Executes on button press in pushbutton5.
function pushbutton5_Callback(hObject, eventdata, handles)
prompt = {'Enter The File Path:'};
dlg_title = 'File';
num_lines = 1;
defaultans = {'C:\Users\karem\Desktop\Matlab Project\z_1\1.txt'};
path = inputdlg(prompt,dlg_title,num_lines,defaultans);
directory = char(path);
global matrix ;
matrix = rot90(matrix,3);
file_writer(directory);



% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
        

% --- Executes on button press in bisection.
function bisection_Callback(hObject, eventdata, handles)
% hObject    handle to bisection (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
%prompt = {'x','y'};
%dlg_title = 'input';
%num_lines =1;
%def = {'',''};
%answer = inputdlg{prompt,dlg_title,num_lines,def};
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on selection change in menu.
function menu_Callback(hObject, eventdata, handles)
% hObject    handle to menu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns menu contents as cell array
%        contents{get(hObject,'Value')} returns selected item from menu


% --- Executes during object creation, after setting all properties.
function menu_CreateFcn(hObject, eventdata, handles)
% hObject    handle to menu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes during object creation, after setting all properties.
function axes1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to axes1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
% Hint: place code in OpeningFcn to populate axes1



% --- Executes during object creation, after setting all properties.
function pushbutton3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% --- Executes on button press in pushbutton3.
