lst=[(0,1),(1,2),(0,3)]

ref1=int(input("Enter the 1st coordinate\n"))
ref2=int(input("Enter the  2nd coordinates\n"))
n=len(lst)
for  i  in range(n):
    for j  in range(n-i-1):
        x1,y1=lst[j]
        x2,y2=lst[j+1]
        dist1=(x1-ref1)**2+(y1-ref2)**2
        dist2=(x2-ref1)**2+(y2-ref2)**2

        if dist1>dist2:
            temp=lst[j]
            lst[j]=lst[j+1]
            lst[j+1]=temp
print('The coordiantes are\n')
print(lst)