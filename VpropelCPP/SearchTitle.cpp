/* 24 - 3 - 2021
Search Titles of Books
Ajay’s favourite book has title ‘t’, he is interested in finding the title of books in his school library whose title is made up of only letters of ‘t’ and has all letters in ‘t’ equal to or more number of times as in ‘t’. For example, if the title of the Ajay’s favourite book is “rail safety” then the book titled “fairy tales” and “yes its a rail safe” are the books of his interest. If no such book exist then print “No such book”. Given the title of Ajay’s favourite book and the title of books in his school library, write a C++ program to print all titles that are of interest or “No such book”.

Input Format
First line contains the title of the Ajay’s favourite book
Next line contains number of books in the school library, n
Next ‘n’ lines contain the title of the books

Output Format
Print all title of books that are of interest if exists and print No such book otherwise

Note:
1. Ignore spaces for processing
2. To read a string with spaces in C++ use getline function of cin object. For example to read a string with spaces into a character array, char s[100], write cin.getline(s,100);
3. After reading an integer or float using normal cin, use cin.ignore() before using cin.getline function
*/
#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    char title[100];
    int n;
    int alphabets[26] = {0};
    cin.getline(title,100);
    for(int i = 0; i < strlen(title); i++){
        if((title[i] > 96) && (title[i] < 123))
            alphabets[title[i] - 97] = 1;
        else if((title[i] > 64) && (title[i] < 91))
            alphabets[title[i] - 65] = 1;
    }
    int nosuch = 0;
    cin >> n;
    cin.ignore();
    char book[100];
    for(int i = 0; i < n; i++)
    {
        int temp = 0;
        cin.getline(book,100);
        for(int j = 0; j < strlen(book); j++)
        {
            if((book[j] > 96) && (book[j] < 123))
            {    
                if(alphabets[book[j] - 97] == 0)
                    temp = 1;
            }       
            else if((book[j] > 64) && (book[j] < 91))
            {
                if(alphabets[book[j] - 65] == 0)
                    temp = 1;
            }
        }
        if(temp == 0){
            nosuch = 1;
            printf("%s\n",book);
        }
    }
    
    if(nosuch == 0)
        printf("No such book");
}



