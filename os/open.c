#include<stdio.h> 
#include<fcntl.h> 

int main() 
{       
    int fd = open("temp.txt", O_RDONLY | O_CREAT);  
      
    printf("fd = %d\n", fd); 
    if (fd ==-1){      
        perror("Program");                  
    } 
    return 0; 
} 
