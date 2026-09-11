#Create a class with a function that does selection sort on a list of
#strings. Input a list like Q1, call the function, print the output.
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
 
n=int(input("Enter the value of n\n"))
lst=[]
for i in range(n):
    str=input("Enter the Strings\n")
    lst.append(str)

sorter=sorting() #object creation

Sorted_lst=sorter.selection_sort(lst) #calling using the function
print("The sorted list is",Sorted_lst)

