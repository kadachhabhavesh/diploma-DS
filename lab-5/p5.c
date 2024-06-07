#include<stdio.h>
void push(int s[],int *top,int x,int n){
	if(*top>=n){
		printf("stack overflow");
		return;
	}else{
		*top=*top+1;
		s[*top]=x;
		return;
	}
}
int pop(int s[],int *top){
	int n = sizeof(s)/sizeof(s[0]);
	int del;
	if(*top==-1){
		printf("stack underflow");
		return -1;
	}else{
		del=s[*top];
		*top=*top-1;
		return del;
	}
}
int performOperation(int op1,int op2,char operater){
	switch(operater){
		case '+':
			return op1+op2;
		case '-':
			return op1-op2;
		case '*':
			return op1*op2;
		case '/':
			return op1/op2;
		default:
			printf("invalid operater");
	}
}
void postfixEvalution(char prefix[]){
	int len;
	while(prefix[len]!='\0') len++;
	
	int top=-1,value=-1,s[100],n=100,i;
	for(i=len-1;i>=0;i--){
		if(prefix[i]>='0' && prefix[i]<='9'){
			push(s,&top,prefix[i]-'0',n);
		}
		else{
			int op1 = pop(s,&top);
			int op2 = pop(s,&top);
			value = performOperation(op1,op2,prefix[i]);
			push(s,&top,value,n);
		}	
	}
	printf("\n%d",pop(s,&top));
}
void main(){
	char prefix[100];
	printf("Enter prefix : ");
	gets(prefix);
	postfixEvalution(prefix);
}
