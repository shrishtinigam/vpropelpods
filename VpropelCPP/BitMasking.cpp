/* 3 - 3 - 2021
Bit Masking
Bit masking is an important phenomenon which is very much helpful in graphical applications. In bit masking, bitwise operations are used to on, off, toggle and query status of bits. Bitwise OR operation with ‘1’ sets a bit on and bitwise OR with ‘0’ leaves a bit unchanged. Bitwise AND operation with a ‘0’ leaves it off and bitwsie AND with ‘1’ leave it unchanged. To toggle a bit, that is to change the bit from ‘0’ to ‘1’ or vice versa it has to be XOR-ed with ‘1’ or ‘0’ as required.

Querying a bit can be acheived using AND operation, that is to know the status of the least significant bit (right most) of a number ‘x’, AND operation can be perfomed with 1. If the least significant bit is 1 then the result of the bitwise AND operation is 1 and it is 0 otherwise. Similarly ‘x’ AND 2 will return 2 when the second bit from right is 1 and 0 otherwise. To check the third, fourth bit and so on bitwise AND operation may be performed with numbers 4, 8, 16 and so on.

Given two unsigned integers ‘M’ and ‘N’, write a C program to find out the bit positions with same bits. For example, when M is 268435446 and N is 1006, unsinged integers a re represented using 4 bytes that is 32 bits internally and representation of these numbers internally are:

M - 00001111111111111111111111110110

N - 0000000000000000000001111101110

Number of bits positions with same bits is 12 and they are:

1, 2, 3, 6, 7, 8, 9, 10, 29, 30, 31, 32

Bit positions are numbered 1 to 32 from right to left.

Input Format

First line contains the value of M

Next line contains the value of N

Output Format

Print the bit positions with same bits on a line and separated by a space

*/

#include <iostream>
#include <stdlib.h>
using namespace std;
void decToBinary(int n);
int main()
{
    int m, n;
    cin >> m >> n;
    
    int binaryNum1[32]; 
    int binaryNum2[32];
    
    // Initializing two arrays of 32 elements each with zeroes
    for(int i = 0; i < 32; i++)
    {
        binaryNum1[i] = 0;
    }
    for(int i = 0; i < 32; i++)
    {
        binaryNum2[i] = 0;
    }
    
    // Converting the numbers in binary
    int i = 0; 
    while (m > 0) { 
        // storing remainder in binary array 
        binaryNum1[i] = m % 2; 
        m = m / 2; 
        i++; 
    } 
    
    int j = 0; 
    while (n > 0) { 
        // storing remainder in binary array 
        binaryNum2[j] = n % 2; 
        n = n / 2; 
        j++; 
    } 

    // The binary number is in reverse order

    // If you want to print the binary numbers, use this
    /*
    for(int k = 0; k < 32; k++)
    {
        cout << binaryNum1[k] <<" ";
    }
    cout <<"\n";
    for(int k = 0; k < 32; k++)
    {
        cout << binaryNum2[k] <<" ";
    }
    cout <<"\n";
    */
    
    // Intializing a result array of 32 elements with zeroes
    int arr[32];
    for(int k = 0; k < 32; k++)
    {
        arr[k] = 0;
    }
    
    // Using XOR on every element respectively, if the answer is 0 then they are the same, save that position in the reult array
    int x = 2;
    for(int k = 0; k < 32; k++)
    {
        x = (binaryNum1[k] ^ binaryNum2[k]); 
        if(x == 0)
        {
           arr[k] = 1; 
        }
    }

    // Printing out the result array in order
    for(int k = 0; k < 32; k++)
    {
        if(arr[k] == 1)
        {
            cout << k + 1 << " ";
        }
    }
}
