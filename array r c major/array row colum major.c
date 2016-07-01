 #include <stdio.h>
 #include <stdlib.h>

 int main(void)
{
	 int i,j;
	 
	 int N;						//Will store total dimensions
	 printf("\nWrite the total no of dimensions\t");
	 scanf("%d",&N);
	 printf("Total Dimensions are %d\n",N);		//Confirm total dimensions
	
	 int *I = malloc(N*sizeof(int));				//Dynamic array to hold index of each Dimension
	 int *S = malloc(N*sizeof(int));				//Making a dynamic array to store Dimensions sizes 
	
	 for(i=0;i<N;i++)
	{
		 printf("Write the size of dimension %d\t",i+1);
		 scanf("%d",(S+i));			//Storing the size of each dimension
	}

	 printf("The given sizes are:\n");		//loop to confirm sizes
	 for(i=0;i<N;i++)
	{
		 printf("Of dimension %d is %d \n",i+1,*(S+i));	//Printing size againt dimension
	}

	 int tE=1;						//variable to store total no of element
	 for(i=0;i<N;i++)
	{
		 tE = tE * *(S+i);				//calculating total elements
	}

	 printf("\nIts mean total element are %d\n\n",tE);	//Printing total elements

	 int *array = malloc(tE*sizeof(int));				//FINALLY MAKING THE ARRAY TO HOLD ALL ELEMENTS

	 printf("Start writing elements ROW-MEASURE mode.\n");	//Elements must be added in Row-Measure form
	 for(i=0;i<tE;i++)
	{
		 printf("Write element count at place %d : ",i);
		 scanf("%d",(array+i));				//Storing elements on the array
	}

	 printf("\nIts mean the array\n");
	 for(i=0;i<tE;i++)
	{
		 printf("\t\t\tElement at %d location is %d\n",(array+i),*(array+i)); //again printing the elements to confirm
	}
	
	 int el, sm;					//Variables to determine Vale at given indexes
	 while(1)
	{
		 printf("\nWrite the index to go \n");
		 for(i=0;i<N;i++)
		{
			 printf("Of dimension %d ",i+1);
			 scanf("%d",(I+i));			//Storring the given dimension
			 if(*(I+i)>=*(S+i))			//If given dimension is greater then total Lenght
			{
				 printf("TOTAL CAPACITY IS %d, YOU ENTERED %d\n\n",*(S+i),*(I+i));
				 return;
			}		 
		}
/*
		 for(i=0;i<N;i++)
		{
			 printf("The index of dimensin %d is %d \n",i+1,*(I+i));//Confirming dimensions
		}
*/
		 el=0, sm=1;					//Setting el = 0 and sm = 1;

		 for(i=0;i<N;i++)
		{
			 for(j=i+1;j<N;j++)
			{
				 sm = sm * *(S+j);		//Multiplying the dimensions from i+j locatons
			}
			 el = el + *(I+i)*sm;			//Multyplying product of indexes with el
			 sm = 1;				//sm = 1 for next inner loop
		}

		 printf("\nYOU ARE AT %d\n",el);			//Printing the calculated adress
		 printf("AND THE VALUE IS %d\n\n",*(array+el));	//Printing the value in array at adress

		 for(i=0;i<tE;i++)
		{
			printf("value at %d is %d\n",(array+i),*(array+i));
		}	
	
		 printf("WRITE 0 TO EXIT , 1 TO CONTINUE\t");	//Exit | Continue
		 int ch ;					//ch to store choice
		 scanf("%d",&ch);				//asking user
		 if(ch==0)					//If choice is 0 exit;
		{
			 free(array);
		   	 free(I);
		   	 free(S);
			 return;
		}				
	 }
}
