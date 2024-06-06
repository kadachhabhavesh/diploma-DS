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
int min(int q[],int *f,int *r){
	int i,min=q[*f],totalel;
	if(*f==-1 && *r==-1){
		printf("quesu is underflow");
		return -1;
	}
	if(*f<=*r){
		for(i=*f+1;i<=*r;i++){
			if(q[i]<min)
				min=q[i];
		}
		return min;
	}else{
		for(i=*f;i<size;i++){
			if(q[i]<min)
				min=q[i];
		}
		for(i=0;i<=*r;i++){
			if(q[i]<min)
				min=q[i];
		}
		return min;
	}
}
int max(int q[],int *f,int *r){
	int i,max=q[*f],totalel;
	if(*f==-1 && *r==-1){
		printf("quesu is underflow");
		return -1;
	}
	if(*f<=*r){
		for(i=*f+1;i<=*r;i++){
			if(q[i]>max)
				max=q[i];
		}
		return max;
	}else{
		for(i=*f;i<size;i++){
			if(q[i]>max)
				max=q[i];
		}
		for(i=0;i<=*r;i++){
			if(q[i]>max)
				max=q[i];
		}
		return max;
	}
}
void main(){
	int q[100],r=-1,f=-1,choice,x;
	
	enqueue(q,&f,&r,11);
	enqueue(q,&f,&r,12);
	enqueue(q,&f,&r,13);
	enqueue(q,&f,&r,14);
	enqueue(q,&f,&r,15);
	dequeue(q,&f,&r,&x);
	dequeue(q,&f,&r,&x);
	enqueue(q,&f,&r,16);
	enqueue(q,&f,&r,1);
	printf("min = %d",min(q,&f,&r));
	printf("\nmax = %d",max(q,&f,&r));
}
