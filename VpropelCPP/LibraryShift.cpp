/* 6 - 3 - 2021
Help to Shift Library
In a village, the local library is to be shifted from one place to the other. Books are to be taken from the old location to the new one, there are no vehicles to help the librarian. Two children Ramu and Somu volunteered to help the librarian in the shifting process. Since there are many books shifting will require many trips. The librarian thinks that the children will become tired over time. So he plans to shift the bigger books first and then the smaller books. To make the shifting process interesting he asks Ramu to carry ‘i’ books and Somu to carry ‘2*i’ books in the odd trips and during even trips Ramu has to carry ‘2*i’ books and Somu has to carry ‘i’ books. Where ‘i’ is the trip number and the trips are numbered from 1.

Given the total number of books in the library, write a C program to find out the number of trips required to shift the books, number of books carried by Ramu, number of books carried by Somu and the name of the child that keep the last book in the new location of the library.

For example, when there are 27 books, it will take totally four trips to complete the shifting, Ramu would carry 16 books, Somu would carry 11 books, and the last book will be placed by Somu. When there are 48 books it will take totally six trips to shift, Ramu would carry 24 books, Somu would carry 24 books, and the last book will be placed by Ramu.

Input Format

First line contains the total number of books in the library, n

Output Format

First line should contain the number of trips taken for shifting

Nex line should contain the number of books carried by Ramu and Somu separated by a tab

Next line should contain the name of the child who carried the last book*/
#include <iostream>
using namespace std;
int ramu = 0, somu = 0, N, flag;
int lastChild = 3; // 1 - ramu , 2 - somu
void rAdd(int i);
void sAdd(int i);
int main()
{
    int n;
    cin >> n;
    flag = 0;
    N = n;
    int r,s,i;
    i = 1;
    while(N > 0)
    {
        if(i%2 != 0)
        {
            rAdd(i);
        }
        else
        {
            sAdd(i);
        }
        i++;
    }
    
    cout << i - 1  << "\n";
    cout << ramu << "\t";
    cout << somu << "\n";
    if(lastChild == 1)
        cout << "Ramu";
    else
        cout << "Somu";
}

void rAdd(int i)
{
    if(N - 3*i >= 0)
    {
        N = N - 3*i;
        ramu = ramu + i;
        somu = somu + 2*i;
    }
    else
    {
        if(N > i && N < 3*i)
        {
            N = N - i;
            ramu = ramu + i;
            somu = somu + N;
            N = N - N;
            lastChild = 2;
        }
        else if(N < i)
        {
            ramu = ramu + N;
            N = N - N;
            lastChild = 1;
        }
    }
}
void sAdd(int i)
{
    if(N - 3*i > 0)
    {
        N = N - 3*i;
        ramu = ramu + 2*i;
        somu = somu + i;
    }
    else
    {
        if(N > 2*i && N < 3*i)
        {
            N = N - 2*i;
            ramu = ramu + 2*i;
            somu = somu + N;
            N = N - N;
            lastChild = 2;
        }
        else if(N < 2*i)
        {
            ramu = ramu + N;
            N = N - N;
            lastChild = 1;
        }
    }
}