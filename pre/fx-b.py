l = [int(i) for i in input().split()]
id = int(input())
new_l = []
for i in range(1,l[len(l)-1] + 1):
    new_l.append(i)
s = list(set(l) ^ set(new_l))
print(s[id-1])