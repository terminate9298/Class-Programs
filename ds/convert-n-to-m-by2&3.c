#include<stdio.h>
int minOperations(int n, int m) 
{ 
	if (m % n != 0) 
		return -1; 
	int t1 = 0; 
	int q = m / n; 
	while (q % 2 == 0) { 
		q = q / 2; 
		t1++; 
	} 
	while (q % 3 == 0) { 
		q = q / 3; 
		t1++; 
	} 
	if (q == 1) 
		return t1; 

	return -1; 
} 

int main() 
{  	
	int n ,m;
	printf("Enter The Value of n and m \n");
	scanf("%d %d",&n,&m);
	int value = minOperations(n, m); 
	printf("Minimun Value To Convert n To m is \t %d\n",value);
	return 0; 
} 
