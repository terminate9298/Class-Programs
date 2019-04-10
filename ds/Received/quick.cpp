#include<iostream>
using namespace std; 
 int partition (int *a, int low, int high) 
{ 
	int pivot = a[high],temp; 
	int i = (low - 1); 

	for (int j = low; j <= high- 1; j++) 
	{ 
	
		if (a[j] <= pivot) 
		{  
			
			i++; 
		  
			  temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		} 
	} 
	temp=a[i + 1];
	 a[i+1]=a[high];
	 a[high]=temp; 
	return (i + 1); 
} 

void quickSort(int *a, int low, int high) 
{ 
	if (low < high) 
	{ 
		int pi = partition(a, low, high); 
     	quickSort(a, low, pi - 1); 
		quickSort(a, pi + 1, high); 
	} 
} 

 

int main() 
{ int i,n;
    cout<<"enter the size of array= ";
    cin>>n;
    int a[n];
    cout<<"enter the array\n";
    for(i=0;i<n;i++)
      cin>>a[i];
      
	quickSort(a, 0, n-1); 
	 
	for(i=0;i<n;i++)
	  cout<<a[i]<<" ";
	return 0; 
} 

