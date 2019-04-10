#include<stdio.h>
//#include<sys/types.h>
//#include<sys/wait.h>
#include<unistd.h>

int main(){
	int pid;
	pid = fork();
	if(pid>0){
		sleep(6);
		printf("This is parent\n");
	}else if(pid == 0){
		sleep(2);
		printf("This is child\n");
	}else{
		printf("Process creation failed");
	}
}
