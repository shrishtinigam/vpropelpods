''' 2 - 03 - 21
Print the Pattern
Given the value of ‘n’ write a C program to print a special rectangular pattern with dots and starts. When the value of n is 5 the rectangle looks as below:

. . . . * . . . .

. . . * . * . . .

. . * . . . * . .

. * . . . . . * .

* . . . . . . . *

Input Format
First line contains the value of ‘n’
Output Format
Print the pattern appropriate to the value of ‘n’
Dots and stars are separated by one space and each row in the pattern is separated only by a new line character.'''
n = int(input())
n1 = n - 1
n2 = 1
print(". "*n1,end = '')
print("*", end = ' ')
print(". "*(n1-1), end = '')
print(".")
for i in range(n-1):
    n1 = n1 - 1
    print(". "*n1,end = '')
    print("*", end = ' ')
    print(". "*n2, end = '')
    print("*", end = ' ')
    if(n1>0):
        print(". "*(n1-1), end = '')
        print(".")
    else:
        print(". "*n1)
    n2 = n2 + 2
