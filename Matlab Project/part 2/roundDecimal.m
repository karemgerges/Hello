function [ y ] = roundDecimal( x, d )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here


D = 10.^(d-ceil(log10(x)));

y = round(x.*D)/D;
end

