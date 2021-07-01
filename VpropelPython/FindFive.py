"""5 - 4 - 2021
Find the Five Numbers
Consider five numbers A, B, C, D and E where A ≤ B ≤ C ≤ D ≤ E, given the sum of all the possible two numbers combination in 
ascending order, write a C program to find the numbers A, B, C, D and E. That is if the sum of all the possible two numbers 
combination is 110, 112, 113, 114, 115, 116, 117, 118, 120, and 121. Then the numbers are 54, 56, 58, 59, 62.
Input Format
First line contains ten numbers separated by a space representing the sum of possible two number combinations in ascending order
Output Format
Print the values of A, B, C, D and E separated by a space
"""
l = list(map(int, input().split()))
t = sum(l)//4
c = t - l[0] - l[9]
a = l[1] - c
e = l[8] - c
b = l[0] - a
d = l[9] - e

print(f"{a} {b} {c} {d} {e}")