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
	if(*r==*f){
		*r=-1;
		*f=-1;
	}else{
		*f=*f+1;
	}
}
void sortQueue(int q[], int *f, int *r) {
    if (*f == -1) {
        printf("Queue is empty, nothing to sort\n");
        return;
    }
    int temp[size],count = 0,i,j;
    while (*f != -1) {
    	int x=0;
    	dequeue(q, f, r,&x);
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
    *f = -1;
    *r = -1;
    for (i = 0; i < count; i++) {
        enqueue(q, f, r, temp[i]);
    }
}

void main(){
	int q[100],r=-1,f=-1,i;
	enqueue(q,&f,&r,56);
	enqueue(q,&f,&r,77);
	enqueue(q,&f,&r,48);
	enqueue(q,&f,&r,45);
	printf("\nbefore sort queue");
	for(i=f;i<=r;i++){
		printf("%d ",q[i]);
	}
	printf("\nafter sort queue");
	sortQueue(q,&f,&r);
	for(i=f;i<=r;i++){
		printf("%d ",q[i]);
	}
}
