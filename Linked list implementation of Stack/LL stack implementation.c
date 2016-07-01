#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void push(int **stackRef,int x);
int pop(int **stackRef);
int top(int *stack);void isEmpty(int *stack);
void printStack(int *stack);
void isEmpty(int *stack);

struct node{
	int data;
	struct node *next;
};

int main(int argc, char *argv[]) {
	
	struct node *stack;
	stack = NULL;
	
	printf("\n");
	
	isEmpty(stack);


	printf("PUSH : \n");
	push(&stack,1);
	push(&stack,2);
	push(&stack,3);
	push(&stack,4);
	push(&stack,5);
			
	printStack(stack);
	
	printf("TOP : \n");	
	printf("The element at the Top of Stack is %d\n", top(stack));
	printf("\n");
	
	printf("POP : \n");
	int temp = pop(&stack);
	
	printf("The element at the Top of Stack i.e %d is Poped from the Stack\n", temp);
	printf("\n");
	
	printStack(stack);

	printf("\n");
	
	printf("ISEMPTY : \n");
	isEmpty(stack);

	return 0;
}


void push(int **stackRef,int x){
	
	struct node *temp;
	
	temp = (int*)malloc(sizeof(struct node));
	
	temp->data = x;
	temp->next = *stackRef;
	*stackRef = temp;	
	
}

int pop(int **stackRef){


	struct node *temp = *stackRef;
	int data;
	
	if(*stackRef == NULL)
		printf("The Stack is Empty!\n");
		return;
	else{
		
		*stackRef = temp->next;
		data = temp->data;
		free(temp);
		return data;
	}


}

int top(int *stack){
	return *stack->data;
}

void isEmpty(int *stack){
	struct node *temp = stack;
	
	if(temp == NULL)
		printf("The Stack is Empty\n");
	else
		printf("The Stack is not Empty\n");
	
}
void printStack(int *top){
	
	struct node *temp = top;
	printf("\n");
	
	if(temp == NULL)
		printf("The Stack is Empty\n");
	else{
		while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	
	printf("\n");
		
	}
	
}
