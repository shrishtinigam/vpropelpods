"""Find Number Up Side Down
A number plate was painted in a workshop and fixed in a house. But the person who fixed the plate made a mistake and fixed the board up side down. 
Luckily the numbers written on the plate are readable up side down also. It is a two digit number. For example if difference is 72 then the numbers 
are 08 and 80.
Given the difference between the original number and the number read upside down, write a C++ code to find the numbers

Boundary Conditions
diff>0 and only one number has diff

Input Format
Difference between the original number and number read upside down

Output Format
Print the original number and number read upside down in ascending order separated by a space"""

import sys
diff = int(input())
x = [0,1,6,8,9]
x2 = [0,1,9,8,6]
for i in range(len(x)):
    for j in range(i,len(x2)):
        y = (10*x[i]) + x2[j]
        z = (10*x[j]) + x2[i]
        if(diff == abs(y-z)):
            print(x[i],end="")
            print(x2[j],end=" ")
            print(x[j],end="")
            print(x2[i])
            sys.exit()