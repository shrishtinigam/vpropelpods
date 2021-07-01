/*13 - 4 - 2021
Number of Unique Points
Given ‘n’ integers which can be value of X or Y coordinate, write a C++ program to find 
the number of unique points that can be formed. For example given three values 1, 1 and 2 
there can be four unique points (1, 1), (1, 2), (2, 1) and (2, 2) and when the three values 
given are 1, 2 and 3 there can be nine unique points (1, 1), (1, 2), (1, 3), (2, 1), (2, 2), 
(2, 3), (3, 1), (3, 2) and (3, 3). Given the value of ‘n’ integers, write a C++ program to 
find the number of unique points that can be formed with the given points.

Boundary Conditions
n can both positive and negative integers

Input Format
First line contains the value of n
Next line contains the ‘n’ integers separated by a space

Output Format
Print the number of unique points that can be formed
*/
#include<iostream>
using namespace std;
int SearchPresence(int arr[], int x, int n);
int main()
{
    int n,x;
    cin >> n;
    int count = 1;
    int arr[n];
    cin >> arr[0];
    for(int i = 1; i < n; i++)
    {
        cin >> x;
        if(SearchPresence(arr, x, count) == 0)
        {
            arr[count] = x;
            count++;
        }
    }
    cout << count*count << "\n";
    for(int i = 0; i < count; i++)
        cout << arr[i] << " ";
}
int SearchPresence(int arr[], int x, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(x == arr[i])
            return 1;
    }
    return 0;
}