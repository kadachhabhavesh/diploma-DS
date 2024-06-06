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
int minimum(int s[],int *top){
	int i,min=s[0];
	for(i=1;i<=*top;i++){
		if(min > s[i])
			min=s[i];
	}
	return min;
}
int maximum(int s[],int *top){
	int i,max=s[0];
	for(i=1;i<=*top;i++){
		if(max < s[i])
			max=s[i];
	}
	return max;
}
void main(){
	int i,s[100],top=-1;
	push(s,&top,55);
	push(s,&top,52);
	push(s,&top,68);
	push(s,&top,16);
	int min = minimum(s,&top);
	int max = maximum(s,&top);
	printf("min = %d\nmax = %d",min,max);
}
