
n=int(input("Enter the value of n\n"))
lst=[]
for i in range(n):
   # print()
    string=input("Enter the string\n")
    lst.append(string)
print("The strings are",lst)
letters={}
for word in lst:
    for alphabet in word:
        alphabet=alphabet.lower()

        if alphabet.isalpha():

            if alphabet in letters:
                letters[alphabet]=letters[alphabet]+1
            else:
                letters[alphabet]=1
# { Name:{lst}

print(letters)