"""26 - 3 - 2021
Is Balls Shuffled?
An electromagnet is a type of magnet in which the magnetic field is produced by an electric current. The magnetic field disappears when the current is turned off. Difference between an electromagnet and a permanent magnet is that the strength of magnetic field can be quickly changed by controlling the amount of electric current in the winding.

In an experiment, ‘n’ iron balls are placed on ‘n’ electromagnets in a circular fashion as shown below


The electromagnets are connected among themselves and they are rotated at a constant speed ‘c’ rad/sec. In this experiment one letter of English alphabet or a number is written on each ball. The character written on the balls are unique. During each experiment the current given for the electromagnet is varied and for some values of electric current, the balls gets shuffled.

Always the characters written on the ball are read from the postion where the experimenter is standing. Given the number of balls taken for experimentation, characters written on the balls in the intial configuration and the characters written on the balls after rotation for ‘m’ seconds, write a program to check if the balls are shuffled or not.

For example, if six balls were taken for experimentation and the characters written on the balls intially are ‘p’, ‘a’, ‘s’, ‘g’, ‘h’, ‘y’ and the characters on the balls after rotation is ‘h’, ‘y’, ‘p’, ‘a’, ‘s’ ‘g’ then the balls haven’t shuffled. And if the characters written on the balls initially are ‘a’, ‘c’, ‘e’, ‘i’, ‘m’, ‘n’ and the characters on the balls after rotation are ‘i’, ‘n’, ‘m’, ‘a’, ‘c’, ‘e’ then the balls are shuffled.

Input Format

First line contains the number of balls taaken for experimentation ‘n’

Next ‘n’ lines contain the characters written on the balls initially

Next ‘n’ lines contain the characters written on the balls after rotating for ‘m’ seconds

Output Format

Print either Shuffled or Not Shuffled
"""

n = int(input())
s = ''
for i in range(n):
    s = s + input()
o = ''
for i in range(n):
    o = o + input()
x = 0
temp = 0
for i in range(n):
    for j in range(n):
        if(s[i] == o[j]):
            x = j
            temp = 1
            break
    if(temp == 1):
        break
o = o[x:] + o[0:x]
if(o == s):
    print("Not Shuffled")
else:
    print("Shuffled")


""" BETTER CODE
n=int(input())
s1=''
s2=''
for i in range(n):
    s1+=input()
for i in range(n):
    s2+=input()
    
a=s2.index(s1[0])
b=s2[a:] + s2[:a]
if b==s1:
    print('Not Shuffled')
else:
    print('Shuffled')

"""