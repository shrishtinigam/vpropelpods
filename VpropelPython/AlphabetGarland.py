""" 21 - 3 - 2021
Alpha garland
Given an alphanumeric string S, develop pseudocode and C code for printing the alpha garland by processing S character by character based on the following rules:
If the current character is an alphabet, add it to the garland.
If the current character is a number, then the garland is extended by adding the alphabets present so far in the garland in reverse form and then its original form alternatively.
The process is repeated till the end of the string.
For example, if the S= “ab3c1” ,then the garland is “ab baabba c cabbaabba”
Note: The white space in the garland is given for understanding the process. Actually the garland formed for this string is “abbaabbaccabbaabba”
Input Format
An alphanumeric string, S
Output Format
A string forming the alpha garland
"""
string = input()
output = ''
for i in range(len(string)):
    x = string[i]
    if x.strip().isalpha():
        output = output + x
    if x.strip().isnumeric():
        temp = output
        temp1 = temp
        temp = temp[::-1]
        count = 0
        while(count < int(string[i])):
            output = output + temp
            count = count + 1
            if(count >= int(string[i])):
                break
            output = output + temp1
            count = count + 1

print(output)

"""
#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
string magic(string s,int n){
    string sC;
    sC = s; 
    for(int i=0;i<n;i++){
        if(i%2==0){
            reverse(sC.begin(),sC.end());
            s.append(sC);
            reverse(sC.begin(),sC.end());
        }
        else{
            s.append(sC);
        }
    }
    return s;
}
int main(){
    string s;
    string ns = "";
    cin >> s;
    for(int i=0;i<s.length();i++){
        if(isalpha(s[i])){
            string temp;
            temp = s[i];
            ns.append(temp);
        }
        else{
            char temp2[1];
            temp2[0] = s[i];
            int x;
            x = atoi(temp2);
            ns = magic(ns,x);
        }
    }
    cout << ns;
}
"""