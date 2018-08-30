#include<stdio.h>
#include<stdlib.h>
typedef struct BITree{
    char data;
    BITree *lchild;
    BITree *rchild;
}BITree,*BiTree;
typedef struct Stack{
    BiTree data;
    Stack *next;
}Stack;
BITree *pop(Stack *p)
{
    Stack *q;
    q = p->next;
    p ->next = q->next;
    return q->data;
}
void push(Stack *q,BiTree &p)
{
    Stack *q1;
    q1 = (Stack*)malloc(sizeof(Stack));
    if(!q1)exit(0);
    q1->data=p;
    q1->next = q->next;
    q->next=q1;
}

//创建二叉树 
void CreateBiTree(BiTree &p)
{
    char d;
    scanf("%c",&d);
    fflush(stdin);
    if(d=='#')p=NULL;
    else{
        p=(BITree*)malloc(sizeof(BITree));
        if(!p)exit(0);
        p->data=d;
        CreateBiTree(p->lchild);
        CreateBiTree(p->rchild);
    }
}

//前序遍历 
void Q_BiTree(BiTree &p)
{
    if(p==NULL)
    return ;
    else{
        printf("%c",p->data);
        Q_BiTree(p->lchild);
        Q_BiTree(p->rchild);
    }
}

//中序遍历 
void Z_BiTree(BiTree &p)
{
    if(p==NULL)
        return;
    else{
        Z_BiTree(p->lchild);
        printf("%c",p->data);
        Z_BiTree(p->rchild);
    }
}

// 后续遍历 
void H_BiTree(BiTree &p)
{
    if(p==NULL)
        return ;
        else{
            H_BiTree(p->lchild);
            H_BiTree(p->rchild);
            printf("%c",p->data);
        }
}

//求二叉树的深度 
int depth(BiTree &p)
{
    if(p==NULL)
        return 0;
    else
    {
        int l=depth(p->lchild);
        int r=depth(p->rchild);
        return (l>r?l:r)+1;
    }
}

//求二叉树的节点数 
int num_of_nodes(BiTree &p)
{
    if(p==NULL)
        return 0;
    return 1+num_of_nodes(p->lchild)+num_of_nodes(p->rchild);
}

//求二叉树的叶子接点 
int num_of_yezi(BiTree &p)
{
    if(p==NULL)
        return 0;
    if((p->lchild==NULL)&&(p->rchild==NULL))
        return 1;
    return num_of_nodes(p->lchild)+num_of_yezi(p->rchild);
}

//求只有一个节点 
int num_of_1nodes(BiTree &p)
{

    if(p==NULL)
        return 0;
    if((p->lchild==NULL&&p->rchild!=NULL)||(p->lchild!=NULL&&p->rchild==NULL))
        return 1;
    return num_of_1nodes(p->lchild)+num_of_1nodes(p->rchild);
}

//交换左右子树 
void changeNode(BiTree &p)
{
    if(p==NULL)
        return ;
    else{
        BiTree q;
        q=p->lchild;
        p->lchild=q->rchild;
        q->rchild=q;
    }
    changeNode(p->lchild);
    changeNode(p->rchild);
}

//非递归，前序遍历 
void F_Q_BiTree(BiTree &p)
{
    Stack *q;
    q=(Stack *)malloc(sizeof(Stack));
    if(!q)exit(0);
    q->next=NULL;
    while(p||q->next!=NULL)
    {
        while(p)
        {
            push(q,p);
            printf("%c",p->data);
            p=p->lchild;
        }
        p=pop(q);
        p=p->rchild;
    }
}
//非递归，中序遍历 
void F_Z_BiTree(BiTree &p)
{
    Stack *q;
    q=(Stack *)malloc(sizeof(Stack));
    if(!q)exit(0);
    q->next=NULL;
    while(p||q->next!=NULL)
    {
        while(p)
        {
            push(q,p);
            p=p->lchild;
        }
        p=pop(q);
        printf("%c",p->data);
        p=p->rchild;
    }
}
void F_H_BiTree(BiTree &p)
{
    //buxiele
}
int main()
{
    int n=0;
    BiTree p;
    CreateBiTree(p);
    /*n=num_of_nodes(p);
    n=num_of_yezi(p);
    n=depth(p);
    n=num_of_1nodes(p);
    printf("%d",n);
    changeNode(p);*/
    F_Q_BiTree(p);
//    Q_BiTree(p);


}

















