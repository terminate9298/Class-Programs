#include<stdio.h>
int arr[5];
int f=-1, r=-1;
int dequeue(){
	if(r==f){
		printf("\n Sorry Can't dequeue");
		return 0;
	}
	f++;
	if(f==5){
		f=0;
	}
	printf("\n The dequeued Up Number is %d \n",arr[f]);
	printf("\n value of f is  %d \n",f);
	return 1;
}
int Insert(){
	r++;
	if(r==5){
		if(f==-1){
			printf("Cannot Insert");
			return 1;
		}
		else{
			r=0;
		}
	}
	if(r==f){
		printf("Queue Full");
		r--;
		return 1;
	}
	printf("\nEnter a Number");
	scanf("%d",&arr[r]);
	return 1;
}
int display(){
	if(r==f){
		printf("Sorry Can't dequeue \n");
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
	if(n==1)
		dequeue();
	if(n==2)
		Insert();
	if(n==3)
		display();
	if(n==4)
		return 1;
}
}