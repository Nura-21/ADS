n = int(input())
ans = []
for i in range(n):
    line = input().split()
    if line[0] == "1":
        ans.append(int(line[1]))
    else:ans.reverse()
print(*ans)