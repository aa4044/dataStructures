#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int n, i, j=0, k, num;
	float avg, sum = 0;
	char ch, ch1;
	
	printf("Enter the number of Students: ");
	scanf("%d",&n);
	
	printf("\n");
	
	int *ptr;
	
	ptr = (int*)malloc(n*sizeof(int));
	
	if(ptr==NULL){
	
		printf("ERROR! Memory Allocation failed.\n");
		return 1;
		
	}else{
		
		//printf("Enter the marks of %d students\n", n);
		
		for(i=0; i<n; i++){
		
			printf("Enter the marks of student # %d (Y/N) : ", i+1);
			fflush(stdin);
			scanf("%c",&ch);
			
			printf("\n");
		
			if(ch=='y'||ch=='Y'){
			printf("Marks: ");
			scanf("%d",ptr+i);
			sum += *(ptr+i);
			printf("\n");
			
			}else{
				j = i;
			
				ptr = realloc(ptr, (j)*sizeof(int));
				printf("Size of ptr after reallocation of memory  = %d\n", j*sizeof(int));

				break;
			}
			
			if(i==n-1){
				
				printf("Do you want to increase the number of students: (Y/N): ");
				fflush(stdin);
				scanf("%c",&ch1);
				
				printf("\n");
				
				

				if(ch1=='y' || ch1=='Y'){
				int add;
				printf("Enter the number of students you want to add: ");
				scanf("%d", &add);
				
				n = n + add;
				
				k= i+1;
			
										
				for(k ; k<n ; k++){
										
				printf("Enter the marks of student # %d (Y/N) : ", k+1);
				fflush(stdin);
				scanf("%c",&ch);
			
				printf("\n");
		
				if(ch=='y'||ch=='Y'){
				printf("Marks: ");
				scanf("%d",ptr+k);
				sum += *(ptr+k);
				printf("\n");
			
				}else{
				j = k;
			
				ptr = realloc(ptr, (j)*sizeof(int));
				printf("Size of ptr after reallocation of memory  = %d\n", j*sizeof(int));

				break;
				}
				}
				}
				
				break;
			}
			
						
		}
		
		if(j!=0){
		avg = sum/j;
		n = j;
		}
		else
		avg = sum/n;
		
		ptr[0] = 1000;
		printf("Marks: ");
		for(i=0; i<n; i++)
			printf(" %d ", *(ptr+i));
		
		
		printf("\n");
		printf("Sum of %d students is : %f\n",n,sum);
		printf("Average of %d students is : %f\n",n,avg);
		
		
	}
	
	
	
	return 0;
}
