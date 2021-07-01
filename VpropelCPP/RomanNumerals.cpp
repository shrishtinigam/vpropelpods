/*21 - 4 - 2021
Valid Customized Roman Numeral
Some modification is made in description and One More Example is added in the problem for Clarity
A teacher wants to give an assignment on Roman numberals. But she is afraid that the students may get the answer from internet. 
Therefore she customizes the roman numerals with changes in the rule of formation. Romans represented numbers using the numerals 
I, V, X, L, C, D, and M as shown in the table:

Roman Numeral          Hindu-Arabic Equivalent

I                               1
V                               5
X                               10
L                               50
C                               100
D                               500
M                               1000

There are a few rules for writing numbers with Roman numerals:
Repeating a numeral represents addition of the number. For example, III represents 1 + 1 + 1 = 3.
Only I, X, C, and M can be repeated that is III is valid but LL is not valid
Writing numerals that decrease from left to right represents addition of the numbers. 
For example, LX represents 50 + 10 = 60 and XVI represents 10 + 5 + 1 = 16.
Writing numerals that increase from left to right represents subtration. 
For example, IV represents 5 - 1 = 4 and IX represents 10 - 1 = 9.
Maximum of two same small numerals can only be written to the left of a Roman numeral. For example, 8 can be represented by either VIII or IIX
For example, XXXIX is 39 and XXXXIIX is 48.  IIIIX is invalid. Given a string of roman numeral, write a C++ code to check if it is valid 
and also print the arabic equivalent if valid and print Invalid otherwise.

More Example
Value of LDMM = 1450
Input Format
First line contains the roman numeral string, s
Output Format
Print the arabic equivalent of s
*/

// CODE WRITTEN BY Akshaya

#include <iostream>
#include <string>
#include <algorithm>   //for count() 
using namespace std;
struct roman{
    char list[7]= {'I','V','X','L','C','D','M'};
    int value[7]={1,5,10,50,100,500,1000};
}k;
int index_finder(char element){
    int index;
    for(int j=0;j<7;j++){
        if(element==k.list[j])
            return j;
    }
}
int main(){
    string s;
    cin>>s;
    int a,b,c,total=0;
    //Eliminate invalid test cases first
    /*for(int i = 0; i < s.length(); i++)
        cout << i << "th element = " << s[i] << "\n";*/
    char repeaters[3]= {'V','L','D'};
    for(int i=s.length()-1; i>=0;i--){      //reversed string iteration

        //Invalid 1: When V,L,D are repeating more than once
        for(int j=0;j<3;j++){
            if((s[i]==repeaters[j])&&(count(s.begin(),s.end(),s[i]) >1)){ 
                    cout<<"Invalid";
                    exit(0);   
            }
        }
        //Invalid 2: A character repeats more than twice and is less than the following    
        a=index_finder(s[i-1]);
        b=index_finder(s[i]); 
        c=index_finder(s[i+1]);     
        if((s[i-3]==s[i-2])&&(s[i-2]==s[i-1])&&(b>a)&&(i>=3)){
            cout<<"Invalid";
            exit(0);  
        }

        //For Valid cases 
        if(i==s.length()-1)
        total+=k.value[b];      //last character is always added first 
        else{     
            if(b<c)
            total-=k.value[b];
            else if(b==c){
                if(c<index_finder(s[i+2]))
                    total-=k.value[b];
                else
                    total+=k.value[b];           
            }
            else
                total+=k.value[b];
        }
    }
    cout<<total;
}