#include<stdio.h>
#include<math.h>

//Radix Sort


int getMax(int arr[],int n){
	int max=arr[0];
	int i;
	for(i=0;i<n;i++){
		if(arr[i]>=max){
			max=arr[i];
		}
	}

	
	return max;
}
void radixSort(int arr[], int n) 
{ 
    int exp;
    int m = getMax(arr, n); 
  
    for (exp = 1; m/exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
} 
void countSort(int arr[],int n,int exp){
	
	int i,j;
	
	int array[10]={0};
	int array2[n];
	
	for (i = 0; i < n; i++) 
        array[ (arr[i]/exp)%10 ]++; 
	
	for (i = 1; i < 10; i++) 
        array[i] += array[i - 1]; 
	for(j=n-1;j>=0;j--){
	    array2[array[(arr[j]/exp)%10]-1]=arr[j];
	    array[(arr[j]/exp)%10]--;
	    }

	
	for (i = 0; i < n; i++) 
        arr[i] = array2[i]; 

	
	
}
	
int main(){
	
	int arr[]={170,45,75,90,2,24,802,66};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	radixSort(arr,n);
	
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	
	
	
	
	return 0;
}
