#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
	int dim, *S, *I, *array, size=1, i;
	char ch='y';
	
	printf("Enter the No. of Dimensions of the Array: ");
	scanf("%d",&dim);
	printf("\n");
	
	S = (int*)malloc(dim*sizeof(int));
	
	printf("Now Enter the Dimensions of Array: \n");
	for(i=0; i<dim; i++){
		printf("D%d: ", i+1);
		scanf("%d", S+i);
		printf("\n");
	}
	
	for(i=0; i<dim; i++){
		size *= *(S+i);
	}
	
	printf("Total No. of Elements in the Array is: %d\n", size);
	
	array = (int*)malloc(size*sizeof(int));
	
	printf("Now Enter the Value of Each element of the Array: \n");
	
	for(i=0; i<size; i++){
		
		printf("array[%d]: ", i);
		scanf("%d", array+i);
		printf("\n");
	}
	
	printf("You Entered the Following Array Elements: \n");
	
	for(i=0; i<size; i++){
		
		printf("array[%d]: %d", i, *(array+i));
		printf("\n");
	}
	
	I = (int*)malloc(dim*sizeof(int));
		
	while(ch=='y' || ch=='Y'){
		
		printf("\n\nEnter the Indexes of Array Element You want to Acces: \n");
			
		for(i=0; i<dim; i++){
			
			printf("I%d: ",i);
			scanf("%d", I+i );
			printf("\n");
			
			if(*(i+I) >= *(S+i)){
				printf("Error: The value of Index can not be greater than the Dimension!!!\n");
				continue;
			}
		}
		
		int sum = 0, pS = 1, j;
		
		for(i=0; i<dim; i++){
			
			for(j=i+1; j<dim; j++){
				
				pS *= *(S+j);
			}
			
			sum += *(I+i) * pS;
			pS = 1;	
			
		}
	
		printf("You are at Index %d elements from the Base Address\n", sum);
		
		printf("The Value at Index is %d\n", *(array+sum));
		
		printf("Do you want to Continue? : ");
		fflush(stdin);
		ch = getchar();
		
	}
	
	if(ch=='N' || ch=='n'){
		
		free(S);
		free(I);
		free(array);
		return;
	}
	
	
	
	return 0;
}
