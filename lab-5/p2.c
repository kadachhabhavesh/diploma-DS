#include<stdio.h>
#define n 5
void push(int s[],int *top,int x){
	if(*top>=n){
		printf("stack overflow");
		return;
	}else{
		*top=*top+1;
		s[*top]=x;
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
		return;
	}
}
float avgOfStack(int s[],int *top){
	int i,sum=0;
	for(i=0;i<=*top;i++){
		sum+=s[i];
	}
	return sum / (*top+1);
}
void main(){
	int i,s[100],top=-1;
	push(s,&top,55);
	push(s,&top,52);
	push(s,&top,68);
	push(s,&top,16);
	float avg = avgOfStack(s,&top);
	printf("avg = %f",avg);
}
