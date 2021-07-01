/* 20 - 3 -2021
Maximum Z-Sum
Z-Sum(i,j) in a matrix M is defined as the sum of the elements in matrix M at positions (i, j), (i, j+1), (i+1, j), (i+1, j+1). Z-Sum(1,1) of the matrix shown in the figure is a11+a12+a21+a22.
Given a mXn matrix, value of i and j, write a C program to find the maximum Z-Sum in the matrix. Print the elements that form Z-structure in order that is print elements at positions (i, j), (i, j+1), (i+1, j), (i+1, j+1). And also print all the positions i,j of the matrix that corressponds to maximum Z-Sum. For example, given a 3X3 matrix as shown below:

1 2 3

2 4 7

1 2 3

The maximum z-sum is 16, the z-structures start with elements in position 1, 2 and 2, 2, the elements that is on the maximum z-structures are 2 3 4 7 and 4 7 2 3.
Input Format
First line contains the number of rows in the matrix m, r
Next line contains the number of columns in the matrix m, c
Next r lines contain the elements of the matrix, one line has the elements of one row and the elements in each column is separated by a space

Output Format
In the first line, print the maximum z sum
In the next 2*m lines, print the position of first element of Z-structure that has maximum z sum followed the elements in the Z-structure with maximum sum in the next line, where ‘m’ is the number of z-structures with maximum z sum
The position of first element of Z-structure with maximum sum and elements in the Z-structure with maximum sum has to be separated by a tab space. Print the elements in the Z-structure in such a way that Z shape is formed when traversed
*/
#include<stdio.h>
int main()
{
    int r, c;
    scanf("%d%d", &r, &c);
    int matrix[r][c];
    int posArray[r*c]; // tracks positions of maxZsum in the matrix
    int count = 0; // Counter for posarray, count/2 = number of maxzsums
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    int maxZsum = 0;
    int temp;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if((i + 1) < r && (j + 1) < c)
            {
                temp = matrix[i][j] + matrix[i + 1][j] + matrix[i][j + 1] + matrix[i + 1][j + 1];
                if(temp > maxZsum)
                {
                    maxZsum = temp;
                }
            }
        }
    }
    
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if((i + 1) < r && (j + 1) < c)
            {
                temp = matrix[i][j] + matrix[i + 1][j] + matrix[i][j + 1] + matrix[i + 1][j + 1];
                if(temp == maxZsum)
                {
                    posArray[count] = i;
                    posArray[count + 1] = j;
                    count++;
                    count++;
                }
            }
        }
    }
    printf("%d\n", maxZsum);
    for(int i = 0; i < count; i = i + 2)
    {
        printf("%d\t%d\n", posArray[i] + 1, posArray[i + 1] + 1);
        printf("%d\t%d\t%d\t%d\n", matrix[posArray[i]][posArray[i + 1]],matrix[posArray[i] ][posArray[i + 1] + 1],matrix[posArray[i] + 1][posArray[i + 1]], matrix[posArray[i] + 1][posArray[i + 1] + 1]);
    }
}