#include <iostream>
#include <stdlib.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	 
 int main(int argc, char** argv)
{
	 printf("Write the no of elements \t:\t");
	 int n;
	 scanf("%d",&n);
	
	 int tree[n] ;		//can use given-2 elements;
	 int s = n/2;
	 
	 int at=1;
	 int a,b,j;
	 int L,R,P;
	 
	 printf("write the root value\t:\t");
	 scanf("%d",&a);
	 tree[1] = a;
	 
	 for(int i=1;i<s;i++)
	{
		 L = 2*i;
		 R = (2*i)+1;
		 P = (L/2);
		 
		 printf("---------\n");
		 // printf("i is %d\tL is %d\tR is %d\tP is %d\n",i,L,R,P);
		 printf("Write the left child \t:\t");
		 scanf("%d",&a);
		 tree[L] = a;
		 while(P>0)
		{
			 //printf("tree L = %d \ttree P = %d\n",tree[L],tree[P]);
		 	 if(tree[L]<tree[P])
			{
		 		 int tmp = tree[L];
		 		 tree[L] = tree[P];
		 		 tree[P] = tmp;
			}
			 else
			{
				 break;
			}
			 //printf("tree L = %d \ttree P = %d\n",tree[L],tree[P]);
			 P--;
		}
		 
			 P = (R/2);
			 // printf("i is %d\tL is %d\tR is %d\tP is %d\n",i,L,R,P);
			 printf("Write the Right child\t:\t");
			 scanf("%d",&b);
			 tree[R] = b;
			 while(P>0)
			{
		 		 // printf("tree R = %d \ttree P = %d\n",tree[R],tree[P]);
				 if(tree[R]<tree[P])
				{
		 			 int tmp = tree[R];
		 			 tree[R] = tree[P];
		 			 tree[P] = tmp;
				}
				 else
				{
					 break;
				}
				 //printf("tree R = %d \ttree P = %d\n",tree[R],tree[P]);
			 P--;
		 	}
	}
	  
	 for(int i=0;i<10;i++)
	{
		 printf("%d\t:\t%d\n",i,tree[i]);
	}
	 return 0;
}
