#include<stdio.h>
int partition(int a[]  , int low , int high)
{
	int pivot = a[high];
	int i = (low-1);
	int t;
	for (int j=low;j<high-1;j++){
		if(a[j]<=pivot){
			i++;
			t= a[i];
			a[i] = a[j];
			a[j] = t;

		}
	}
	t = a[i+1];
	a[i+1] = a[high];
	a[high] = t;
	return (i+1);
}
int quicksort(int a[] , int low , int high) {
	if(low < high){
		int p = partition(a , low , high) ;

		quicksort(a , low , p-1);
		quicksort(a , p+1 , high );
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
	// for (int i=0;i<n-1;i++){
	// 	for (int j=0;j<n-i-1;j++){
	// 		if(a[j+1]<a[j]){
	// 			int t = a[j+1];
	// 			a[j+1]= a[j];
	// 			a[j] = t;
	// 		}
	// 	}
	// }
	quicksort(a,0,n-1);
	for (int i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}