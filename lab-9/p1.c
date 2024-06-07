#include<stdio.h>
#include<stdlib.h>
struct Node{
	int info;
	struct Node* link;
};
void InsertAtBeg(int data, struct Node** first) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->info = data;
    newNode->link = *first;
    *first = newNode;
}
void insertBeforeNode(int data,struct Node** first,int n){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->info = data;
    struct Node* ptr = *first;
    struct Node* preptr = *first;
    while(ptr->info != n){
    	preptr = ptr;
    	ptr = ptr->link;
	}
	preptr->link = newNode;
	newNode->link = ptr;
}
void insertAfterNode(int data,struct Node** first,int n){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->info = data;
    struct Node* ptr = *first;
    struct Node* preptr = *first;
    while(preptr->info != n){
    	preptr = ptr;
    	ptr = ptr->link;
	}
	preptr->link = newNode;
	newNode->link = ptr;
}
void deleteSpec(struct Node** first,int n){
	if (*first == NULL) {
        printf("The list is empty.\n");
        return;
    }	
    struct Node* ptr = *first;
    struct Node* preptr = *first;
    if ((*first)->info == n) {
        *first = (*first)->link;
        free(ptr);
        return;
    }
    while(ptr->info != n){
    	preptr = ptr;
    	ptr = ptr->link;
	}
	if (ptr == NULL) {
        printf("Node with value %d not found.\n", n);
        return;
    }
	preptr->link = ptr->link;
	free(ptr);
}

void display(struct Node* first){
	if (first == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* ptr = first;
    while (ptr != NULL) {
        printf("%d -> ", ptr->info);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

void main(){
	struct Node* first = NULL;
	int choice=-1,x,n;
	do{
		printf("\n2.insert at beg\n2.Insert before given node\n3.Insert after given node\n4.Delete specific\n5.Display all nodes.\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("enter data to be insert : ");
		 		scanf("%d",&x);
		 		InsertAtBeg(x,&first);
		 		break;
		 	case 2:
		 		printf("enter data to be insert : ");
		 		scanf("%d",&x);
		 		printf("enter node before insert : ");
		 		scanf("%d",&n);
		 		insertBeforeNode(x,&first,n);
		 		break;
		 	case 3:
		 		printf("enter data to be insert : ");
		 		scanf("%d",&x);
		 		printf("enter node after insert : ");
		 		scanf("%d",&n);
		 		insertAfterNode(x,&first,n);
		 		break;
		 	case 4:
		 		printf("enter node to be delete : ");
		 		scanf("%d",&n);
		 		deleteSpec(&first,n);
		 		break;
		 	case 5:
		 		display(first);
		 		break;
		 	default:
				printf("### Invalid choice ###");	
		}
	}while(choice!=99);
}
