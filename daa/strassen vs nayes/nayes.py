import numpy as np
import sys
import time
start_time = time.time()
arg1 = sys.argv[1]
arg2 = sys.argv[2]
aFile = open(arg1, 'r+')
bFile = open(arg2, 'r+')
aN = int(aFile.readline())
bN = int(bFile.readline())
counter = 0

def genMatrix(inFile, d):
    datalines = inFile
    newMatrix = []

    for x in range(0,d):
        dataline = datalines.readline().split()
        for y in range(0,d):
            yVals = list(map(float, dataline))

        newMatrix.append(yVals)
    return newMatrix
def multiply(mA , mB):
    n1 = len(mA)
    n2 = len(mB)
    # result = [[0 for x in range(n1)] for y in range(n1)]  
    # for i in range(0, n1):
    #     for j in range(0 , n1):
    #     	for k in range(0 , n1):
    #     		result[i][j] += mA[i][k] * mB[k][j]
    #return result
    return np.dot(mA,mB)


matrixA = genMatrix(aFile, aN)
matrixB = genMatrix(bFile, bN)
matrixA = np.matrix(matrixA)
matrixB = np.matrix(matrixB)

matrixC = [[0 for i in range(len(matrixA))]for j in range(len(matrixA))]

temp = multiply(matrixA, matrixB)
temp.astype(int)
file_name = 'array_solution_'+str(aN)+'.txt'
file = open(file_name,'w')
file.write(str(aN)) 
file.write('\n')
np.savetxt(file , temp, fmt='%i' , delimiter=' ')
file.close()
close_time  = time.time()
print('Time of Execution ',close_time-start_time)
