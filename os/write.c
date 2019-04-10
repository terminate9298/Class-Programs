#include<stdio.h>
#include<stdlib.h>
void main(){
	char str[100];
	FILE *fp;
	printf("Enter string : ");
	gets(str);
	fp = fopen("file.txt","w+");
	fprintf(fp,"%s",str);
	
}
