/*30-3-2021
Find Fruits Left Over
Fruit smash is an interesting online game in which three fruits apple, orange and mango are arranged in a linear fashion. 
If all the three different fruits occur adjacent then they are smashed. The smashing process continue till no three adjacent 
fruits are different. The smashing process starts from the left side. A single smash at point 'p' may initiate many subsequent 
smashes to the points 'q' < 'p' and all triplets on the left side must be smashed before the triplets on their right side. 
In the representation, letter ‘a’ is used for apple, ‘m’ for mango and ‘o’ for orange.

Given a string of letters representing the arrangement of fruits, write a C/C++ program to findout the fruits that are 
left over after the smashing process. If all the fruits are smashed then print ‘No fruit is left over’.

For example, if the input is amammoamaoo then the output is am representing that an apple and a mango is left over. If 
the input is momoaamoomaa then output should be ‘No fruit is left over’.

Boundary Conditions

The length of the string can be upto 200

Input Format

First line contain the string representing the arrangement of fruits. One letter for one fruit, ‘a’ for apple, ‘o’ for 
orange and ‘m’ for mango

Output Format

Print the letters of the fruits left over and if all the fruits are smashed then print ‘No fruit is left over’

Input
amammoamaoo
Expected output
am

Input
momoaamoomaa
Expected output
No fruit is left over
*/
// incomplete
#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
int main()
{
    char * ptr;
    char arr[100];
    cin >> arr;
    ptr = (char*) malloc(100 * sizeof(char));
    if (ptr == NULL) {
        cout << "Memory not allocated.\n";
        exit(0);
    }
    for(int i = 0; i < strlen(arr); i++)
    {
        *(ptr+i) = arr[i];
    }
    char temp1 = 0, temp2 = 0, temp3 = 0;
    temp1 = arr[0];
    temp2 = arr[1];
    
    int n = strlen(arr);
    char * ptr2;
    ptr2 = (char*) malloc(100 * sizeof(char));
    *(ptr2+0) = *ptr;
    for(int i = 2; i < strlen(ptr2); i++)
    {
        temp3 = *(ptr+i);
        if(temp1 != temp2 && temp2 != temp3)
        {
            n = n - 3;
            *(ptr+i-2) = 42;
            *(ptr+i-1) = 42;
            *(ptr+i) = 42;
            ptr2 = (char*) malloc(100 * sizeof(char));
            int count = 0;
            for(int i = 0; i < n+3; i++)
            {
                 if(arr[i] != 42)
                {
                    *(ptr2+count) = *(ptr+i);
                    count++;
                }
            }
            ptr = (char*)realloc(ptr, n * sizeof(char));
            for(int i = 0; i < n; i++)
            {
                *(ptr+i) = *(ptr2+i);
            }
        }
        temp1 = *(ptr+i-1);
        temp2 = *(ptr+i);
    }
    for(int i = 0; i < n; i++)
    {
        cout << *(ptr+i);
    }
    free(ptr);
    free(ptr2);
}