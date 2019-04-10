def toh(n , f, t, a):
    if n == 1:
            print ("Moving disk 1 from rod",f,"to rod",t)
            return
    toh(n-1, f, a, t)
    print ("Moving disk",n,"from rod",f,"to rod",t )
    toh(n-1, a, t, f)
n = int(input('Enter Number of Disks for 3 Pegs  '))
print("Number of steps are ",2**n-1)
toh(n, 'A', 'C', 'B')

