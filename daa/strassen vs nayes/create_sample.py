import numpy as np
i = '8'

array =  np.random.randint(0 , int(i), (int(i),int(i)))
array.astype(int)
file_name = 'array_1_'+i+'.txt'
file = open(file_name,'w')
file.write(i) 
file.write('\n')
np.savetxt(file, array, fmt='%i' , delimiter=' ')
file.close()

array =  np.random.randint(0 , int(i), (int(i),int(i)))
array.astype(int)
file_name = 'array_2_'+i+'.txt'
file = open(file_name,'w')
file.write(i) 
file.write('\n')
np.savetxt(file, array, fmt='%i' , delimiter=' ')
file.close()

