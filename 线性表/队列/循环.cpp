#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int *base ;
	int front ;
	int rear ;
} SqQueue ;

//����ն��� 
int InitQueue(SqQueue &Q) {
	Q.base = (int *)malloc(6*sizeof(int));
	if(!Q.base)
	exit(0);
	Q.front = Q.rear = 0;
}

//�ڶ�β���Ԫ�� 
int EnQueue(SqQueue &Q , int e) {
	if((Q.rear+1)%6 == Q.front)
	return -1 ;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear+1) % 6 ; //���� 
	return 0 ;
} 

//ȡ����ͷԪ�� 
int DeQueue(SqQueue &Q ) {
	if(Q.rear == Q.front)
	return -1 ;
	int n = Q.base[Q.front];
	Q.front = (Q.front+1)%6;
	return n ;
}
//�ж�ѭ������ĳ��� 
int QueueLength(SqQueue &Q) {
	return ( Q.rear - Q.front + 6 ) / 6;
}

int main() {
	SqQueue Q ;
	InitQueue(Q) ;
	for(int i = 0 ; i <= 4 ; i++ )
	EnQueue(Q , i);
	while(Q.front != Q.rear)
	printf("%d" , DeQueue(Q));
}
