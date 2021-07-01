# POD 9 January 2021
# EASY
# A positive integer is called as a `Consecutive Four Sum (CFS) number' if that number can be expressed as the sum of four consecutive positive integers. 
# Given a number `n', write an algorithm and the subsequent python code to check whether the given number is a CFS number or not.
def consec_4_number_adder(n):
    ans = 4*n+6
    return ans
temp = 0
n = int(input())
if(n%2!=0):
    print(0)
else:
    for i in range(int(n/2)):
        temp = consec_4_number_adder(i)
        if(temp == n):
            print(1)
            print(i)
            break 

            



