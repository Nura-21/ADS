f = open("input.txt",'r').readlines()
o = open("output.txt",'w')
if len(f) == 0:
    o.write("No")
else:
    o.write("Good")
    o.write(str(len(f)))