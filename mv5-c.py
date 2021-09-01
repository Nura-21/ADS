l,r = map(int, input().split())
lt = set([int(i) for i in input().split()])
all = []
for i in range(l,r+1):
    all.append(i)
print(*(set(all) ^ lt))