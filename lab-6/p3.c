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
int minimum(int q[],int *f,int *r){
	int i,min=q[0];
	for(i=*f+1;i<=*r;i++){
		if(min>q[i])
			min=q[i];
	}
	return min;
}
int maximum(int q[],int *f,int *r){
	int i,max=q[0];
	for(i=*f+1;i<=*r;i++){
		if(max<q[i])
			max=q[i];
	}
	return max;
}
void main(){
	int q[100],r=-1,f=-1,n=100,avg;
	enqueue(q,&f,&r,56);
	enqueue(q,&f,&r,77);
	enqueue(q,&f,&r,48);
	enqueue(q,&f,&r,45);
	printf("min = %d",minimum(q,&f,&r));
	printf("\nmax = %d",maximum(q,&f,&r));
}
