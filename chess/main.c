#include <stdio.h>
#include <stdlib.h>
int main()
{
    double   INITIAL_BALANCE = 10000;
    double   rate = 5;
    int      year = 0;
    double balance = INITIAL_BALANCE ;
    double targetBalance = 2 * INITIAL_BALANCE;
    while (balance < targetBalance)
        {
        year++;
        double interest = balance * rate / 100;
        balance = balance + interest;
    }
    printf("The investment doubled after %d  years\n",  year);
    return 0;
}
