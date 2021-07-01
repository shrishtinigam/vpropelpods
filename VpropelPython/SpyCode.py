""" 8 - 03 - 2021
Secret Agent and Code Word
A secret agent is a government employee whose job involves gathering secret information about the governments of unfriendly foreign countries. 
A secret agent ‘X’ emailed a sentence ‘S’ with a code word ‘W’ to his head office. Only one word of the sentence 'S' is real and others are fake. 
The agent ‘X’ also mailed a sentence as a clue - if I tell you any one character ‘C’ of the code word 'W', then you would find exactly two words 
with ‘C’ in it, those words will have same number of vowels and one of them is ‘W’.

For example, if the senetence ‘S’ mailed by agent ‘X’ is "AIM DUE OAT TIE MOD", then TIE is the code word. Due to the following reasons:

https://tenor.com/view/gif-20662682

Input Format

First line contains the sentence with codeword

Output Format

First line should contain the code word

Boundary Conditions

Length of the sentence < 200

Length of each word in the sentence<10

Number of words in each sentence <20

"""
# Condition A: Another word has that letter
# Condition B: Both words have the same number of vowels

# Every letter in the code word will fulfil the condition (A and B) with some other letter.

# A function that outputs the number of vowels in a string
def noOfVowels(x):
    count = 0
    if(x !=0):
        for i in range(len(x)):
            if(x[i] == "A" or x[i] == "E" or x[i] == "I" or x[i] == "O" or x[i] == "U"):
                count = count + 1
    return count

# A funtion the takes a string and a single character and checks if that character comes in that string only once. If the char appears in the str once, it returns True, otherwise False
def oneCommonLetter1(x, y):
    count = 0
    if(y != 0):
        for i in range(len(x)):
            if(x[i] == y):
                count = count + 1
    if(count == 1):
        return True
    else:
        return False

# Input the sentence and convert it to a list of words
arr = list(input().split())
# Intialize output list
arr4 = []

# Iterate over all the words in the sentence
for i in range(len(arr)):
    arr3 = [] 
    count1 = 0
    # Convert the word into an array of letters
    for j in range(len(arr[i])):
        arr3.append(arr[i][j])
    
    for j in range(len(arr)):# Iterating over the array of words
        if(arr[j] != arr[i]): # To prevent accidentally matching the same word
            for k in range(len(arr3)): # Iterating over every letter of the word
                if(oneCommonLetter1(arr[j], arr3[k]) == True): # If that letter exists in the current word (A Condition satisfied)
                    if(noOfVowels(arr[i]) == noOfVowels(arr[j])): # If the word that letter came from and the current word have the same number of vowels (B Condition satisfied)
                        count1 = count1 + 1 # Increase the count of the number of times both conditions were satisfied
                        arr3[k] = 0
    # If the number of times both conditions were satisfied is equal to the number of letters in the word
    if(count1 == len(arr3)):
        arr4.append(arr[i]) # This will happen only once and it will happen when iterating over our required code word

print(arr4[0])
            

"""
Without Comments - 

def noOfVowels(x):
    count = 0
    if(x !=0):
        for i in range(len(x)):
            if(x[i] == "A" or x[i] == "E" or x[i] == "I" or x[i] == "O" or x[i] == "U"):
                count = count + 1
    return count

def oneCommonLetter1(x, y):
    count = 0
    if(y != 0):
        for i in range(len(x)):
            if(x[i] == y):
                count = count + 1
    if(count == 1):
        return True
    else:
        return False


arr = list(input().split())
arr4 = []
for i in range(len(arr)):
    arr3 = []
    count1 = 0
    for j in range(len(arr[i])):
        arr3.append(arr[i][j])
    for j in range(len(arr)):
        if(arr[j] != arr[i]):
            for k in range(len(arr3)):
                if(oneCommonLetter1(arr[j], arr3[k]) == True):
                    if(noOfVowels(arr[i]) == noOfVowels(arr[j])):
                        count1 = count1 + 1
                        arr3[k] = 0
    if(count1 == len(arr3)):
        arr4.append(arr[i])

print(arr4[0])

"""              
            