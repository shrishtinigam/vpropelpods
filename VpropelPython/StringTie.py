"""22 - 3 - 2021
Math Cum Tie Skill Competition
A compeititon is conducted to test mathematics and tieing skills of kids, some number of beads in three colors red, green and blue are kept in a bowl. Each kid will be given a number ‘n’ and kid has to tie tree strings of beads by mixing the colored beads.


One string of beads is formed with a number ‘m’ as per the following rules:

1. Totally there should be 20 beads in each string and always beads are added to the left side of the string.

2. The kid has to repeatedly divide the number ‘m’ by 3 till it becomes zero, find the remainder ‘r’ and quotient ‘q’. Make ‘n’ as ‘q’.

3. After each division if the remainder is zero then the kid has to add a red bead into the string, if the reminder is one then he has to add green bead and when the remainder is two he has to add a blue bead.

4. When the value of ‘m’ becomes zero, add red beads for the remaining positions. That if four beads were already added by the division process then sixteen more red beads have to added to complete the string with twenty beads.

The first string of beads ‘S’ has to be formed with the given number ‘n’, the second string of beads ‘S1’ has to be formed with a number ‘p’ where p > n and the string of beads S1 will change only by one bead color as comapred to S. The third string of beads ‘S2’ has to be formed with a number ‘q’ where q > n and string of beads S2 will change exactly by two bead colors when compared to S.

Given the number ‘n’, write a C program to find the numbers with which the second and third strings can be tied and also print the color of the beads in the three strings from left to right. For example, if the value of ‘n’ is 5 then the numbers that can be used to tie the strings are 8 and 6 and the color of the beads on the three strings are:

rrrrrrrrrrrrrrrrrrgb

rrrrrrrrrrrrrrrrrrbb

rrrrrrrrrrrrrrrrrrbr

Input Format

First line contains the number, n

Output Format

First line print the numbers that can be used to form the second and the third string. Separate the numbers by a tab

Next line print the color of the beads tied in the first string from left to right

Next line print the color of the beads tied in the second string from left to right

Next line print the color of the beads tied in the third string from left to right"""
# MY ATTEMPT
n=int(input())
def num_to_str(num):
    s=""
    while len(s)!=20:
        if num%3==0:
            s+='r'
        elif num%3==1:
            s+='g'
        elif num%3==2:
            s+='b'
        num=num//3
    return (s[::-1])

def comp(s1,s2):
    count = 0
    for i in range(20):
        if(s1[i] != s2[i]):
            count = count + 1
    return count

s1 = num_to_str(n)
temp = 0
n1 = n
while(temp == 0):
    n1 = n1 + 1
    s2 = num_to_str(n1)
    if(comp(s1,s2) == 1):
        temp = 1
temp = 0
n2 = n
while(temp == 0):
    n2 = n2 + 1
    s3 = num_to_str(n2)
    if(comp(s1,s3) == 2):
        temp = 1

print(n1, end = "\t")
print(n2)
print(s1)
print(s2)
print(s3)

# FASTER
"""
n=int(input())
def num_to_str(num):
    s=""
    while len(s)!=20:
        if num%3==0:
            s+='r'
        elif num%3==1:
            s+='g'
        elif num%3==2:
            s+='b'
        num=num//3
    return (s[::-1])
def str_to_num(s):
    dic={"r":0,"g":1,"b":2}
    z=0
    for i in s:
        z=3*z + dic[i]
    return z

def str_check_1(a1,a2):
    count=0
    for i in range(20):
        if a1[i]!=a2[i]:
            count+=1
    if count==1:
        return True
def str_check_2(a1,a2):
    count=0
    for i in  range(20):
        if a1[i]!=a2[i]:
            count+=1
    if count==2:
        return True
num1=n+1
while True:
    p=num_to_str(n)
    q=num_to_str(num1)
    if str_check_1(p,q):
        temp1=q
        break
    num1+=1

num2=n+1
while True:
    a=num_to_str(n)
    b=num_to_str(num2)
    if str_check_2(a,b):
        temp2=b
        break
    num2+=1

print(str_to_num(temp1),end='\t')
print(str_to_num(temp2))
print(num_to_str(n))
print(temp1)
print(temp2)
"""