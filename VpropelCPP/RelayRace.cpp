/* 25 - 4 - 2021
Varied Distance Relay Race
A relay race is to be conducted by a sports club for ‘x’ meters. It is a different type of race in which each runner in a 
team can run different distances but there should be four runners in a team. There is a group of runners and they can run 
with maximum speed for varied distances according to their capacity. Given the value of ‘x’ and the speed with which each 
runner in the group can run check if four players in the group can exactly run the distance ‘x’. For example, if x is 7 and 
if there are six runners with capacity as 1 3 2 6 1 7 then players with capacity 1 3 2 and 1 with indices 1, 2, 3, 5 can 
form the team for relay race.

Boundary conditions
Only one such team may exist

Input Format
First line the value of x
Next line contains the value of n, number of people in the group
Next line contains the capacity of the n runners separated by a space

Output Format
Print the index of the players who can form the team so that the sum of their capacity exactly matches x. Index starts with 1
If no such team exist then print No
*/


#include<iostream>
using namespace std;
int main()
{
    int a,b,i,j,k,l,c[20],d=0;
    cin >> a >> b;
    for(int i=0;i<b;i++)
        cin >> c[i];
        
    for(i = 0; i < b - 3; i++)
    {
        for(j = i + 1; j < b - 2; j++)
        {
            for(k = j + 1; k < b - 1; k++)
            {
                for(l = k + 1; l < b; l++)
                {
                    if(c[i] + c[j] + c[k] + c[l] == a)
                    {
                        cout << i+1 << " " << j+1 << " "<< k+1 << " " << l+1;
                        d=1;
                        break;
                    }
                }
                if(d==1)
                {
                    break;
                    
                }
            }
            if(d==1)
            {
                break;
            }
        }
        if(d==1)
        {
            break;
        }
    }
    if(d==0)
    {
        cout << "No";
    }
}