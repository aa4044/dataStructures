#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void selectionSort(int *arr, int n);

int main(int argc, char *argv[]) {
	
	int n;
	
	printf("Enter the Size of Array: ");
	scanf("%d",&n);
	
	printf("\n");
	
	int arr[n], i, j, k, temp, flag;
	
	printf("Enter the Elements of Array to be Sorted: ");
	
	for(i=0; i<n; i++){
		
		scanf("%d",&arr[i]);
		
	}
	
	printf("\nSorting Array in Ascending Order........");
	
	selectionSort(arr, n);
	
	printf("\n\nThe Sorted Array is: \n");
	for(i=0; i<n; i++)
		printf("%d ",arr[i]);

	
	return 0;
}

void selectionSort(int *arr, int n){
	
	int iMin, i, j,temp;
	
	for(i=0; i<n-1; i++){
		
		iMin = i;
		
		for(j=i+1; j<n; j++){
			
			if(arr[iMin] > arr[j])
				iMin = j;
		}	
		
		{
			temp = arr[i];
			arr[i] = arr[iMin];
			arr[iMin] = temp;
		}
	}
}



