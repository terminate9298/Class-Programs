#include<stdio.h>
int arr[100];
int f=-1, r=-1;
int Dequeue(){
	if(r==f){
		printf("\n Sorry Can't Dequeue");
		return 0;
	}
	f++;
	printf("\n The Dequeued Number is %d \n",arr[f]);
	return 1;

}
int insert(){
	printf("\nEnter a Number");
	r++;
	scanf("%d",&arr[r]);
	
	return 1;
}
int display(){
	if(r==f){
		printf("Sorry Can't Dequeue \n");
		return 0;
	}
	
	printf("\nThe Display Number is %d \n",arr[f+1]);
	return 1;
}
int main(){

int n=0;

while(n!=4){
	printf("Enter Your Choice  \n1->\tDequeue  \n2->\tInsert  \n3->\tDISPLAY  \n4->\tEXIT \n");
	scanf("%d",&n);
	if(n==1){
		Dequeue();
	}
	if(n==2){
		insert();
	}
	if(n==3){
		display();
	}
	if(n==4){
		return 1;
	}
}
}