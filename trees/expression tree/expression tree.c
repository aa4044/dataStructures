#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//creating a structure data type for binary search tree
struct node{
	
	char data;
	struct node *left; // address of left child
	struct node *right; // address of right child
};

//a expression tree is not a binary search tree so functions of bst like search delete find min find max etc will not work in expression trees
//tree stuff
struct node* createNode(char data);
void inOrder(struct node *root);
void postOrder(struct node *root);
void preOrder(struct node *root);


//stack stuff
void push(struct node* x);
struct node * pop();
struct node * top();
int isOpt(char ch);

int top1 = -1;
struct node * stack[100];


int main(int argc, char *argv[]) {

	struct node *bet; // creating a node pointer to store the root address of bst
	
	bet = NULL; //empty tree
	
	int i;
	
	
	printf("Enter the Number of Nodes you want to Insert in the Tree: ");
	
	scanf("%d",&i);
	printf("\n");
	char ch[i];
	
	int j;
	for(j = i; i>=1; i--){
		
		printf("Enter the data: ");
		fflush(stdin);
		ch[i] = getchar();
		fflush(stdin);
			
		printf("\n");

		if(isOpt(ch[i]) == 1){
			
			bet = createNode(ch[i]);
			bet->right = pop();
			bet->left = pop();
			
			push(bet);
			
		}else{
			push(createNode(ch[i]));
		}
	}
	
	bet = pop();
	
	
	printf("Inorder Traversal: LDR\n");
	inOrder(bet);
	printf("\nPreorder Traversal: DLR\n");
	preOrder(bet);
	printf("\nPostorder Traversal: LRD\n");
	postOrder(bet);
	
	return 0;
}

struct node* createNode(char data){
		
		struct node *temp = malloc(sizeof(struct node));
		
		(temp)->left = NULL;
		(temp)->data = data;
		(temp)->right = NULL;
		
		return  temp;
}


void inOrder(struct node* r)
{
    if(r!=NULL){
        inOrder(r->left);
        printf("%c ", r->data);
        inOrder(r->right);
    }
}

void preOrder(struct node* r)
{
    if(r!=NULL){
        printf("%c ", r->data);
        preOrder(r->left);
        preOrder(r->right);
    }
}

void postOrder(struct node* r)
{
    if(r!=NULL){
        postOrder(r->left);
      postOrder(r->right);
        printf("%c ", r->data);

    }
}



//stack functions
int isOpt(char ch){
	
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
	return 1;
	else
	return 0;
}

void push(struct node* x){
	
	top1++;
	stack[top1] = x;

}

struct node * pop(){
	
	struct node *temp = stack[top1];
	stack[top1] = 0;
	top1--;
	
	return temp;
}

struct node * top(){
	return stack[top1];
}

