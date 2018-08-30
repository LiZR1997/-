#include<stdio.h>
#include<stdlib.h>

typedef struct SqStack {
	int *base;
	int *top;
	int stacksize;
}SqStack; 

//创建顺序栈 
SqStack InitStack() {   
	SqStack S;
	S.base = (int*)malloc(10*sizeof(int));
	if(!S.base)
	exit(0);
	S.top = S.base;
	S.stacksize = 10 ;
	return S;
}

//设置为空栈 
int ClearStack(SqStack &S) {
	S.top = S.base;
	return 0;
}

//将元素入栈 
int Push(SqStack &S , int e) {
	
	if(S.top - S.base >= S.stacksize)
	{
		S.base = (int *)realloc(S.base , (S.stacksize + S.stacksize/2)*sizeof(int));
		if(!S.base)
		exit(0);
		S.top = S.base + S.stacksize ;
		S.stacksize += S.stacksize/2 ;
	}
	*S.top++ = e;
}

//弹出栈顶元素 
int Pop(SqStack &S) {
	if(S.base == S.top)
	return 0;
	return *--S.top;
}

//取出栈顶元素 
int GetTop(SqStack &S) {
	if(S.base == S.top)
	return 0;
	return *(S.top-1);
}

//将栈内元素倒置 
void StackTraverse(SqStack &S) {
	SqStack S1 = InitStack();
	while(S.base != S.top) 
		Push(S1 , Pop(S));
	S = S1 ;
}

//输出所有元素 
int PrintfStack(SqStack &S) {
	for( ; ; ) {
		if(S.base == S.top)
		return 0;
		printf("%d" , Pop(S));
	}
}
int main() {
	SqStack S ;
	S = InitStack();
	int  n = 0 ;
	for(int i = 0 ; i < 2 ; i++)
	{
		scanf("%d" , &n);
		Push(S , n);
	}
	StackTraverse(S);
	PrintfStack(S);
}
























