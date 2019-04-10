#include<stdio.h>
int csort(int a[] , int n , int min , int max) {
	int t = max-min;
	int b[max-min+1];
	for(int i=0 ; i <= max-min ; i++){
		b[i]=0;
	}
	for(int i=0;i<n;i++){
		b[a[i]-min]++;
	}
	for(int i=1 ; i <= max-min ; i++){
		b[i]+=b[i-1];
	}
	int c[n];
	for(int i=0;i<n;i++){
		b[a[i]-min]--;
		c[b[a[i]-min]] = a[i];
	}
	// for(int i=0;i<= max-min;i++){
	// 	printf("%d\t",b[i]);
	// }
	for(int i=0;i<n;i++){
		printf("%d\t",c[i]);
	}

}

int main(){
	int n;
	printf("Enter a Number\n");
	scanf("%d",&n);
	int a[n];
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	//for min number
	int min=a[0];
	for (int i=1;i<n;i++){
		if(min>a[i])
			min=a[i];
	}
	int max=a[0];
	for (int i=1;i<n;i++){
		if(max<a[i])
			max=a[i];
	}
	csort(a,n,min,max);
	// for (int i=0;i<n;i++){
	// 	printf("%d\t",a[i]);
	// }
}