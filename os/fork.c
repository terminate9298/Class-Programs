#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	int pid;
	pid = fork();
	if(pid>0){
		printf("This is parent\n");
	}else if(pid == 0){
		printf("This is child\n");
	}else{
		printf("Process creation failed");
	}
}

