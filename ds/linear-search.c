#include<stdio.h>
int main(){
	int n;
	printf("Enter a Number\n");
	scanf("%d",&n);
	int a[n];
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int s;
	printf("Enter a number to search");
	scanf("%d",&s);	
	for (int i=0;i<n-1;i++){
		if(a[i]==s){
			printf("The Number is found at %d Location\n",i+1);
			return 0;
		}
	}
	printf("The Number is not found\n");
}