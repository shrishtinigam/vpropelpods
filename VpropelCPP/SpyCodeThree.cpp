/*15 - 3 - 2021
Code Word Check
An agent ‘A’ comes to a secret place to collect some information, the information will be disclosed to him if he is able to find one of the code words of the group of agents from a given word ‘w’. All the code words are of length four. The agent ‘A’ will say the positions of four letters in ‘w’ that may form the code word. Write a C program to check if the letters in ‘w’ in the positions mentioned by ‘A’ is a code word. For example, if the valid code words are HEAR, BEAR, VEST, MONK and if ‘w’ is ‘RESEARCH’ and position mentioned by the agent is 8, 2, 5 and 6 then it is Valid. Position of letters in the word ‘w’ starts from 1. Print Valid if the word that can be formed by the positions mentioed by the agent ‘A’ is in the list of code words and print Invalid otherwise.

Input Format

First line contains the number of code words among the group of agents, n

Next ‘n’ lines contain the code words

Next line contains the word, ‘w’

Next four lines contain the position of the letters chosen by the agent ‘A’

Output Format

Print either Valid or Invalid

5
HEAR
BEAR
VEST
MONK
NEAR
RESEARCH
8
2
5
6

COMPILES FINE ON IDE, GIVES ERROR HERE
*/
#include<stdio.h>
#include<string.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    char a[10][100];
    for(i=0;i<n;i++)
    {
        scanf("%s",a[i]);
    }
    
    char w[30];
    scanf("%s",w);
    
    int b[4];
    for(i=0;i<4;i++)
    {
        scanf("%d",&b[i]);
    }
    char c;
    char t[10];
    for(i=0;i<4;i++)
    {
        c=w[b[i]-1];
        strncat(t, &c, 1); 
    }
    int flag=0;
    int x;
   
    for(i=0;i<4;i++)
    {
        x=strcmp(a[i],t);
        if(x==0)
        {
           flag=1;
           printf("Valid");
           break;
        }
    }
    if(flag==0)
    {
        printf("Invalid");
    }
    return 0;
  
}