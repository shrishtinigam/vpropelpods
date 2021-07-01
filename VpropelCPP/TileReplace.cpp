/* 17 - 4- 2021
Arrange the Tiles
In a tile game a nXn grid of tiles with numbers are given to the players. In each move then can pluck 
a tile in a particular square and fix it on some other square. Given the numbers written on the tiles 
in current configuration and the numbers written on the tiles in desired configuration, write a C++ 
program to determine the minimum number of moves to be made by the player to attain the desired configuration 
from the current configuration. For example, if the numbers on a 3X3 tile (read row wise) is 23, 12, 45, 67, 
53, 11, 13, 90, 75 and the desired cofiguration is 11, 12, 13, 23, 45, 53, 67, 75, 90 then 6 moves are required.
Input format
First line contains the number of tiles, nXn
Next line contains the numbers written on the tiles in the current configuration separated by a space
Next line contains the numbers written on the tiles in the desired configuration separated by a space
Output format
Print the minimum number of moves to be made to reach desired configuration from initial configuration
*/
#include<iostream>
using namespace std;
int isArrayEqual(int x[], int y[], int n); // returns the position its unequal
void SearchAndSwitch(int arr[], int n1, int n2, int n);
int main()
{
    int n;
    cin >> n;
    int arr1[n];
    int arr2[n];
    for(int i = 0; i < n; i++)
        cin >> arr1[i];
    for(int i = 0; i < n; i++)
        cin >> arr2[i];
    int count = 0;
    while(isArrayEqual(arr1,arr2,n) != -1)
    {
        int x = arr1[isArrayEqual(arr1,arr2,n)];
        int y = arr2[isArrayEqual(arr1,arr2,n)];
        SearchAndSwitch(arr1, x, y, n);
        count++;
    }
    cout << count;
}

int isArrayEqual(int x[], int y[], int n)
{
    for(int i = 0; i < n; i++){
        if(x[i] != y[i])
            return i;
    }
    return -1;
}

void SearchAndSwitch(int arr[], int n1, int n2, int n)
{
    int pos1, pos2;
    for(int i = 0; i < n; i++){
        if(arr[i] == n1)
            pos1 = i;
        if(arr[i] == n2)
            pos2 = i;
    }
    arr[pos1] = n2;
    arr[pos2] = n1;
}