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
int countNode(struct Node* first){
	int count = 0;
    struct Node* ptr = first;
    while (ptr != NULL) {
        count++;
        ptr = ptr->link;
    }
    return count;
}void display(struct Node* first){
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
	int choice=-1,x,n,len;
	do{
		printf("\n1.Insert at begin\n2.display\n3.count\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("enter data to be insert : ");
		 		scanf("%d",&x);
		 		InsertAtBeg(x,&first);
		 		break;
		 	case 2:
		 		display(first);
		 		break;
		 	case 3:
		 		len = countNode(first);
		 		printf("length of LL is %d",len);
		 		break;
		 	default:
				printf("### Invalid choice ###");	
		}
	}while(choice!=99);
}
