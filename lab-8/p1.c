#include<stdio.h>
#include<stdlib.h>
struct Node{
	int info;
	struct Node* link;
};
struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->info = data;
	newNode->link = NULL;
	return newNode;
}

void displayNode(struct Node* node){
	printf("data : %d",node->info);
}
void main(){
	int data;
	printf("Enter node data : ");
	scanf("%d",&data);
	struct Node* newNode = createNode(data);
	displayNode(newNode);
}
