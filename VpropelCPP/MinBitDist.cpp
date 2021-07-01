/*16-4-2021
Minimum Bin-Distance Numbers
Two numbers n1 and n2 are said to be have a bin-distance of ‘x’ if ‘x’ bits are different in the corressponding positions in binary representation of n1 and n2. For example, numbers 4 (100) and 6 (110) are having a distance of 1 whereas numbers 2027 (11111101011) and 119 (1110111) are having a distance of 7.
Given a collection ‘c’ of ‘n’ numbers and a number ‘m’, write a C++ program to find the number(s) in ‘c’ that is having minimum bin-distance with m. For example, given three numbers 4, 2 and 5 in collection ‘c’ and if m = 6 then numbers 4 and 2 are having a minimum distance of 1 with 6.
Hint: Try to solve this problem without doing decimal to binary conversion
Input Format
First line contains the number of integers ‘n’ in C
Next ‘n’ lines contain the numbers in C
Next line contains the number m
Output Format
Print all the elements having minimum bin-distance with m. Print one number in one line. Print the minimum bin-distance elements in the order in which it was given in the input
*/
#include<iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> m;
    int arr1[n];
    for(int i = 0; i < n; i++)
    {
        int x = m^arr[i]; // bitwise xor
        int count = 0;
        while(x>0) // count the number of 1's
        {
            if(x%2!=0)
                count++;
            x = x>>1;
        } 
        arr1[i] = count;
    }
    int min = 100000;
    for(int i = 0; i < n; i++) // finding the min bit distance
    {
        if(arr1[i]<min)
            min = arr1[i];
    }
    cout << "\n";
    for(int i = 0; i < n; i++)
    {
        if(arr1[i]==min)
            cout << arr[i] << "\n";
    }
}