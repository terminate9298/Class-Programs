#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
void main(int argc,char *argv[]){
	DIR *dp;
	struct dirent *dirp;
	if(argc<2){
		printf("Not enough argument");
		exit(1);
	}
	if((dp = opendir(argv[1])) == NULL){
		printf("Cannot open file");
		exit(1);
	}
	while((dirp=readdir(dp)) != NULL){
		printf("%s\n",dirp->d_name);
	}
}
