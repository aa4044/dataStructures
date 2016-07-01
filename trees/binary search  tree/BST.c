#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//creating a structure data type for binary search tree
struct node{
	
	int data;
	struct node *left; // address of left child
	struct node *right; // address of right child
};


void insert(struct node **ref, int data);
int search(struct node *root, int data);
void inOrder(struct node *root);
void postOrder(struct node *root);
void preOrder(struct node *root);
int height(struct node *root);
struct node* delete(struct node *root, int num);
struct node* findMin(struct node *root);
struct node* findMax(struct node *root);



int main(int argc, char *argv[]) {

	struct node *bst; // creating a node pointer to store the root address of bst
	
	bst = NULL; //empty tree
	
	int i, num;
	
	printf("Enter the Number of Nodes you want to Insert in the Tree");

	scanf("%d",&i);
	int j;
	for(j = i; i>=1; i--){
		
		printf("Enter the data: ");
		scanf("%d", &num);
		printf("\n");
		
		insert(&bst, num);
		
	}
	
	
	inOrder(bst);
	printf("\n");
	preOrder(bst);
	printf("\n");
	postOrder(bst);
		
	printf("Enter a value to search in the tree: ");
	
	scanf("%d",&num);
	printf("\n");
	
	int tf = (search(bst , num)==1?printf("\nFound\n"):printf("\nNot Found\n"));
	
	printf("Minimum Value in the Tree is %d\n\n", findMin(bst)->data);
	printf("Maximum Value in the Tree is %d\n\n", findMax(bst)->data);
	
	printf("Enter a value to delete from the tree: ");
	scanf("%d",&num);
	bst = delete(bst, num);
		
	inOrder(bst);	
	return 0;
}

void insert(struct node **ref, int data){
	
	//this if block will execute if the ref is NULL, there are two possible cases
	//1. the tree is empty, this will simply add a new node in the tree
	//2. if block is executed after recursion from the below else block
	
	
	if(*ref==NULL){
		
		*ref = malloc(sizeof(struct node));
		
		(*ref)->left = NULL;
		(*ref)->data = data;
		(*ref)->right = NULL;
		
		return;
	}else{
		
		if(data <= (*ref)->data)
			insert(&((*ref)->left),data);
		
		else if(data > (*ref)->data)
			insert(&((*ref)->right), data);
	}
	
	
	
}

int search(struct node *root, int data){
	
	if(root == NULL) return 0; 
	
	else if(root->data == data) return 1;
	
	else if(data <= root->data) search(root->left, data);
	
	else if(data > root->data) search(root->right, data);
}

void inOrder(struct node* r)
{
    if(r!=NULL){
        inOrder(r->left);
        printf("%d ", r->data);
        inOrder(r->right);
    }
}

void preOrder(struct node* r)
{
    if(r!=NULL){
        printf("%d ", r->data);
        preOrder(r->left);
        preOrder(r->right);
    }
}

void postOrder(struct node* r)
{
    if(r!=NULL){
        postOrder(r->left);
        postOrder(r->right);
        printf("%d ", r->data);

    }
}

struct node* delete(struct node *root, int num){
	
	if(root == NULL) return root;
	
		
	else if(num < root->data) root->left = delete(root->left, num);
	
	else if(num > root->data) root->right = delete(root->right, num);
	
	//root to be deleted is found
	else{ 
		
		
		if(root->left == NULL && root->right == NULL){

			free(root);			
			root = NULL;

		}

		else if(root->left == NULL){
			
			struct node *temp = root;
			
			root = root->right;
			
			free(temp);
		}		

		else if(root->right == NULL){
			
			struct node *temp = root;
			
			root = root->left;
			
			free(temp);
		}
		
		else if(root->left != NULL && root->right!=NULL){
			
			struct node *temp = findMin(root->right);
			
			root->data = temp->data;
			
			root->right = delete(root->right, temp->data);
		}
		
		return root;
	}
}

struct node* findMin(struct node *root){
	
	if(root == NULL){
		printf("The Tree is Empty\n");
		return NULL;
	}
	
	while(root->left != NULL){
		
		root = root->left;
	}
	
	return root;
}

struct node* findMax(struct node *root){
	
	if(root == NULL){
		printf("The Tree is Empty\n");
		return NULL;
	}
	
	while(root->right != NULL){
		
		root = root->right;
	}
	
	return root;
}
