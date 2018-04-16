function [func] = edit_fixed(equation)
    y = char(equation);
	pattern = 'x';
	arr= strfind(y,pattern);
 	n = 1;
	coffecinet = 1;
	coff = {''};
	while(n <= size(arr,2))
		position = arr(n);
		if(y(position+1) ~= '^' && y(position+1) ~= ')')
				if(y(position - 1) == '*')
					b = 2 ;
					while(y(position-b)~='+'||y(position-b)~='-')
					b=b+1;
						if(position-b==0)
							b=b-1;
							break;
						end
					end
					t=b-1;
					while(t>=2)
						coff = strcat(coff,y(position - t ));
						%disp(coff);
						t=t-1;
					end
					coffecinet = str2double(coff);
					disp(coffecinet);
					if(y(position-b)=='+')
						coffecinet = coffecinet * -1 ;
					end
				end
				if(y(position - 1) ~= '*')
					coffecinet = 1;
					if(y(position-1)=='+')
						coffecinet = coffecinet * -1 ;
					end
				end
		end
		n=n+1;
	end
    z = sprintf('%s%s','@(x) ',y);
    func = str2func(z);
    cof = num2str(coffecinet);
    fun = strcat(cof,'*x');
	h = sprintf('%s%s','@(x) ',fun);
	func2 = str2func(h);
  	g1=sym(func);
	g2=sym(func2);
	g3 = (g1 + g2)/coffecinet;
    gh = char(g3);
	cat = strcat('@(x) ',gh);
	func=str2func(cat);