#include<stdio.h>
#include<stdlib.h>

typedef struct Queue {
	int data;
	Queue * next ;
}Queue , *queue;

typedef struct {
	queue front; // ��ͷָ�� 
	queue rear; //  ��βָ�� 
}LinkQueue;
//����һ���ն��� 
void InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = (queue)malloc(sizeof(Queue));
	if(!Q.front)
	exit(0);
	Q.front->next = NULL;
}

//���ٶ��� 
void DestroyQueue(LinkQueue &Q) {
	while(Q.front) {
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
}

//�ڶ�β���Ԫ�� 
void EnQueue(LinkQueue &Q , int n) {
	Q.rear->next = (queue)malloc(sizeof(Queue)) ;
	if(!Q.rear)
	exit(0);
	Q.rear->data = n ;
	Q.rear = Q.rear->next ;
	Q.rear->next = NULL ;
}

//ȡ����ͷԪ�� 
int DeQueue(LinkQueue &Q) {
    if(Q.front == Q.rear)
    return -1 ;
    Queue *q = Q.front->next;
	int n = Q.front->data;
	Q.front = q;
	free(q);
	return n;	
}

 //�������Ԫ�� 
 void PrintfQueue(LinkQueue &Q) {
 	for( ; ; ) 
 	{
 		if(Q.front == Q.rear)
 		break;
 		printf("%d" , DeQueue(Q));
	 }
 }
 
int main() {
	LinkQueue Q ;
	InitQueue(Q);
	for(int i = 0 ; i < 3 ; i++)
	{
		int n = 0 ;
		scanf("%d" , &n);
		EnQueue(Q,n);
	}
	printf("%d\n" , DeQueue(Q));
	PrintfQueue(Q); 	
}



















