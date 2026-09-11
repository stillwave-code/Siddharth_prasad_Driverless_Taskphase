n=int(input("Enter the number of numbers to be inserted\n"))

hash_table=[]
for i in range(10):
    hash_table.append([]) #for creating sublist
print("Enter the numbers")
for i in range(n):
        num=int(input())

        index=num %10

        hash_table[index].append(num)
        
print("The Hashing table is\n")
for i in range(10):
      print("Index",i,":",hash_table[i])