#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void push(int *stack, int n,int x);
int pop(int *stack,int n);
int top(int *stack,int n);
void isEmpty(int *stack, int n);
void printStack(int *stack, int n);

int top1 = -1;

int main(int argc, char *argv[]) {

	int n, temp;
	
	printf("Enter the size of Stack: ");
	scanf("%d", &n);
	printf("\n");
	
	int stack[n],i;
	
	for(i=0; i<n; i++)
		stack[i] = 0;

	printf("\n");
	
	isEmpty(stack, n);


	printf("PUSH : \n");
	push(stack,n,1);
	push(stack,n,2);
	push(stack,n,3);
	push(stack,n,4);
	push(stack,n,5);
	push(stack,n,6);		
	printStack(stack,n);
	
	printf("TOP : \n");	
	printf("The element at the Top of Stack is %d\n", top(stack,n));
	printf("\n");
	
	printf("POP : \n");
	temp = pop(stack, n);
	
	printf("The element at the Top of Stack i.e %d is Poped from the Stack\n", temp);
	printf("\n");
	
	printStack(stack,n);
	
	printf("\n");
	
	printf("ISEMPTY : \n");
	isEmpty(stack, n);
	return 0;
}

void push(int *stack, int n, int x){

	if(top1 == n-1){
		printf("Stack is Full\n");
			return;
	}
	
	top1++;
	stack[top1] = x;

}

int pop(int *stack, int n){
	
	int temp = stack[top1];
	stack[top1] = 0;
	top1--;
	
	return temp;
}

int top(int *stack, int n){
	return stack[top1];
}

void isEmpty(int *stack, int n){
	if(top1==-1)
		printf("Stack is Empty\n");
	else
		printf("Stack is not Empty\n");
		
}

void printStack(int *stack, int n){
	int i;
	if(top1==-1)
		printf("Stack is Empty\n");
	else{
		printf("Stack: ");
		for(i=0; i<n; i++){
		printf("%d ", stack[i]);
		}		
		printf("\n");
	}

}
