""" 23 - 02 - 21
Gain-Coins is a mxn board game, in which the number of coins in each square increases during enlarge move. 
The number of coins on each square ‘s’ which is row ‘r’ and column ‘c’ increases by the maximum number of coins 
in the row ‘r’ and also increases by the minimum number of coins in the column of ‘c’. Given the number of coins 
in the board write a C program to print the number of coins in the board after enlarge move. For example if the 
number of coins in a 3X3 board is:
2 3 4
5 7 3
3 8 1

Then after enlarge move the number of coins will be:
8 10 9
14 17 11
13 19 10
"""

r = int(input())
c = int(input())

arr = [[0 for i in range(c)] for j in range(r)] 

for i in range(r):
    arr[i] = list(map(int, input().split()))



list1 = [0 for i in range(r)]
for i in range(r):
    x = -1
    for j in range(c):
        if(arr[i][j] > x):
            x = arr[i][j]
    list1[i] = x

list2 = [0 for i in range(c)]
for i in range(c):
    x = 1000
    for j in range(r):
        if(arr[j][i] < x):
            x = arr[j][i]
    list2[i] = x


for i in range(r):
    for j in range(c):
        arr[i][j] = arr[i][j] + list1[i] + list2[j]

sum1 = 0
for i in range(r):
    for j in range(c):
        sum1 = sum1 + arr[i][j]
    
# print(sum1)

for i in range(r):
    for j in range(c):
        print(f"{arr[i][j]} ", end="") 
    print("")
    