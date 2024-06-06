#include<stdio.h>
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
void InsertAtEnd(int data,struct Node** first){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
	newNode->info = data;
	newNode->link = NULL;
	if(*first == NULL){
		*first = newNode;
	}else{
		struct Node* ptr = *first;
		while(ptr->link != NULL){
			ptr = ptr->link;
		}
		ptr->link = newNode;
	}
}
void deleteFirst(struct Node** first){
	if(*first == NULL){
		printf("Linked list is empty");
		return;
	}
	if((*first)->link == NULL){
		free(*first);
		*first = NULL;
	}else{
		*first = (*first)->link;
	}
}
void deleteEnd(struct Node** first){
	if(*first == NULL){
		printf("Linked list is empty");
		return;
	}
	if((*first)->link == NULL){
		free(*first);
		*first = NULL;
	}else{
		struct Node* ptr = *first;
		struct Node* preptr = *first;
		while(ptr->link != NULL){
			preptr = ptr;
			ptr=ptr->link;
		}
		free(preptr->link);
		preptr->link=NULL;
	}
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
	int choice=-1,x;
	do{
		printf("\n1.Insert at the beginning\n2.Insert at the end\n3.Delete a first node\n4.Delete a last node\n5.Display all nodes.\nEnter your choice : ");
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
		 		InsertAtEnd(x,&first);
		 		break;
		 	case 3:
		 		deleteFirst(&first);
		 		break;
		 	case 4:
		 		deleteEnd(&first);
		 		break;
		 	case 5:
		 		display(first);
		 		break;
		 	default:
				printf("### Invalid choice ###");	
		}
	}while(choice!=99);
}
