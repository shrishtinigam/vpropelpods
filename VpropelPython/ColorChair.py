""" 5-03-2021 
Find Color of Chair
In a game the participants are made to sit on chairs of three colors Green, Orange, Blue in a big hall. A number of pair of six chairs are arranged opposite to each other and numbered as shown in the following image. In the image each pair of six chairs are separated by a gap that is chairs with number 1 to 12 is a pair, 13 to 24 is a pair and so on.


The first chair is Green, second chair is Orange third chair is Blue in color, fourth is Blue, fifth is Orange and sixth is Green and then the colors of chairs are reversed so that color of chairs on opposite sides are same. The numbering of chairs are increasing from left to right in the first pair and is decreasing from left to right in the second pair. In this game a participant is called and given a chair number, ‘x’. He has to find the number of the chair opposite to ‘x’ and also find the color of ‘x’. For example, when ‘x’ is 30, print 31 and Green when ‘x’ is 46 print 39 and Blue.

Input Format

First line contains the chair number, ‘x’

Output Format

First line contain the chair ‘y’ number opposite to ‘x’

Next line contain the color of chair ‘y’ (Green or Orange or Blue)"""


x = int(input())
if(x % 12 != 0):
    equi = x - 12*int(x/12)
else:
    equi = 12

if(equi == 1 or equi == 6 or equi == 7 or equi == 12):
    color = "Green"
elif(equi == 2 or equi == 5 or equi == 8 or equi == 11):
    color = "Orange"
elif(equi == 3 or equi == 4 or equi == 9 or equi == 10):
    color = "Blue"

y = 0

if(x % 12 != 0):
    y = 13 - equi + 12*int(x/12)
else:
    if(x == 24):
        y = 13
    elif(x == 36):
        y = 25
    elif(x == 48):
        y = 37
    if(x == 12):
        y = 1
    
print(y)
print(color)
    
            