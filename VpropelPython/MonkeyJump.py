def Search(x, arr): 
  
    for i in range(len(arr)): 
        if arr[i] == x: 
            return i 
  
    return -1


n = int(input())
arr = list(map(int, input().split()))
print(arr)
print(arr2)
flag = 0
angry = 0
count = []
x = 0
count.append(arr[x])
x = abs(arr[x] - arr[x+1]) - 1
if(Search(arr[x], count) == true):
    angry = 1
    break
count.append(arr[x])


