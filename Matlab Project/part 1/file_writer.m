function file_writer(directory)
global input1;
global input2;
global input3;
global input4;
global input5;
global ROOTSTR;
global output;
global matrix;
global rootsvalue;
global numberofiterations;
global approximateerror;
if(output == 2||output == 3)
    newstring = sprintf('%s\t\t%s\t\t%s\n','  all Roots','Errors','all Value');
    fileID = fopen(directory,'w');
    fprintf(fileID,newstring); 
elseif(output == 1)
    newstring = sprintf('%s\t\t%s\t%s\t%s\t\t%s\n','   upper','lower','   all Roots','Errors','all Value');
    fileID = fopen(directory,'w');
    fprintf(fileID,newstring);
elseif(output == 4)
	method = '--bisection-- falseposition -fixed-point- newtonraphson. ---secant---- bierge--vieta';
	meth = strsplit(method);
	numberOfSolution = size(rootsvalue,2);
    fileID = fopen(directory,'w');
	newstring = sprintf('%s\t%s\t%s\t%s\n','---Method--','# of iter','root','Error');
	fprintf(fileID,newstring);
    n = 0;
    while(n < numberOfSolution)
    fprintf(fileID,char(meth(n+1)));
    fprintf(fileID,'\t');
    fprintf(fileID,num2str(numberofiterations(n+1)));
    fprintf(fileID,'\t\t');
    fprintf(fileID,num2str(rootsvalue(n+1)));
	fprintf(fileID,'\t\t');
	fprintf(fileID,num2str(approximateerror(n+1)));
    fprintf(fileID,'\n');
    n = n + 1;
    end
end    
if(output ~= 4)
	dlmwrite(directory,matrix,'-append','delimiter','\t','precision','%10.5f');
end
if(output == 2)
    fileID = fopen(directory,'a');
    newstring = sprintf('%s%s\n%s%s\n%s%s\n%s%s\n%s%s','The Root is ',ROOTSTR,'The initial point is ', input1,'The Number of  iterations is : ',input2,'The precision is : ',input3,'The Execution time is : ',input4);
    fprintf(fileID,newstring);
elseif(output == 1)
    fileID = fopen(directory,'a');
    newstring = sprintf('%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n','The Root is :',ROOTSTR,'The UpperBound is : ', input1,'The LowerBound is : ', input2,'The Number of iterations : ',input3,'The precision is : ',input4,'The Execution time is : ',input5);
    fprintf(fileID,newstring);
elseif(output == 3)
    fileID = fopen(directory,'a');
    newstring = sprintf('%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n','The Root is :',ROOTSTR,'The FirstPoint is : ', input1,'The second point is : ', input2,'The Number of iterations : ',input3,'The precision is : ',input4,'The Execution time is : ',input5);
    fprintf(fileID,newstring);
end 
