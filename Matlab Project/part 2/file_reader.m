function [data] = file_reader(str)
delimiterIn = '';
data = importdata(str,delimiterIn);
