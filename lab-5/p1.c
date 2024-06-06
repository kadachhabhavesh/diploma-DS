#include<stdio.h>
#define n 5
void push(int s[],int *top,int x){
	if(*top>n){
		printf("stack overflow");
		return;
	}else{
		*top=*top+1;
		s[*top]=x;
		printf("-- %d PUSH --",x);
		return;
	}
}
void pop(int s[],int *top){
	int del;
	if(*top==-1){
		printf("stack underflow");
		return;
	}else{
		del=s[*top];
		*top=*top-1;
		printf("-- %d POP --",del);
		return;
	}
}
int peep(int s[],int *top,int i){
	if(*top<0){
		printf("stack empty");
		return -1;
	}if(top-i+1<0){
		printf("Stack underflow");
		return -1;
	}
	
	int value = s[*top-i+1];
	printf("element at position %d from top is %d",i,value);
}
void change(int s[],int *top,int i,int x){
	if(*top<0){
		printf("stack empty");
		return;
	}if(top-i+1<0){
		printf("Stack underflow");
		return;
	}
	s[*top-i+1]=x;
}
void display(int s[],int *top){
	int i = *top;	
	if(*top<0){
		printf("stack underflow");
		return;
	}
	else{
		printf("--- stack ---\n");
		while(i>=0){
			printf("%d\n",s[i]);
			i--;
		}
	}
}
void main(){
	int x,po,choice,top=-1,s[100];
	do{
		printf("\n1.PUSH\n2.POP\n3.PEEP\n4.CHNAGE\n5.DISPLAY\n99.EXIT\nEnter Your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter element : ");
				scanf("%d",&x);
				push(s,&top,x);
				printf("\ntop-%d",top);
				break;
			case 2:
				pop(s,&top);
				break;
			case 3:
				printf("Enter position of element : ");
				scanf("%d",&po);
				peep(s,&top,po);
				break;
			case 4:
				printf("Enter element : ");
				scanf("%d",&x);
				printf("Enter position of element to be change: ");
				scanf("%d",&po);
				change(s,&top,po,x);
				break;
			case 5:
				display(s,&top);
				break;
			default:
				printf("### Invalid choice ###");
		}
	}while(choice!=99);
}
