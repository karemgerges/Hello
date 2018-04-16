function varargout = PartTwo(varargin)
% PARTTWO MATLAB code for PartTwo.fig
%      PARTTWO, by itself, creates a new PARTTWO or raises the existing
%      singleton*.
%
%      H = PARTTWO returns the handle to a new PARTTWO or the handle to
%      the existing singleton*.
%
%      PARTTWO('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in PARTTWO.M with the given input arguments.
%
%      PARTTWO('Property','Value',...) creates a new PARTTWO or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before PartTwo_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to PartTwo_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help PartTwo

% Last Modified by GUIDE v2.5 17-May-2017 23:38:59

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @PartTwo_OpeningFcn, ...
                   'gui_OutputFcn',  @PartTwo_OutputFcn, ...
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

% --- Executes just before PartTwo is made visible.
function PartTwo_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to PartTwo (see VARARGIN)

% Choose default command line output for PartTwo
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes PartTwo wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = PartTwo_OutputFcn(hObject, eventdata, handles) 
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
global symbols;
global solution;
global output;
global absErr;
global precision;
global iterations;
global exeTime;
global solutiongauss;
global solutionlu;
global solutionjordan;
if(a==1||a==2||a==3)
    %make labels not needed not visible
    set(handles.text8,'visible','off');
    set(handles.text9,'visible','off');
    set(handles.text10,'visible','off');
    set(handles.text11,'visible','off');
    set(handles.text14,'visible','off');
    set(handles.text17,'visible','off');
    set(handles.text18,'visible','off');
    set(handles.text19,'visible','off');
    set(handles.text16,'visible','off');
    set(handles.text20,'visible','off');
    set(handles.text21,'visible','off');
    set(handles.text22,'visible','off');
    set(handles.text13,'string','value');
elseif(a==4||a==5)
    set(handles.text8,'visible','on');
    set(handles.text9,'visible','on');
    set(handles.text14,'visible','on');
end
if(a==5)
     set(handles.text18,'visible','on');
    set(handles.text22,'visible','on');
    set(handles.text16,'visible','on');
end
if (a == 1)
%Gauss-Elimination
    NumOfEquations = get(handles.input,'String');
    symbolstring = get(handles.input2,'String');
    [EquationsNumber,equ,symstr] = get_parameters(NumOfEquations,symbolstring);
    symbols = strsplit(symstr);
    solution = GaussElim(equ,symstr,EquationsNumber);  
    set(handles.text3,'string',symbols);
    set(handles.text5,'string',solution);
    set(handles.text6,'visible','on');
elseif (a == 2)
    %LU Decomoposition
    NumOfEquations = get(handles.input,'String');
    symbolstring = get(handles.input2,'String');
    [EquationsNumber,equ,symstr] = get_parameters(NumOfEquations,symbolstring);
    symbols = strsplit(symstr);
    solution = LUDecomp(equ,symstr,EquationsNumber);  
    set(handles.text3,'string',symbols);
    set(handles.text5,'string',solution);
    set(handles.text6,'visible','on');
elseif (a == 3)
    %gauss-jordan
    NumOfEquations = get(handles.input,'String');
    symbolstring = get(handles.input2,'String');
    [EquationsNumber,equ,symstr] = get_parameters(NumOfEquations,symbolstring);
    symbols = strsplit(symstr);
    solution = GaussJordanElim(equ,symstr,EquationsNumber);  
    set(handles.text3,'string',symbols);
    set(handles.text5,'string',solution);
    set(handles.text6,'visible','on');
elseif (a == 4)
    %gauss-sidel
    output = 2;
    NumOfEquations = get(handles.input,'String');
    symbolstring = get(handles.input2,'String');
    [EquationsNumber,equ,symstr,precision,max] = get_Seidel_parameters2(NumOfEquations,symbolstring);
    [solution,iterNum,absErr,precision,exeTime,iterations] = GaussSeidel(equ,symstr, EquationsNumber,precision,max);  
    symbols = strsplit(symstr);
    set(handles.text3,'string',symbols);
    set(handles.text5,'string',solution);
    set(handles.text6,'visible','on');
    set(handles.text17,'visible','on');
    set(handles.text10,'visible','on');
    set(handles.text11,'visible','on');
    newstring = sprintf('%s%s\n%s%s','Number of iter : ',num2str(iterNum), 'The Exe Time is ',num2str(exeTime));
    set(handles.text7,'string',newstring);
    set(handles.text8,'string',num2str(iterations));
    set(handles.text14,'string',num2str(precision));
    set(handles.text9,'string',num2str(absErr));
elseif(a == 5)
    %all-methods
    output = 3;
    NumOfEquations = get(handles.input,'String');
    symbolstring = get(handles.input2,'String');
    [EquationsNumber,equ,symstr,precision,max] = get_Seidel_parameters2(NumOfEquations,symbolstring);
    [solution,iterNum,absErr,precision,exeTime,iterations] = GaussSeidel(equ,symstr, EquationsNumber,precesion,max);
    solutiongauss = GaussElim(equ,symstr,EquationsNumber);
    solutionlu = LUDecomp(equ,symstr,EquationsNumber);
    solutionjordan = GaussJordanElim(equ,symstr,EquationsNumber);
    symbols = strsplit(symstr);
    set(handles.text3,'string',symbols);
    set(handles.text5,'string',solution);
    set(handles.text6,'visible','on');
    set(handles.text17,'visible','on');
    set(handles.text10,'visible','on');
    set(handles.text11,'visible','on');
    set(handles.text19,'visible','on');
    set(handles.text20,'visible','on');
    set(handles.text21,'visible','on');
    set(handles.text16,'string',solutiongauss);
    set(handles.text22,'string',solutionlu);
    set(handles.text18,'string',solutionjordan);
    set(handles.text13,'string','seidel');
    newstring = sprintf('%s%s\n%s%s','Number of iter : ',num2str(iterNum), 'The Exe Time is ',num2str(exeTime));
    set(handles.text7,'string',newstring);
    set(handles.text8,'string',num2str(iterations));
    set(handles.text14,'string',num2str(precision));
    set(handles.text9,'string',num2str(absErr));
end
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
prompt = {'Enter The File Path:'};
dlg_title = 'File';
num_lines = 1;
defaultans = {'C:\Users\karem\Desktop\Matlab Project\test_2\1.txt'};
path = inputdlg(prompt,dlg_title,num_lines,defaultans);
str = char(path);
data = file_reader(str);
method = data.textdata(1);
met = char(method);
tf = strcmp(met,'gausselimination');
a = 0;
if(tf == 1)
a = 1;
end
tf = strcmp(met,'ludecomposition');
if(tf == 1)
a = 2;
end
tf = strcmp(met,'gaussjordan');
if(tf == 1)
a = 3;
end
tf = strcmp(met,'gausssiedel');
if(tf == 1)
a = 4;
end
tf = strcmp(met,'allmethods');
if(tf == 1)
a = 5;
end
global symbols;
global solution;
global output;
global absErr;
global precision;
global iterations;
global exeTime;
global solutiongauss;
global solutionlu;
global solutionjordan;
if(a==1||a==2||a==3)
    %make labels not needed not visible
    set(handles.text8,'visible','off');
    set(handles.text9,'visible','off');
    set(handles.text10,'visible','off');
    set(handles.text11,'visible','off');
    set(handles.text14,'visible','off');
    set(handles.text17,'visible','off');
    set(handles.text18,'visible','off');
    set(handles.text19,'visible','off');
    set(handles.text16,'visible','off');
    set(handles.text20,'visible','off');
    set(handles.text21,'visible','off');
    set(handles.text22,'visible','off');
    set(handles.text13,'string','value');
elseif(a==4||a==5)
    set(handles.text8,'visible','on');
    set(handles.text9,'visible','on');
    set(handles.text14,'visible','on');
end
if(a==5)
     set(handles.text18,'visible','on');
    set(handles.text22,'visible','on');
    set(handles.text16,'visible','on');
end

if (a == 0)
    set(handles.text3,'string','Un Defined Method');
elseif(a == 1)
    [EquationsNumber,equ,symstr] = get_File_Parameters(data);
    symbols = strsplit(symstr);
    solution = GaussElim(equ,symstr,EquationsNumber);  
    set(handles.text3,'string',symbols);
    set(handles.text5,'string',solution);
    set(handles.text6,'visible','on');
elseif(a == 2)
    [EquationsNumber,equ,symstr] = get_File_Parameters(data);
    symbols = strsplit(symstr);
    solution = LUDecomp(equ,symstr,EquationsNumber);  
    set(handles.text3,'string',symbols);
    set(handles.text5,'string',solution);
    set(handles.text6,'visible','on');
elseif(a == 3)
    [EquationsNumber,equ,symstr] = get_File_Parameters(data);
    symbols = strsplit(symstr);
    solution = GaussJordanElim(equ,symstr,EquationsNumber);  
    set(handles.text3,'string',symbols);
    set(handles.text5,'string',solution);
    set(handles.text6,'visible','on');
elseif(a == 4)
    %gauss-seidel
    output = 2 ;
    [EquationsNumber,equ,symstr,precesion,max] = get_Seidel_Parameters(data);
    [solution,iterNum,absErr,precision,exeTime,iterations] = GaussSeidel(equ,symstr, EquationsNumber,precesion,max);
    symbols = strsplit(symstr);
    set(handles.text3,'string',symbols);
    set(handles.text5,'string',solution);
     set(handles.text6,'visible','on');
    set(handles.text17,'visible','on');
    set(handles.text10,'visible','on');
    set(handles.text11,'visible','on');
    newstring = sprintf('%s%s\n%s%s','Number of iter : ',num2str(iterNum), 'The Exe Time is ',num2str(exeTime));
    set(handles.text7,'string',newstring);
    set(handles.text8,'string',num2str(iterations));
    set(handles.text14,'string',num2str(precision));
    set(handles.text9,'string',num2str(absErr));
elseif(a == 5)
    %all methods
    output = 3 ;
    [EquationsNumber,equ,symstr,precesion,max] = get_Seidel_Parameters(data);
    [solution,iterNum,absErr,precision,exeTime,iterations] = GaussSeidel(equ,symstr, EquationsNumber,precesion,max);
    solutiongauss = GaussElim(equ,symstr,EquationsNumber);
    solutionlu = LUDecomp(equ,symstr,EquationsNumber);
    solutionjordan = GaussElim(equ,symstr,EquationsNumber);
    symbols = strsplit(symstr);
    set(handles.text3,'string',symbols);
    set(handles.text5,'string',solution);
    set(handles.text6,'visible','on');
    set(handles.text17,'visible','on');
    set(handles.text10,'visible','on');
    set(handles.text11,'visible','on');
    set(handles.text19,'visible','on');
    set(handles.text20,'visible','on');
    set(handles.text21,'visible','on');
    set(handles.text16,'string',solutiongauss);
    set(handles.text22,'string',solutionlu);
    set(handles.text18,'string',solutionjordan);
    set(handles.text13,'string','seidel');
    newstring = sprintf('%s%s\n%s%s','Number of iter : ',num2str(iterNum), 'The Exe Time is ',num2str(exeTime));
    set(handles.text7,'string',newstring);
    set(handles.text8,'string',num2str(iterations));
    set(handles.text14,'string',num2str(precision));
    set(handles.text9,'string',num2str(absErr));
end

        
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



function input2_Callback(hObject, eventdata, handles)
% hObject    handle to input2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of input2 as text
%        str2double(get(hObject,'String')) returns contents of input2 as a double


% --- Executes during object creation, after setting all properties.
function input2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to input2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
   
% --- Executes on button press in pushbutton4.
function pushbutton4_Callback(hObject, eventdata, handles)
prompt = {'Enter The File Path:'};
dlg_title = 'File';
num_lines = 1;
defaultans = {'C:\Users\karem\Desktop\Matlab Project\z_2\1.txt'};
path = inputdlg(prompt,dlg_title,num_lines,defaultans);
directory = char(path);
file_writer(directory);
