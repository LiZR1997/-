#include<stdio.h>
#include<stdlib.h>

typedef struct LinkList {
	int data;
	LinkList *next;

}LinkList , *linklist;
//����ͷ��� 
int CreateList(linklist &L) {
	L = (linklist)malloc(sizeof(LinkList));
	if(!L)
	exit(0);
	L->next = NULL;
	L->data = 0; 
}
//β�巨 
int PushBack(linklist &L) {
	linklist L1 = NULL;
	L1 = L ;
	char c = 'N';
	for( ; ; ){
	linklist q = NULL;
	CreateList(q);
	printf("������Ԫ��\n");
	scanf("%d" , &(q->data));
	L1->next = q ;
	L1= q ;
	fflush(stdin);
	printf("�Ƿ��������Y/N");
	scanf("%c" , &c);
	fflush(stdin);
	if(c != 'Y')
	return 0;
    }
}
//ͷ�巨 
int PushFront(linklist &L) {	
	char c = 'N';
	linklist p = NULL ;
//	L1 = L ;
	p = L;
	for( ; ; ){
	linklist q = NULL ;
	CreateList(q);
	printf("������Ԫ��\n");
	scanf("%d" ,  &(q->data));
	p = L->next;
	L->next = q ;
	q->next = p ;
	fflush(stdin);
	printf("�Ƿ��������Y/N");
	scanf("%c" , &c);
	fflush(stdin);
	if(c != 'Y')
    return 0;	
    }
}
//�������Ԫ�� 
void PrintfList(linklist &L) {
	linklist L1 = L ; 
	while(L1->next != NULL)
	{
	L1 = L1->next;
	printf("///%d///" , L1->data);
    }
	
}

int deleteList(linklist &L , int n) {
	if(L->next == NULL)
	return 0 ;
	linklist L1 = L ;
	while(L1->next->data != n)
		L1 = L1->next;
	L1->next = L1->next->next;
		
}
//������������鲢 
LinkList *MergeList(linklist &La , linklist &Lb ) {
	linklist L = NULL , l = NULL, la = La->next , lb = Lb->next;
	CreateList(L);
	l = L;
	while(lb && la){
	if(la->data >= lb->data){
		l->next = la ;
		l = l->next;
		la = la -> next;
	}
	else{
		l -> next = lb;
		l = l->next;
		lb = lb -> next;
	}
    }
    l->next = lb ? lb : la  ;   
	return L ;
}
//����Ԫ�� 
int insertList(linklist &L , int n ,int data) {
	linklist L1 = L , q ;
	for(int i = 0 ; i < n , L1->next!=NULL ; i++ )
	{
		if(i = n-1)
		{
			CreateList(q);
			q ->data = data ;
			q->next = L1->next;
			L1->next = q;
			return n;	
		}
		L1 = L1 -> next;
	}
	return 0;
}
int main() {
	LinkList *q = NULL , *p = NULL ,*L = NULL;
	CreateList(q);
	PushFront(q);
	PrintfList(q);
	printf("\n");
	CreateList(p);
	PushFront(p);
	PrintfList(p);
	L = MergeList(q , p );
	printf("\n");
	PrintfList(L);
//	deleteList(q , 3);
//	PrintfList(q);
	
} 
