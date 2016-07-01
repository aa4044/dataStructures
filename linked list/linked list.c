#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct node{
	int data;
	struct node *next;
};

int count(struct node *head); 
void addAtBeg(struct node **headRef, int num);
void append(struct node **head, int num);
void display(struct node *head);
void addAfterIndex(struct node *q, int index, int num);
void addAscending(struct node **headRef, int num);
void delete(struct node **headRef, int num);
void reverse(struct node **headRef);

int main(int argc, char *argv[]) {



	struct node *list;
	list = NULL;
	
	printf("EMPTY LINKED LIST\n");
	printf("NO OF ELEMENTS IN LIST %d \n", count(list));
	display(list);
	
	printf("________________________________________________________________________________");

	printf("append\n");	
	append(&list,2);
	append(&list,3);
	append(&list,4);

	printf("\nNO OF ELEMENTS IN LIST %d \n", count(list));
	display(list);
	
	printf("\n________________________________________________________________________________\n");		
	
	printf("addAtBeg\n");
	addAtBeg(&list,1);

	printf("\nNO OF ELEMENTS IN LIST %d \n", count(list));
	display(list);

	printf("\n________________________________________________________________________________\n");		
	
	printf("addAfterIndex\n");

	addAfterIndex(list, 2, 6);
	printf("\nNO OF ELEMENTS IN LIST %d \n", count(list));
	display(list);

	printf("\n________________________________________________________________________________\n");		

	printf("delete\n");
	delete(&list, 6);
	printf("\nNO OF ELEMENTS IN LIST %d \n", count(list));
	display(list);

	printf("\n________________________________________________________________________________\n");		

	printf("addAscending\n");
		
	addAscending(&list,-1);
	addAscending(&list,10);
	addAscending(&list,7);
	addAscending(&list,9);
	
	printf("\nNO OF ELEMENTS IN LIST %d \n", count(list));
	display(list);

	printf("\n________________________________________________________________________________\n");		

	printf("reverse\n");
		
	reverse(&list);
	display(list);
	

	return 0;
}


//function for counting total nodes in linked list, this is done by iterating the linked list till we encounter NULL
int count(struct node *head){
	
	struct node *current = head; //copying value of head in a local variable current, this current variable will be used to iterate the linked list
	int count = 0;
	
	while(current != NULL){ //we will not use the value of current later in the function so we can use current in the loop, it will become NULL in the end
		count++;
		current = current->next;	
	}
	
	return count;
}



//append function is used to add a node at the end of the linked list
//there are two cases in append function
//1. the list is empty
//2. the list is not empty
void append(struct node **headRef, int num){

	struct node *temp, *current = *headRef;
	
	temp = (int*)malloc(sizeof(struct node));
	
	if(current == NULL){
		*headRef = temp;
	}else{
		
		while(current->next != NULL){ //here we are using current->next because we have to use the value in current, otherwise current will be NULL
			current = current->next;
		}
		
		current->next = temp;
	}
	
	temp->data = num;
	temp->next = NULL;

	
/*	struct node *temp;
	temp = *headRef;
	
	if(*headRef==NULL){
		*headRef = (int*)malloc(sizeof(struct node));
		temp = *headRef;
		
	}else{
		
		while(temp->next != NULL)
			temp = temp->next;
		
		temp->next = (int*)malloc(sizeof(struct node));
		temp = temp->next; 	
	}
	
	temp->data = num;
	temp->next = NULL;
*/

}



//this funciton is used to add a node at the beganing of the linked list. in this funciton we will create a new node, save the address of first node in the next of this new node and after that we will save the address of this new node in head 
void addAtBeg(struct node **headRef, int num){
	
	struct node *temp = (int*)malloc(sizeof(struct node));
	
	temp->data = num;
	temp->next = *headRef;
	*headRef = temp;
}



//this function is used to add a node at the specified index in the list, this index works like that in array, 0 means after first node, 1 means after 2nd node, 2 means after 3rd node and so on
void addAfterIndex(struct node *q, int index, int num){
	//we can not use this function in case of empty list
	struct node *temp;
	int i;
	
	if(q==NULL){
        printf("List is Empty, Item can not be added at index %d\n", index);
	}else{
	
		for(i=0; i<index; i++){
			q = q->next;
		
		if(q == NULL){
			printf("There are less than %d elements in the list! \n", index);
			return;
		}
		}
	
		temp = (int*)malloc(sizeof(struct node));
	
		temp->data = num;
		temp->next = q->next;
		q->next = temp;
	
	}
		
 
}


//this display function is used to print the linked list
void display(struct node *head){
	
	printf("\n");
	
	struct node *temp = head;
	
	while(temp != NULL){  //we will not use the value of temp later in the function so we can use temp in the loop, it will become NULL in the end
		printf("%d ", temp->data);
		temp = temp->next;
	}
}


//delete a node from the linked list, in this function we will pass a value "num" , if number is a value at a node , that node will be deleted
void delete(struct node **headRef, int num)
{
    // Store head node
    struct node *temp = *headRef, *prev;
 
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == num)
    {
        *headRef = temp->next;   // Changed head
        free(temp);               // free old head
        return;
    }
 
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != num)
    {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL){
    	printf("\nElement Not found!\n");
    	return;
	}
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    free(temp);  // Free memory
}



//this function will add a new node in a sorted way, i.e all nodes added through this funcitons will be added in ascending order
void addAscending(struct node **headRef, int num){
	
	struct node *temp, *current = *headRef;
	
	
	temp = (int*)malloc(sizeof(struct node));
	temp->data = num;
	
   
    if (*headRef == NULL || (*headRef)->data > num)
    {		
		temp->next = *headRef;
		*headRef = temp;
	}	
    else
    {
		while(current!=NULL && current->data<=num){
			
							
			if(current->next==NULL || current->next->data > num){
				temp->next = current->next;
				current->next = temp;
				return;
			
			}
			current = current->next;
		}
		

    }

}


// this fucntion will reverse the linked list
void reverse(struct node **headRef){
	
	struct node *prev, *current, *next;
	current = *headRef;
	prev = NULL;
	
	while(current!=NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*headRef = prev;
}
