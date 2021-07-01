/* 8 - 4 - 2021
Color of Building Blocks
There is a competition held among students of class six to build a given structure using 
building blocks. Blocks of ‘n’ different colors are given to the participants. One of the 
rule of the competition states that a block of a particular color can be chosen only after 
choosing ‘m’ other given colors where m ≤ n-1. Given the ‘n’ colors, the value of ‘m’ and the 
choice of colors made by the participants, write a C++ program to check if the choices made

For example given four color pink, yellow, blue and green represented by letters ‘p’, ‘y’, 
‘b’ and ‘g’ and the value of m as two, it is valid to choose the colors in the 
sequence pbygpbygbpgypgbygp and the choice of color pbygygbpbygpbygbpgypgbygp is invalid for m=2.

Boundary Conditions
Maximum number of building blocks used in the competition is 300
n ≤ 20

Colors are represented by a unique letter

Input Format
First line contains the value of n
Next line contain the n colors used by the participant and separated by a space
Next line contains the value of m
Next line contains the colors used by the participants in order

Output Format
Print Valid or Invalid */

#include<iostream>
#include<string>
using namespace std;
int searchChar(int arr[], int x, int m);
int main()
{
    int n;
    cin >> n;
    char colors[n];
    for(int i = 0; i < n; i++)
        cin >> colors[i];
    int m;
    cin >> m;

    string str;
    cin>>str;
    int arr[m];
    for(int i = 0; i < m; i++){
        arr[i] = str[i];
    }

    for(int i = m; i < str.length(); i++){
        /*cout << "i = " << i << "\n";
        for(int j = 0; j < m; j++){
            cout << (char)arr[j] <<" ";
        }*/
        cout << " x = " << str[i] << "\n";
        int a;
        a =  str[i];
        if(searchChar(arr,a,m) == 0)
        {
            cout << "Invalid";
            return 0;
        }
        for(int j = 0; j < m; j++){
            arr[j] = (int)str[i + j - m + 1];
        }
    }

    cout << "Valid";
    return 0;
}

int searchChar(int arr[], int x, int m) // 0 if found, 1 if not found
{
    for(int i = 0; i < m; i++)
    {
        int a, b;
        a = (int)arr[i];
        b = x;
        // cout << "a = "  << a << " b = " << b << "\n";
        if(arr[i] == x)
        {
            return 0;
        }
    }
    return 1;
}

// asdfgasdfgasdfgasdfa