/*28 - 3- 2021
Palindrome and Repdigit
Given a range of integers, write a C/C++ program to identify numbers which are not palindromes and whose cube root is a repdigit. A repdigit is a number which is composed of same digit. For example, tthe numbers between 10 and 99999 (inclusive) that are satisfying the conditions are 10648, 35937 and 85184 and their corressponding cube roots which are repdigits are 22, 33 and 44.

Boundary conditions
Upper bound of range of values can be 10^13
Input Format
First line contains the lower bound value of the range, l
Next line contains the upper bound value of the range, u
Output Format
In one line print the number ‘n’ which is not a palidrome and its cube root which is a repdigit separated by a tab
Print in ascending order of n

Note:
Cuberoot of a number can be found using cbrt function in math.h
*/
#include <iostream>
#include <math.h>
using namespace std;
int palindromeChecker(long long int x);
int repDigitGen(long long a);
int repDigitChecker(long long n);
int main()
{
    long long l, u;
    cin >> l >> u;
    long  cbrtu = (long)cbrt(u);
    long long l2 = 20;
    while((l2*l2*l2) < u)
    {
        l2 = repDigitGen(l2);
        if(palindromeChecker(l2*l2*l2)==0 && (l2*l2*l2) < u)
            cout << l2*l2*l2 << "\t" << l2 << "\n";
        l2 = l2 + 1;
    }
}
int palindromeChecker(long long int num)
{
    int rev = 0;
    int digit = 0;
    int n = num;
    do
    {
        digit = num % 10;
        rev = (rev * 10) + digit;
        num = num / 10;
    }while (num != 0);
    if(n == rev)
        return 1;
    return 0;
}
int repDigitChecker(long long num)
{
    int prev = -1;
    while (num) {
        int digit = num % 10;
        num /= 10;
        if (prev != -1 && digit != prev)
            return 0;
        prev = digit;
    }
    return 1;
}

int repDigitGen(long long a)
{
    while(repDigitChecker(a) != 1)
        a = a + 1;
    return a;
}
/*
code in python by ayush gupta

l=int(input())
u=int(input())
x=11
while len(str(x))!=len(str(u))+1:
    for i in range(1,10):
        z=x*i
        a=z**3
        k=str(a)[::-1]
        if l<=a and a<=u:
            if str(a)!=k:
                print(a,end='\t')
                print(z)
    x=int(str(x) + '1')
    
*/