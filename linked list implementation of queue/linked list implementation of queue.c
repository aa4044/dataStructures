#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


struct node{
	int data;
	struct node *next;
	
};

int main(int argc, char *argv[]) {

	struct node *f, *r;
	f = r = NULL;
	int data;
	
	
	
	printf("\n");
	
	isEmpty(f);


	printf("ENQUEUE : \n");
	enqueue(&f, &r, 1);
	enqueue(&f, &r,2);
	enqueue(&f, &r,3);
	enqueue(&f, &r,4);
	enqueue(&f, &r,5);
	enqueue(&f, &r,6);		
	printQueue(f);
	
	printf("PEAK : \n");	
	printf("The element at the Front of Queue is %d\n", peak(f));
	printf("\n");
	
	printf("DEQUEUE : \n");
	int temp = dequeue(&f, &r);
	
 	printf("The element at the Front of Queue i.e %d is Dequeued from the queue\n", temp);
	printf("\n");
	
	printQueue(f);
	
	printf("\n");
	
	printf("ISEMPTY : \n");
	isEmpty(f);
	return 0;
}

enqueue(struct node **f,struct node **r, int num){
	
	struct node *temp = malloc(sizeof(struct node));
	temp->data = num;
	temp->next = NULL;
	
	if(*f == NULL){
		*f = temp;
	}else{
		(*r)->next = temp;
	}
	
	*r = temp;
}

int dequeue(struct node **f, struct node **r){
	
	struct node *q;
	int data;
	
	if(*f == NULL){
		printf("The Queue is Empty");
	}else{
		
		q = *f;
		data = q->data;
		*f = q->next;
		free(q);

	if(*f == NULL){
		*r = NULL;
	}
	
	return data;
	}
	
}

int peak(struct node *f){
	
	int data = f->data;
	return data;
}

isEmpty(struct node *f){
	
	if(f == NULL)
		printf("The Queue is Empty\n");
	else
		printf("The Queue is not Empty");
}

printQueue(struct node *f){
	
	struct node *temp = f;
	
	while(temp != NULL){
		
		printf("%d ", temp->data);
		
		temp = temp->next;
	}
}

