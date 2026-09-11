def multiply( r1, c1, r2, c2):

    print("Enter the elements of the matrix A\n")
    matrix_A=[]
    for i in range(r1):
       row=[]
       for j in range(c1):
          val=int(input("Enter element"))
          row.append(val)
       matrix_A.append(row)

    print("Enter the elements of the matrix B\n")
    matrix_B=[]
    for i in range(r2):
       row=[]
       for j in range(c2):
          val=int(input("Enter element"))
          row.append(val)
       matrix_B.append(row)


    mult=[]
    for i in range(r1):
       row=[]
       for j in range(c2):
          sum=0
          for k in range(c1):
             sum+=matrix_A[i][k]*matrix_B[k][j]
          row.append(sum)
       mult.append(row)
    return mult


r1=int(input("Enter the rows of matrix A\n"))
c1=int(input("Enter the columns of matrix A\n"))

r2=int(input("Enter the rows of Matrix B\n"))
c2=int(input("Enter the columns of Matrix B\n"))
if c1!=r2:
   print("Matrix multiplication not possible")
   
else:
    result=multiply(r1,c1,r2,c2)
    print("The matrix  multiplication is\n",result)
