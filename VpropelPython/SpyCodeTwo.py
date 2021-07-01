""" 9 - 3 - 2021
Arithmetic of Secret Agent
Another secret agent ‘Y’ communicates the secret word to his head office as two words ‘W1’ and ‘W2’. The number of characters 
in the codeword is one more than the maximum of length of ‘W1’ and ‘W2’. He has given instruction to his head office to do arithmetic 
on the letters of the alphabet using the following rules:
Addition happens similar to numeric addition and starts from the right most character of the words.
The ASCII value of the characters is used for addition. The right most digit of the result is taken as sum and the remaining 
digits are considered as carry. The letter corresponding to the character position in English alphabet of sum will be the character 
in the codeword (i.e.), 0-a, 1-b, 2-c, …, 25-z.
The carry is added along with the next character to the left of the current character.
The steps 1-3 are repeated till the left most character of the of the longest word among ‘W1’ and ‘W2’ is reached. When end of the 
words ‘W1’ or ‘W2’ is reached then the remaining characters of the longer word alone take part in addition with carry.
The last sum got will be the next to the leftmost character of the codeword. The carry left out will give the leftmost character of 
codeword and it may have more than one digit. If the value exceeds 25, then the equivalent character in the alphabet is obtained in a 
cyclic manner. ie., 26-a, 27-b and so on.
Given two words W1 and W2, develop a pseudocode and a C code to find the codeword sent by the agent.
For example, if S1= ‘zap’ and S2= ‘zap’, then the numerical is sum 26564 and the equivalent alpha sum is obtained as follows:

26-‘a’, 5- ‘f’, 6-‘g’, 4=’e’.
Hence, the alpha sum is ‘afge’
"""

def NumericSum(a, b):
    an = len(a)
    bn = len(b)
    ans = ''
    if(an > bn):
        n = an + 1
    else:
        n = bn + 1
    a.reverse()
    b.reverse()
    carry = 0
    for i in range(n+1):
        if(i < an and i < bn):
            x = a[i] + b[i] + carry
            ans += str(x%10)
            carry = int((x - x%10)/10)
            continue
        if(i >= bn and i < an):
            x = a[i] + carry
            ans += str(x%10)
            carry = int((x - x%10)/10)
            continue
        elif(i >= an and i < bn):
            x = b[i] + carry
            ans += str(x%10)
            carry = int((x - x%10)/10)
            continue
        elif(i > bn or i > an):
            x = carry
            x1 = list(str(x))
            x1.reverse()
            x = ''
            for i in x1:
                x += i
            ans += x
            x =''
            break
    return ans

a = input()
b = input()
an = len(a)
bn = len(b)
if(an > bn):
    n = an + 1
else:
    n = bn + 1
lista = []
for i in range(len(a)):
    lista.append(ord(a[i]))

listb = []
for i in range(len(b)):
    listb.append(ord(b[i]))
    
sum2 = NumericSum(lista, listb)
sum3 = list(sum2)
anslist = []
for i in range(0,n-1):
    anslist.append(chr(int(sum3[i])+97))

x = []
for i in range(n-1, len(sum3)):
    x.append(sum3[i])

summ = 0
for i in range(len(x)):
    summ = summ + (pow(10,i))*int(x[i])
while(summ>25):
    summ = summ - 26
anslist.append(chr(summ + 97))
anslist.reverse()
str1 = ''
for ele in anslist:  
    str1 += ele 
print(str1)
    

