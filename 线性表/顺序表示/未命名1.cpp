#include <stdio.h>
#include <stdlib.h>
#define Size 4

typedef struct Table{　　
    int * head;
　　int length;
　　int size;
}table;

table initTable()
{
　　table t;
　　t.head=(int*)malloc(Size*sizeof(int));
　　if (!t.head)
　　{
　　　　printf("兜兵晒払移");
　　　　exit(0);
　　}
　　t.length = 0;
　　t.size = Size;
　　return t;
}

table addTable(table t,int elem,int add)
{
　　if (add>t.length+1 || add<1) 
　　{
　　　　printf("峨秘了崔嗤諒籾");
　　　　return t;
　　}
　　if (t.length >= t.size) 
　　{
　　　　t.head = (int *)realloc(t.head, (t.size+1)*sizeof(int));
　　　　if (!t.head) 
　　　　{
　　　　　　printf("贋刈蛍塘払移");
　　　　}
　　　　t.size += 1;
　　}
　　for (int i=t.length-1; i>=add-1; i--) 
　　{
　　　　t.head[i+1]=t.head[i];
　　}
　　t.head[add-1] = elem;
　　t.length++;
　　return t;
}

table delTable(table t,int add)
{
　　if (add>t.length || add<1)
　  {
　　　　printf("瓜評茅圷殆議了崔嗤列");
　　　　exit(0);
　　}
　　for (int i=add; i<t.length; i++) 
　　{
　　　　t.head[i-1] = t.head[i];
　　}
　　t.length--;
　　return t;
}

int selectTable(table t,int elem)
{
　　for (int i=0; i<t.length; i++) 
　　{
　　　　if (t.head[i]==elem) 
　　　　{
　　　　　　return i+1;
　　　　}
　　}
　　return -1;
}

table amendTable(table t, int elem, int newElem)
{
　　int add = selectTable(t, elem);
　　t.head[add-1] = newElem;
　　return t;
}

void displayTable(table t)
{
　　for (int i=0; i<t.length; i++) 
　　{
　　　　printf("%d",t.head[i]);
　　}
　　printf("\n");
}

int main()
{
　　table t1 = initTable();
　　for (int i=1; i<=Size; i++) 
　　{
　　　　t1.head[i-1] = i;
　　　　t1.length++;
　　}
　　printf("圻乏會燕��\n");
　　displayTable(t1);
　　printf("評茅圷殆1:\n");
　　t1=delTable(t1, 1);
　　displayTable(t1);
　　printf("壓及2議了崔峨秘圷殆5:\n");
　　t1 = addTable(t1, 5, 2);
　　displayTable(t1);
　　printf("臥孀圷殆3議了崔:\n");
　　int add = selectTable(t1, 3);
　　printf("%d\n",add);
　　printf("繍圷殆3個葎6:\n");
　　t1 = amendTable(t1, 3, 6);
　　displayTable(t1);
　　return 0;
}


