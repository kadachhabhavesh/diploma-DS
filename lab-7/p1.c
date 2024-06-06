#include<stdio.h>
#define size 5
void enqueue(int q[],int *f,int *r,int x){
	if((*f==0 && *r==size-1) || (*f==*r+1)){
		printf("circular queue overflow");
		return;
	}else if(*f==-1 && *r==-1){
		*f=0;
		*r=0;
	}else if(*f!=0 && *r==size-1){
		*r=0;
	}else{
		*r=*r+1;
	}
	q[*r]=x;
}
void dequeue(int q[],int *f,int *r,int *x){
	if(*f==-1){
		printf("circular queue is underflow");
		return;
	}
	*x=q[*f];
	printf("\n%d delete from queue",*x);
	if(*r==*f){
		*r=-1;
		*f=-1;
	}else if(*f==size-1){
		*f=0;
	}
	else{
		*f=*f+1;
	}
}
void display(int q[],int *f,int *r){
	int i;
	if(*f==-1 && *r==-1){
		printf("quesu is underflow");
		return;
	}
	if(*f<=*r){
		for(i=*f;i<=*r;i++){
			printf("%d ",q[i]);
		}
	}else{
		for(i=*f;i<size;i++){
			printf("%d ",q[i]);
		}
		for(i=0;i<=*r;i++){
			printf("%d ",q[i]);
		}
	}
}
void main(){
	int q[100],r=-1,f=-1,choice,x;
	
	do{
		printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n99.EXIT\nEnter Your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter element : ");
				scanf("%d",&x);
				enqueue(q,&f,&r,x);
				break;
			case 2:
				dequeue(q,&f,&r,&x);
				break;
			case 3:
				display(q,&f,&r);
				break;
			default:
				printf("### Invalid choice ###");
		}
	}while(choice!=99);
}
