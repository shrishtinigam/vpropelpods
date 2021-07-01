/* 17 - 3 - 2021
Find the Week Day
Given the week day of nth day of a month, write a C program to find mth day of the month. 
For example, if it is given that 16th of the month is Wednesday then 25th of the month is Friday 
and if it is given that 29th of the month is Tuesday then 2nd of the month is Wednesday. 
Weekday number is given as input for ‘n’ that 0 indicates Sunday, 1 indicates Monday and so on.

Input Format
First line contains the value of n
Next line contains the week day number of ‘n’
Next line contains the value of ‘m’

Output Format
Print the week day of m. First letter of weekday should be in upper case*/
#include<stdio.h>
#include<string.h>
char week[8][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int main()
{
    int n, m, weekday, carry, x;
    scanf("%d%d%d", &n, &weekday, &m);
    while(n > 7)
        n = n - 7;
    while(m > 7)
        m = m - 7;
    
    while(n != m)
    {
        n++;
        if(n >= 8)
            n = n - 7;
        weekday++;
        if(weekday >= 8)
            weekday = weekday - 7;
    }
    printf("%s", week[weekday]);
}