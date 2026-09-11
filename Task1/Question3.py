# Create a class with a function that does binary search in a list of strings.
#Input a list like Q1, sort it using your Q2 function, input a string, search for it

class sorting:
 def selection_sort(self,lst):
   
    length=len(lst)
    for i in range(length):
        min_index=i
        for j in range(i+1,length):
           if lst[j]<lst[min_index]:
               min_index=j
        temp=lst[i]
        lst[i]=lst[min_index]
        lst[min_index]=temp
    return lst
 

class Bin:
   def Bin_Search(self,lst1):
    key=input("Enter the string to be searched\n")
    length=len(lst1)
    index=-1
    #for i in range(i,length):
    low=0
    high=length-1
    while low<=high:
        mid=(high+low)//2

        if key<lst1[mid]:
            high=mid-1
        elif key>lst1[mid]:
            low=mid+1
        elif key==lst1[mid]:
            index=mid
            break
    if index==-1:
       print("No such element exists\n")
    else:
        print("The element is found at the position\n",index+1)

n=int(input("Enter the value of n\n"))
lst=[]
for i in range(n):
    str=input("Enter the Strings\n")
    lst.append(str)

sorter=sorting() #object creation

Sorted_lst=sorter.selection_sort(lst) #calling using the function
print("The sorted list is",Sorted_lst)

sorter1=Bin() #object creation 2

sorter1.Bin_Search(Sorted_lst) #function called