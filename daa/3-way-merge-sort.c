#include<stdlib.h> 
#include<stdio.h> 
void printArray(int A[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
} 
void merge(int DA[], int low ,int mid1 , int mid2 , int high , int A[]){
	int i = low, j = mid1, k = mid2, l = low;
	while ((i < mid1) && (j < mid2) && (k < high)) 
        { 
            if ( DA[i] < DA[j] ) 
            { 
                if (DA[i] < DA[k]) 
                    A[l++] = DA[i++];  
                else
                    A[l++] = DA[k++]; 
            } 
            else
            { 
                if (DA[j] < DA[k]) 
                    A[l++] = DA[j++]; 
                else
                    A[l++] = DA[k++]; 
            } 
        }
    while ((i < mid1) && (j < mid2)) 
        { 
            if ( DA[i]< DA[j]) 
                A[l++] = DA[i++]; 
            else
                A[l++] = DA[j++]; 
        } 
    while ((j < mid2) && (k < high)) 
        { 
            if (DA[j] < DA[k]) 
                A[l++] = DA[j++]; 
  
            else
                A[l++] = DA[k++]; 
        } 
    while ((i < mid1) && (k < high)) 
        { 
            if (DA[i] < DA[k]) 
                A[l++] = DA[i++]; 
            else
                A[l++] = DA[k++]; 
        } 
    while (i < mid1) 
            A[l++] = DA[i++]; 
    while (j < mid2) 
            A[l++] = DA[j++]; 
  	while (k < high) 
            A[l++] = DA[k++]; 
}
void mergeSort3WayRec(int A[] , int low , int high, int DA[]){
	if(high-low < 2)
		return;
	int mid1 = low + ((high - low) / 3); 
    int mid2 = low + 2 * ((high - low) / 3) + 1; 
    mergeSort3WayRec(DA, low, mid1, A); 
    mergeSort3WayRec(DA, mid1, mid2, A); 
    mergeSort3WayRec(DA, mid2, high, A); 
    merge(DA , low , mid1 ,mid2 ,high , A);
}

void mergeSort3Way(int DA[],int arr_size){
	// int arr_size = sizeof(A)/sizeof(A[0]);
	int A[arr_size];
	for(int i=0;i<arr_size;i++){
		A[i] = DA[i];
	}
	mergeSort3WayRec(A , 0, arr_size , DA);
	for(int i=0;i<arr_size;i++){
		DA[i] = A[i];
	}
}

int main() 
{ 
	int arr[] = {12, 11, 13, 5, 6, 7}; 
	int arr_size = sizeof(arr)/sizeof(arr[0]); 

	printf("Given array is \n"); 
	printArray(arr, arr_size); 
    mergeSort3Way(arr,arr_size);
	//mergeSort(arr, 0, arr_size - 1); 

	printf("\nSorted array is \n"); 
	printArray(arr, arr_size); 
	return 0; 
} 

