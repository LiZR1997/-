#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct SqList{
	ElemType *elem ;    // ���Ա�˳���ʾ�Ļ������� 
	int length;         // ��ǰ�ı� 
	int listsize;       // ��ǰ����洢�ռ������ 
}SqList ;
 
//����˳��� 
SqList InitList() {   
	SqList L;
	L.elem = (ElemType*)malloc(10*sizeof(ElemType));
	if(!L.elem)
	exit(0);
	L.length = 0;
	L.listsize = 10;
	return L;
}

//���Ԫ�� 
int add(SqList &L) {   
	int i = 0;
	for( ; ; )
	{	
		char n = 'N';
		if(L.length == L.listsize)
		return L.listsize - L.length;
		printf("������Ԫ��");
		scanf( "%d" , &(L.elem[i]));
		i++;
		L.length++;
		printf("�Ƿ��������Y/N");
		fflush(stdin);
		scanf("%c" , &n);
		if(n != 'Y')
		return L.listsize - L.length;
		fflush(stdin);	
	 }
	  
}

//���Ԫ�� 
void PrintfSqList(SqList &L) {  //
	for(int i = 0 ; i < L.length ; i ++ )
	printf("///%d/// " , L.elem[i]);
}

//ɾ��ָ��Ԫ�� 
int deleteSqList(SqList &L, int n){     //
	if( n > L.length)
	return 0 ;
	for(int i = n ; i < L.listsize ; i++)
		L.elem[i-1] = L.elem[i];
	L.length--;
	return 1 ;
} 

//����Ԫ�� 
int insertSqList(SqList &L , int n , int data) {
	if( n > L.length || L.length == L.listsize)
	return 0 ;
	L.length++;
	for( int i =  L.length ; i >= n-1 ; i--)
	L.elem[i] = L.elem[i-1];
	L.elem[n-1] = data;
}

//���� 
int Reverseorder(SqList &L) {
	for(int i = 0 ; i <= ( L.length - 1 ) / 2 ; i ++)
	{
		int data = L.elem[i];
		L.elem[i] = L.elem[L.length - 1 - i];
		L.elem[L.length-1-i] = data;
	}
}

//���� ��С���� �� �ɴ�С 
int sortSqList(SqList &L , int z) {
	for(int i = 0 ; i < L.length ; i ++)
	for(int j = L.length-1 ; j > i ; j--)
		if( L.elem[j] <= L.elem[j-1])
		{
		int data = L.elem[j];
		L.elem[j] = L.elem[j-1];
		L.elem[j-1] = data;
		}
	if( z < 0)
	Reverseorder(L);
	return 0;	
}

//ɾ������Ԫ�� 
int deleteAll(SqList &L)
{
	L.length = 0;
}
main() {
	SqList L;
	L = InitList();
	add(L);
	PrintfSqList(L);
//	deleteSqList(L,1);
//    insertSqList(L , 2 , 9);
//    Reverseorder(L);
    sortSqList(L , -1);
	printf("\n");
	PrintfSqList(L);
	
}
