#include<stdio.h>
#define size 5
void enqueue(int q[],int *f,int *r,int x){
	if(*r>=size){
		printf("queue overflow");
		return;
	}
	*r=*r+1;
	q[*r]=x;
	if(*f==-1)
		*f=0;
}
void dequeue(int q[],int *f,int *r,int *x){
	if(*f==-1){
		printf("queue is underflow");
		return;
	}
	*x=q[*f];
	printf("\n%d delete from queue",*x);
	if(*r==*f){
		*r=-1;
		*f=-1;
	}else{
		*f=*f+1;
	}
}
float avgOfQueue(int q[],int *f,int *r){
	int i,sum=0;
	for(i=*f;i<=*r;i++){
		sum=sum+q[i];
	}
	return (float)sum/(*r-*f+1);
}
void main(){
	int q[100],r=-1,f=-1,avg;
	enqueue(q,&f,&r,56);
	enqueue(q,&f,&r,77);
	enqueue(q,&f,&r,48);
	enqueue(q,&f,&r,45);
	printf("avg = %f",avgOfQueue(q,&f,&r));
}
