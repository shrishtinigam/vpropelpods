"""10 - 4 - 2021
Minimum Value Expression
Given three integers a,b,c ≥ 0, write a C++ program to find the minimum value that may be obtained by expression with only binary operators +, - and *. Use all the three integers for finding minimum value. For example when a= 2, b =1 c = 3 minimum value is -5

Input Format

First line contains the value of a

Next line contains the value of b

Next line contains the value of c

Output Format

Print the minimum value that can be obtained

Input
2
1
3
Expected output
-5

Input
2
2
1
Expected output
-3
"""

arr=[int(input()) for i in range(3)]
arr = sorted(arr)
print(arr[0]-max(arr[1]+arr[2], arr[1]*arr[2]))