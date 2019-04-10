import numpy as np
global N
N = 8
def isSafe(board , row ,col ):
    for i in range(col):
        if board[row][i]==1:
            return False
    for i,j in zip(range(row , -1, -1) , range(col ,-1 , -1)):
        if board[i][j]==1:
            return False
    for i , j in zip(range(row , N ,1) , range(col , -1 ,-1)):
        if board[i][j]==1:
            return False
    return True
def solve(board, col): 
    if col >= N: 
        return True
    for i in range(N): 
        if isSafe(board, i, col): 
            board[i][col] = 1
            if solve(board, col+1) == True: 
                return True
            board[i][col] = 0
    return False
def solveNQ(): 
    board = np.zeros((N,N) ,dtype = np.int8)
    if solve(board, 0) == False: 
        print ("Solution does not exist")
        return False
    print(board) 
    return True
solveNQ() 
