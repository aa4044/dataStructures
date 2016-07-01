#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void enqueue(int *queue, int n,int x);
int dequeue(int *queue,int n);
int peek(int *queue,int n);
void isEmpty(int *queue, int n);
void printQueue(int *queue, int n);

int front = -1;
int rear = -1;
int main(int argc, char *argv[]) {

	int n, temp;
	
	printf("Enter the size of Queue: ");
	scanf("%d", &n);
	printf("\n");
	
	int queue[n],i;
	
	for(i=0; i<n; i++)
		queue[i] = 0;

	printf("\n");
	
	isEmpty(queue, n);


	printf("ENQUEUE : \n");
	enqueue(queue,n,1);
	enqueue(queue,n,2);
	enqueue(queue,n,3);
	enqueue(queue,n,4);
	enqueue(queue,n,5);
	enqueue(queue,n,6);		
	printQueue(queue,n);
	
	printf("PEAK : \n");	
	printf("The element at the Top of queue is %d\n", peak(queue,n));
	printf("\n");
	
	printf("DEQUEUE : \n");
	temp = dequeue(queue, n);
	
	printf("The element at the Front of Queue i.e %d is Dequeued from the queue\n", temp);
	printf("\n");
	
	printQueue(queue,n);
	
	printf("\n");
	
	printf("ISEMPTY : \n");
	isEmpty(queue, n);
	return 0;
}

void enqueue(int *queue, int n, int x){
	
	if(rear == n-1){
		printf("Queue is Full\n");
		return;
	}else{
		
		if(front == -1)
			front = 0;
			
		rare++;
		queue[rear] = x;	
	}
}

int dequeue(int *queue, int n){
	
	int data;
	
	if(rare == -1){
		printf("Queue is Empty\n");
		return;
	}else{
		
		data = queue[front];
		queue[front] = 0;
		front++;
		
		return data;	
	}
	
}

int peak(int *queue, int n){
	if(rare == -1){
		printf("Queue is Empty\n");
		return;
	}else{
		return queue[front];
	}
}
	

void isEmpty(int *queue, int n){
	if(rare == -1)
		printf("Queue is Empty\n");
	else
		printf("Queue is not Empty\n");
		
}

void printQueue(int *queue, int n){
	int i;
	if(rare == -1)
		printf("Queue is Empty\n");
	else{
		printf("queue: ");
		for(i=front; i<n; i++){
		printf("%d ", queue[i]);
		}		
		printf("\n");
	}

}

