#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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
	
	printf("\n\nThe Sorted Array is: \n");
	for(i=0; i<n; i++)
		printf("%d ",arr[i]);
		
		
	return 0;
}
