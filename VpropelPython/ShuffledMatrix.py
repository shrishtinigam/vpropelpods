"""4 - 3 - 2021"""
# Checks if a matrix is just a shuffled version of another matrix
# Defining a linear search function
def search(arr, x): 
    for i in range(len(arr)): 
        if arr[i] == x: 
            return i
    return -1
    
# Taking rows and columns as input
r = int(input())
c = int(input())

# Taking first row as input
arr = list(map(int, input().strip().split("\t")))

# Declaring an array and eqauting each element with first rows elements (to prevent two pointers to the same array in memory)
arr1 = []
for i in range(len(arr)):
    arr1.append(arr[i])
    
# For each subsequent row, search the first row for a matching char, if it exists, then set that value to -1 on the array being searched from, at the end of the iteration set it back to the original array
# Intialize outer counter to zero, add one if that row is a shuffled version of the first row
count = 0
for i in range(r-1):
    flag = 0
    x = list(map(int, input().strip().split("\t")))
    for i in range(len(x)):
        if(search(arr, x[i]) != -1):
            arr[search(arr,x[i])] = -1
            flag = flag + 1 # Flag increments when the search is successful
    if(flag == c): # If flag is equal to the number of columns, that means the row is a shuffled version of the first row
        count = count + 1
    arr = []
    for i in range(len(arr1)):
        arr.append(arr1[i]) 

# If the count is equal to the total number of subsequent rows, print shuffled row matrix
if(count == r-1):
    print("Shuffled Row Matrix")
else:
    print("Not Shuffled Row Matrix")

"""
The same code without comments


def search(arr, x): 
  
    for i in range(len(arr)): 
        if arr[i] == x: 
            return i
    return -1
    
r = int(input())
c = int(input())

arr = list(map(int, input().strip().split("\t")))

arr1 = []
for i in range(len(arr)):
    arr1.append(arr[i])
    
count = 0
for i in range(r-1):
    flag = 0
    x = list(map(int, input().strip().split("\t")))
    for i in range(len(x)):
        if(search(arr, x[i]) != -1):
            arr[search(arr,x[i])] = -1
            flag = flag + 1
    if(flag == c):
        count = count + 1
    arr = []
    for i in range(len(arr1)):
        arr.append(arr1[i]) 

if(count == r-1):
    print("Shuffled Row Matrix")
else:
    print("Not Shuffled Row Matrix")
        
"""
        