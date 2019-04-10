#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>

int main() 
{
    //Creating child process
    int id = fork(); 

    if (id<0){
        printf("Cannot create process\n");
        exit(1);
    }
    //Child process
    else if (id==0){
        printf("This is child process with PID: %d\n", getpid());
    }
    //Parent process
    else{
        printf("This is parent process with PID: %d\n", getpid());
    }
    return 0;    
} 
