/* 7 - 4 -2021
Last M Digit Generate-able
A number ‘f’ is said to be generatable if it can be generated in a Fibonacci-like 
sequence from its digits. Initially the sequence contains the digits in it from left 
to right and the next number in the sequence is generated by summing up the last ‘d’ 
numbers in the sequence where ‘d’ is the number of digits in ‘f’. For example, the number 
197 can be got in a sequence 1, 9, 7, 17, 33, 57, 107, 197 by adding last three numbers.

A number ‘n’ is said to be last ‘m’ digit generate-able if the number that can be formed 
with last ‘m’ digits of it can be generated from them. For example 23197 is last 3 digit 
generate-able, 371104 is last 4 digit generate-able, 17844121607 is last 8 digit generate-able.

Input Format

First line contains the number n

Next line contains the number of last digits m

Output Format

Print either Generated or Cannot be generated
*/

// FOR N = INT

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
bool Fibonacci(int arr[], int n, int m);
int main()
{
    int n,m;
    cin >> n >> m;
    int x = pow(10,m);
    x = n%x; // x = last m digits of n
    int x1 = x;
    int arr[m];
    for(int i = 0; i < m; i++)  // converting x into an array, 197 -> {7,9,1}
    {
        arr[i] = x%10;
        x = (x - x%10)/10;
    }
    for(int i = 0; i < m; i++)
        cout << arr[i] << " ";
    cout << "\n";
    if(Fibonacci(arr, x1, m) == true)
    {
        cout << "Generatable" <<"\n";
    }
    else
    {
        cout << "Not Generatable" << "\n";
    }
    
    
    
}
// arr is the array of the first m elements of a M-Digit fibonacci series, x is the number we have check if it exists in the series.
bool Fibonacci(int arr[], int x, int m)
{
    int sum = 0;
    while(sum < x)
    {
        sum = 0;
        for(int i = 0; i < m; i++)
        {
            sum = arr[i] + sum;
        }
        if(sum == x)
            return true;
        // This following code shifts the array in this manner, 7,9,1 -> 7,7,9 -> 17,7,9  (17 is the sum calculated previously)
        for(int i = m-1; i > 0; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[0] = sum;
        for(int i = 0; i < m; i++)
        cout << arr[i] << " ";
        cout << "\nsum = " << sum << "\n";
    }
    return false;
}
/*
// FOR N = LONG (modulus won't work for large integers)
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
bool Fibonacci(long arr[], long n, long m);
long mod(string num, int a);
int main()
{
    string n;
    long m;
    cin >> n >> m;
    long x = pow(10,m);
    cout << "x = " << x << "\n";
    x = mod(n,x); // x = last m digits of n
    long x1 = x;
    cout << "x = " << x << "\n";
    long arr[m];
    for(int i = 0; i < m; i++)  // converting x into an array, 197 -> {7,9,1}
    {
        arr[i] = x%10;
        x = (x - x%10)/10;
        cout << "x = " << x << "\n";
    }
    for(int i = 0; i < m; i++)
        cout << arr[i] << " ";
    cout << "\n";
    if(Fibonacci(arr, x1, m) == true)
    {
        cout << "Generatable" <<"\n";
    }
    else
    {
        cout << "Not Generatable" << "\n";
    }
    
    
    
}
bool Fibonacci(long arr[], long x, long m)
{
    int sum = 0;
    while(sum < x)
    {
        sum = 0;
        for(int i = 0; i < m; i++)
        {
            sum = arr[i] + sum;
        }
        if(sum == x)
            return true;
        for(int i = m-1; i > 0; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[0] = sum;
        for(int i = 0; i < m; i++)
        cout << arr[i] << " ";
        cout << "\nsum = " << sum << "\n";
    }
    return false;
}
long mod(string num, int a)
{
    // Initialize result
    long res = 0;
    // One by one process all digits of 'num'
    for (int i = 0; i < num.length(); i++)
         res = (res*10 + (int)num[i] - '0') %a;
 
    return res;
}
*/