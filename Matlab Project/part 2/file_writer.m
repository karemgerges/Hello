function file_writer(directory)
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
    if(output == 2 || output == 3)
        numberOfSolution = size(solution,1);
        fileID = fopen(directory,'w');
        n = 0;
        while(n < numberOfSolution)
        fprintf(fileID,char(symbols(n+1)));
        fprintf(fileID,'\t');
        fprintf(fileID,num2str(solution(n+1)));
        fprintf(fileID,'\t');
        fprintf(fileID,num2str(precision(n+1)));
        fprintf(fileID,'\n');
        n = n + 1;
        end
        fprintf(fileID,'the number of iterations is : ');
        fprintf(fileID,num2str(size(iterations,1)));
        fprintf(fileID,'\n');
        fprintf(fileID,'the execusion time is : ');
        fprintf(fileID,num2str(exeTime));
        fprintf(fileID,'\n');
        fprintf(fileID,'\t\t iterations');
        fprintf(fileID,'\n');
        dlmwrite(directory,iterations,'-append','delimiter','\t','precision','%10.5f');
        fileID = fopen(directory,'a');
        fprintf(fileID,'\t\t Absolute Error');
        fprintf(fileID,'\n');
        dlmwrite(directory,absErr,'-append','delimiter','\t','precision','%10.5f');
        if(output==3)
            fileID = fopen(directory,'a');
            n = 0;
            fprintf(fileID,'\t \t Gauss Elimination \n');
            while(n < numberOfSolution)
                fprintf(fileID,char(symbols(n+1)));
                fprintf(fileID,'\t');
                fprintf(fileID,num2str(solutiongauss(n+1)));
                fprintf(fileID,'\n');
                n = n + 1;
            end
            n = 0;
            fprintf(fileID,'\t \t Lu Decomposition \n ');
            while(n < numberOfSolution)
                fprintf(fileID,char(symbols(n+1)));
                fprintf(fileID,'\t');
                fprintf(fileID,num2str(solutionlu(n+1)));
                fprintf(fileID,'\n');
                n = n + 1;
            end
            n = 0;
            fprintf(fileID,'\t \t Gauss Jordan \n ');
            while(n < numberOfSolution)
                fprintf(fileID,char(symbols(n+1)));
                fprintf(fileID,'\t');
                fprintf(fileID,num2str(solutionjordan(n+1)));
                fprintf(fileID,'\n');
                n = n + 1;
            end
        end
    else
        numberOfSolution = size(solution,1);
        if(numberOfSolution == 1)
            numberOfSolution = size(solution,2);
        end
        fileID = fopen(directory,'w');
        n = 0;
        while(n < numberOfSolution)
        fprintf(fileID,char(symbols(n+1)));
        fprintf(fileID,'\t');
        fprintf(fileID,num2str(solution(n+1)));
        fprintf(fileID,'\n');
        n = n + 1;
        end
    end
 