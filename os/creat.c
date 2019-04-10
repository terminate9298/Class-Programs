#include<stdio.h>
void main(){
	int id = creat("file1.txt",0);
	if(id == -1){
		printf("cannot create file\n");
	}else{
		printf("File created\n");
	}
}
