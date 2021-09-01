l = input().split()
ans = 0
for i in l:
    if len(i) % 2 == 0:
        ans+=1
print(ans)