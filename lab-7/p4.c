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
void sort(int q[], int *f, int *r) {
    if (*f == -1) {
        printf("Queue is empty\n");
        return;
    }
    int temp[size],count = 0,i,j;
    while (*f != -1) {
        int x=-1;
        dequeue(q, f, r, &x);
        temp[count] = x;
        count++;
    }
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                int swap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swap;
            }
        }
    }
    for (i = 0; i < count; i++) {
        enqueue(q, f, r, temp[i]);
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
	int q[100],r=-1,f=-1,choice,x,i;
	enqueue(q,&f,&r,17);
	enqueue(q,&f,&r,12);
	enqueue(q,&f,&r,23);
	enqueue(q,&f,&r,14);
	enqueue(q,&f,&r,5);
	dequeue(q,&f,&r,&x);
	dequeue(q,&f,&r,&x);
	enqueue(q,&f,&r,16);
	enqueue(q,&f,&r,1);
	sort(q,&f,&r);
	display(q,&f,&r);
	
}
