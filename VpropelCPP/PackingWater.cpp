/*4 - 4 - 2021
Packing Water Bottles for a Resort
There is a resort ‘ABC’ in a hill station, during season time many tourist come and stay in the resort. Everyday each resident of the resort is given a water bottle. From a mineral water plant, water bottles are packed in a cardboard box and sent to the resort. As per the bookings done, during first ‘m’ days the number of tourists staying in the resort gets increased and during the next ‘n’ days the number of tourists staying in the resort gets decreased. The resort places the order to the mineral water plant well in advance. There are two packaging machines M1 and M2 in the mineral water plant. M1 is used for packing when the number of bottles are multiple of 5 and M2 is used for packing all number of bottles. The working speed of M1 is much faster than M2 and both the machines pack the bottles faster when they are given number of bottles in ascending order. Given the number of guests for the first ‘m’ and subsequent ‘n’ days, write a C/C++ program to find the ordered list of number of bottles to be sent to M1 and M2 so that the packing can be done in minimum possible time.
For example, if the number of visitors for the first seven days is 12, 17, 20, 27, 29, 31, 35 and for the next six days the number of visitors in 30, 28, 25, 23, 16, 5 then the ordered list of bottles to be packed given for M1 is 5, 20, 25, 30, 35 and for M2 it is 12, 16, 17, 23, 27, 28, 29, 31.
Input Format
First line contains the value of m
Next line contain ‘m’ values separated by a space
Next line contains the value of n
Next line contain the value of ‘n’ values separated by a space
Output Format
First line should contain the number of bottles to be packaged by M1 in order
Next line should contain the number of bottles to be packaged by M2 in order
Note:There is a space at the end of both the lines in the expected output
*/
#include<iostream>
using namespace std;
void mergeSort(int arr[],int l,int r);
void merge(int arr[], int l, int m, int r);
int main()
{
    int n, m;
    // Input the first array
    cin >> n;
    int listn[n];
    for(int i = 0; i < n; i++)
        cin >> listn[i];
    // Input the second array
    cin >> m;
    int listm[m];
    for(int i = 0; i < m; i++)
        cin >> listm[i];
    
    // Combine both the arrays into one array (total array)
    int listt[n+m];
    int count = 0;
    for(int i = 0; i < n; i++){
        listt[i] = listn[i];
        count++;
    }
    for(int k = count; k < m+n; k++)
        listt[k] = listm[k-n];

    // Sort the total array
    mergeSort(listt,0,n+m-1);
   
    // Segregate the sorted array into the two required lists (it will stay sorted)
    int list5[100], listo[100];
    int count1 = 0, count2 = 0;
    for(int i = 0; i < n + m; i++)
    {
        if(listt[i]%5==0)
        {
            list5[count1] = listt[i];
            count1++;
        }
        else
        {
            listo[count2] = listt[i];
            count2++;
        }
    }
    for(int i = 0; i < count1; i++)
    {
        cout << list5[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < count2; i++)
    {
        cout << listo[i] << " ";
    }
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
 