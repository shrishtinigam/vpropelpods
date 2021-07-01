x = int(input())
m = int(input())
arr = [0 for i in range(100)]
for i in range(1,m+1):
    for j in range(1, 101):
        if(j % i == 0):
            if(arr[i-1] == 0):
                arr[i-1] == 1
            else:
                arr[i-1] == 0


print(arr[x-1])

