/* 1 - 3 -2021
Time Taken to Clarify Doubts
A maths teacher wants to make all his students to have a good understanding of the concepts. He regularly give homeworks and clarifies the doubts of his students. Every day some ‘n’ number of students come to him with some number of their doubts to the teacher at the same time. The teacher do not want any of his student to wait for a long time without attended since that may lead them to get frustrated and lose interest. So he follows a particular statergy to clarify their doubts in which the teacher takes multiple rounds to clarify the doubts of a student till all his doubts are clarified. The steps involved in his startegy are:

(i) Students with doubts are made to stand in a queue

(ii) In each round, the teachers clarifies ‘t’ doubts for each student. He starts from the first student in the queue and move till the last student.

(iii) A student leaves the queue as soon as all of his doubts got clarified. Assume that one minute will be taken by the teacher to clarify one doubt.

Given the number of students coming to clarify their doubts, the number of doubts each student has got and the number of doubts ‘t’ that are going to be clarified by the teacher in each round, write a C program to find the number of minutes for each student to clarify his doubts and leaves the queue.

For example, when there are three students with number of doubts as 5, 7 and 8 and the teacher decides to clarify two questions for a student in a round. Time taken for each student to clarify doubts is 13, 18 and 20.

Input Format

First line contains the number of students, n

Next ‘n’ lines contain the number of doubts each student needs to clarify

Number of minutes

Output Format

Print the time taken for each student to clarify his doubts and leave the queue
*/

#include <iostream>
using namespace std;

int AllCleared(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int arr2[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr2[i] = 0;
    }
    int x;
    cin >> x;
    int flag = 0;
    while(AllCleared(arr,n) == 1)
    {
        for(int i = 0; i < n; i++)
        {
            flag = 0;
            if(arr[i] > 0)
            { 
                if(arr[i] >= x)
                {
                    arr[i] = arr[i] - x;
                    if(arr[i] == 0)
                    {
                        arr2[i] = arr2[i] + x;
                    }
                }
                else if(arr[i] > 0 && arr[i] < x)
                {
                    flag = arr[i];
                    arr2[i] = arr2[i] + flag;
                    arr[i] = arr[i] - x;
                }
                for(int j = 0; j < n; j++)
                {   
                    if(arr[j] > 0 && flag == 0)
                    {
                        arr2[j] = arr2[j] + x;
                    }
                    else if(arr[j] > 0 && flag != 0)
                    {
                        arr2[j] = arr2[j] + flag;
                    }
                }
            }
            
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        cout << arr2[i] << "\n";
    }
}