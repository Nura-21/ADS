n,q = map(int, input().split())
l = [int(i) for i in input().split()]
ans = []
for i in range(q):
    l1,r1,l2,r2 = map(int, input().split())
    k = 0
    for j in range(n):
        if l1 <= l[j] <= r1 or l2 <= l[j] <= r2:
            k+=1
    ans.append(k)
for i in ans:
    print(i)