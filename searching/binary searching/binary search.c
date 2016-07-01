#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void sort(int *arr, int n);
int binarySearch(int arr[], int n, int x, int min, int max);

int main(int argc, char *argv[]) {
	
	
	int n, i, x, index;
	
	printf("Enter the size of the Array: ");
	scanf("%d",&n);
	
	printf("\n");
	int arr[n];
	
	printf("Enter the Elements of the Array: ");
	for(i=0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	
	printf("\n");
	
	
	sort(arr,n);
	
	printf("\n\nThe Sorted Array is: \n");
	for(i=0; i<n; i++)
		printf("%d ",arr[i]);

	printf("\n\nEnter the Element to Search in the Array:");
	scanf("%d",&x);
	printf("\n");
	

	index = binarySearch(&arr[0], n, x, 0, n-1);
	
	
	printf("\n\nThe Element is present at index %d", index);
	return 0;
}

void sort(int *arr, int n){
	
	int j, k, temp, flag;
	
	printf("\nSorting Array in Ascending Order........");
	
	for(j=0; j<n-1; j++){
		
		for(k=0; k<n-1-j; k++){
			
			flag = 0;
							
			if(arr[k]>arr[k+1]){
				temp = arr[k];
				arr[k] = arr[k+1];
				arr[k+1] = temp;
				flag = 1;
			}
		}
		
		if(flag==0)
			break;
				

	}
	
}

int binarySearch(int arr[], int n, int x, int min, int max){
	
	int middle;
			
		middle = (min+max)/2;
		
		if(x == arr[middle])
			return middle;
		else if(x < arr[middle]){
			return binarySearch(arr, n, x, min, middle - 1);
		}
		else if(x > arr[middle]){
			return binarySearch(arr, n, x, middle + 1, max);
		}
		
	
}
