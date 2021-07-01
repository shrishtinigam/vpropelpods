/* 16 - 3 -2021
Sides of a Rectangle
Given four points P1, P2, P3 and P4 check whether they can be corners of a rectangle with sides A, B, C and D respectively. 
The naming of the sides of the rectangle are shown as below.
For example, if P1 is (2, 12), P2 is (14, 12), P3 is (14, 22), P4 is (2, 22) then they can be corners A, B, C and D of a rectangle. 
Whereas the points P1 is (5, 12), P2 is (14, 12), P3 is (14, 22), P4 is (2, 22) cannot be corners of a rectangle. 
Distance between any two points P1(x1, y1) and P2(x2, y2) shall be calculated using the formula:
Print Yes if the points P1, P2, P3 and P4 can be corners A, B, C and D of a rectangle respectively and No otherwise.

Input Format
First line contains the coordinates of point P1 separated by a space
Next line contains the coordinates of point P2 separated by a space
Next line contains the coordinates of point P3 separated by a space
Next line contains the coordinates of point P4 separated by a space

Output Format
Print Yes or No*/

#include<stdio.h>
#include<math.h>
int findDistance(int a1, int a2, int b1, int b2);
int main()
{
    int points1[4];
    int points2[4];
    int x;
    for(int i = 0; i < 4; i++)
    {
        scanf("%d", &points1[i]);
        scanf("%c",x);
        scanf("%d", &points2[i]);
    }
    int dist[6];
    int count = 0;
    int count2 = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = count2; j < 4; j++)
        {
            if(i !=j)
            {
                dist[count] = findDistance(points1[i],points2[i],points1[j],points2[j]);
                count++;
            }
        }
        count2++;
    }
    int flag = 0;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if((i !=j) && (dist[i] != -1) && (dist[j] != -1))
            {
                if(dist[i] == dist[j])
                {
                    flag++;
                    dist[i] = -1;
                    dist[j] = -1;
                }
            }
        }
    }
    //printf("%d", flag);
    if(flag == 3)
        printf("Yes");
    else
        printf("No");
}
int findDistance(int a1, int a2, int b1, int b2)
{
    int dist;
    dist = sqrt(pow((a1 - b1),2) + pow((a2 - b2),2));
    return dist;
}