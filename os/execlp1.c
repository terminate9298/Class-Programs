#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int pid;
    pid = fork();

    if (pid == -1){
        perror("fork error");
        exit(1);
    }    
    else if (pid == 0){
        execlp("/bin/ls", "ls", NULL);
        printf("execlp executed by child\n");
    }
    else{
        printf("this is parent process\n");
    }
    return 0;
}

