l = [int(x) for x in input().split()]
d = {}
for i in range(len(l)):
    d[l[i]] = d.get(l[i],0) + 1
mx = 0
mx_name = 0
for i in sorted(d):
    if mx < d[i]:
        mx = d[i]
        mx_name = i
print(mx_name)
    