#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int partition(int arr[], int min, int max);
void quickSort(int arr[], int min, int max);
void swap(int *a, int *b);


int main(int argc, char *argv[]) {
	
	
	int n;
	
	printf("Enter the Size of Array: ");
	scanf("%d",&n);
	
	printf("\n");
	
	int arr[n],i;
	
	printf("Enter the Elements of Array to be Sorted: ");
	
	for(i=0; i<n; i++){
		
		scanf("%d",&arr[i]);
		
	}
	
	printf("\nSorting Array in Ascending Order........");
	
	quickSort(arr, 0, n-1);
	
	printf("\n\nThe Sorted Array is: \n");
	for(i=0; i<n; i++)
		printf("%d ",arr[i]);

	
	return 0;
}

int partition(int arr[], int min, int max){
	
	int i, pivot = arr[max];
	int pIndex = min;
	
	for(i=min ; i<max; i++){
		
		if(arr[i] <= pivot){
			
			swap(&arr[i], &arr[pIndex]);
			pIndex++;
		}
	}
	swap(&arr[pIndex], &arr[max]);
	return pIndex;	
	
}

void quickSort(int arr[], int min, int max){
	
	int pIndex;
	
	if(min < max){
		
		pIndex = partition(arr, min, max);
		
		quickSort(arr, min, pIndex-1);
		
		quickSort(arr, pIndex+1, max);
		
	}
}

void swap(int *a, int *b){
	
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;	
}

