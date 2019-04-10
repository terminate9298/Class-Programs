#include<stdio.h>
void main(){
	char str[100];
	FILE *fp;
	fp =fopen("file.txt","r");
	while(!feof(fp)){
		fscanf(fp,"%s",str);
		printf("%s ",str);
	}
	printf("\n");
	fclose(fp);
}
