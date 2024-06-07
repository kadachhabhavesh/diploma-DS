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
void searchNode(struct Node* first, int n) {
    if (first == NULL) {
        printf("Linked List is Empty & Underflow\n");
        return;
    }
    int flag = 0;
    struct Node* ptr = first;
    while (ptr != NULL) {
        if (ptr->info == n) {
            flag = 1;
            break;
        }
        ptr = ptr->link;
    }
    if (flag == 1) {
        printf("Search Successful\n");
    } else {
        printf("Search Unsuccessful\n");
    }
}
void main(){
	struct Node* first = NULL;
	int choice=-1,x,n,len;
	do{
		printf("\n1.Insert at begi\n2.search node\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("enter data to be insert : ");
		 		scanf("%d",&x);
		 		InsertAtBeg(x,&first);
		 		break;
		 	case 2:
		 		printf("enter data to be search : ");
		 		scanf("%d",&x);
		 		searchNode(first,x);
		 		break;
		 	default:
				printf("### Invalid choice ###");	
		}
	}while(choice!=99);
}
