/*6 - 4 -2021
Lucky card
An ordered letter pattern is a set of letters in alphabetical order. In a lucky game, a player gets a letter card which has got a matrix of alphabets in it. The letter card has N rows of M random letters in each row. An ordered letter pattern P of length L <= Min(N,M) will be announced.
If the letters of ‘P’ occurs continuously in the ordered letter pattern that could be formed with letters either along row or column in the letter card of the player then the player is lucky.
Given the matrix in the letter card of the player and and an ordered letter pattern P, develop pseudocode and C code to print “Lucky Player”. Otherwise, print “Unlucky Player”
For example, if the player has a letter card that has the following matrix
Q W E R
A S D F
Z X C V
and the announced ordered pattern P is AFS, then the player is lucky because the ordered letter pattern that could be formed with ASDF matches with the given pattern P.
Input Format
Enter the number of letter collection, N
Enter the number of letters M in each collection
Enter N*M characters one in each row
Enter the pattern P
Output Format
Ordered letters in collection that matches with ordered letters in pattern
Lucky Player
or
Unlucky Player
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
void OrderedLetterPattern(char string[],int n);
int main()
{
    int n, m;
    cin >> n >> m;
    char arr[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin>>arr[i][j];
    }

    char pattern[min(n,m)];
    cin >> pattern;
    char temp0[strlen(pattern)];
    char temp1[m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < strlen(pattern); j++)
            temp0[j] = pattern[j];
        for(int j = 0; j < m; j++)
            temp1[j] = arr[i][j];
        for(int j = 0; j < m; j++)
        {
            for(int k = 0; k < strlen(pattern); k++)
            {
                if(temp0[k] == temp1[j])
                {
                    temp0[k] = 42;
                }
            }
        }
        int count = 0;
        for(int k = 0; k < strlen(pattern); k++)
        {
            if(temp0[k] == 42)
                count++;
        }
        if(count == strlen(pattern))
        {
            OrderedLetterPattern(temp1, m);
            cout << "Lucky Player";
            return 0;
        }
    }
    
    char arr2[m][n];
    for(int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            arr2[i][j] = arr[j][i];

    char temp2[n] = {"0"};
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < strlen(pattern); j++)
            temp0[j] = pattern[j];
        for(int j = 0; j < n; j++)
            temp2[j] = arr2[i][j];
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < strlen(pattern); k++)
            {
                if(temp0[k] == temp2[j])
                {
                    temp0[k] = 42;
                }
            }
        }
        int count = 0;
        for(int k = 0; k < strlen(pattern); k++)
        {
            if(temp0[k] == 42)
                count++;
        }
        if(count == strlen(pattern))
        {
            OrderedLetterPattern(temp2, n);
            cout << "Lucky Player";
            return 0;
        }
    }
    cout << "Unlucky Player";
    return 0;
}

void OrderedLetterPattern(char string[],int n)
{
    char temp;
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (string[i] > string[j]) {
					temp = string[i];
					string[i] = string[j];
					string[j] = temp;
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
	    cout << string[i];
	}
	cout <<"\n";
	return;
}