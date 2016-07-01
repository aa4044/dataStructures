#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int hashFunc(int key);
int table_size;

int main(int argc, char *argv[]) {


	int n, i, key;
	char ch = 'y';
	
	printf("Enter the Size of Hash Table:");
	scanf("%d",&table_size);
	printf("\n");
	
	int hashTab[table_size];
	
	for(i=0; i<table_size; i++)
		hashTab[i] = 0;
		
	do{
	
	printf("Enter Element to Hash in The table: ");
	scanf("%d", &key);

	hashTab[hashFunc(key)] = key;
		
	printf("Do You Want to Hash Another Value: ");
	fflush(stdin);
	ch = getchar();
	fflush(stdin);
	
	}while(ch == 'y' || ch == 'Y');

	
	printf("HashTable: ");
	for(i=0; i<table_size; i++)
		printf("%d ", hashTab[i]);
	
	printf("\n\nEnter an Element to Search in Hash Table: ");
	scanf("%d",&key);
	printf("\n");
		
	i = hashFunc(key);
	if(key == hashTab[hashFunc(key)])
	printf("\nThe element %d is at %d index of HashTable", key, i);	
	else
	printf("\nNot Present in Hash Table");
	return 0;
}

int hashFunc(int key){
	
	int hashValue;
	
	hashValue = key % table_size;
	
	return hashValue;
}


