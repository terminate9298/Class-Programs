#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main(){
	int pid = fork();
	if(pid <0){printf("cannot create processs");exit(1);}
	else if(pid == 0){  
	execlp("/bin/ls","ls",NULL);
	}
else{printf("This is parent");}
	//printf("program ending\n");
}
