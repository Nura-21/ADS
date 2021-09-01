n = int(input())
l = []
def check():
    s = str(input())
    for i in range(len(s)):
        if s[i].isdigit == True or s[i].islower == True or s[i].isupper == True:
            return True
        else:
            return False
for i in range(n):
    l.append(input().split())
for i in l:
    for j in range(len(i)):
        if len(i[j]) == True:
            print("YES")