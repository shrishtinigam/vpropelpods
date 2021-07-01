/* 11 - 4 - 2021
Correctness of Printed Sheets
Number labels are to be prepared by a small scale printing company. The sheets are cut into uniform 
dimension and fed into the printing machine. The printing machine has to print some numbers in ascending 
order.

 0 1 2 3 4 5 6 7 8 9

The printing machine doesn’t do the job always correct it print numbers in wrong order sometimes. 
But some of the printed sheets are easily correctable by a single cut and a single paste. For 
example, if the printed sheet has numbers 17, 19, 23, 34, 56, 71, 80 then it has done the job 
correct. If the printed sheet has the numbers 76, 89, 91, 96, 23, 28, 29, 37, 45 then it is easily 
correctable since by a single cut after number 96 and single paste before 76 will contain the numbers 
in order that is cut after the 4th number in the printed sheet will do. If the printed sheets has the 
numbers 76, 89, 91, 96, 23, 28, 97, 29, 37, 45 is not easily correctable. Given the numbers in a printed 
sheet, write a C++ code to categorize it to Correct, Easily correctable or Not easilt correctable.

Input Format
First line contains the count of numbers printed in the sheet
Next line contain the numbers printed on the sheet separated by a space

Output Format
Print either Correct, Easily correctable or Not easily correctable
If the sheet is easily correctable then print the position of the number after which 
cut has to be made in the next line
*/
#include <iostream>
#include <algorithm>
using namespace std;
bool arraySameChecker(int arr1[], int arr2[], int n); // Checks if two arrays are the same
void swap(int* a, int* b);
int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
int main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    int y = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> y;
        a[i] = y;
        b[i] = y;
    }
    quickSort(b , 0, n - 1);
    if(arraySameChecker(a, b, n))
    {
        cout << "Correct" << "\n";
        return 0;
    }
    for(int j = 0; j < n - 1; j++)
    {
        if(arraySameChecker(a, b, n))
        {
            cout << "Easily correctable" << "\n" << n - j;
            return 0;
        }
        int x = a[n-1];
        for(int i = n - 1; i > 0; i--)
        {
            a[i] = a[i - 1];
        }
        a[0] = x;
    }
    cout << "Not easily correctable" << "\n";
    return 0;
    
}

bool arraySameChecker(int arr1[], int arr2[], int n)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr1[i] == arr2[i])
            count++;
    }
    if(count == n)
        return true;
    return false;
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ---------------------------------------------------- ANOTHER METHOD
/*
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, position, count = 0;
    cin >> n;
    int a[n];
    cin >> a[0];
    for(int i = 1; i < n; i++)
    {
        cin >> a[i];
        if(a[i]>a[i-1])
            count++;
        if(a[i]<a[i-1])
            position = i;
    }
    if(count == n - 1)
        cout << "Correct";
    else if((count == n - 2) && (a[0] > a[n-1]))
        cout << "Easily correctable" << "\n" << position;
    else
        cout << "Not easily correctable";
}
*/
