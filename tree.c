#include <stdio.h>
#include <stdlib.h>
#include "include/tree.h"
BiTNode* createtree(BiTNode* T)
{
   char ch;
    scanf("%c",&ch);
    if (ch=='#')
    {
        T=NULL;
       return 0;}
    else
    {
        if (!(T=(BiTNode*)malloc(sizeof (BiTNode))))
        {
            printf("create Error!");
            exit (0);
        }
        {
            T->data=ch;
            T->Rtag=Link;
            T->Ltag=Link;
        }
        T->Lchild=createtree(T->Lchild);
        T->Rchild=createtree(T->Rchild);
    }
    return T;
}
void  preorder(BiTNode* T)
{
    if (T!=NULL)
    {
       printf("%c ",T->data);
       preorder(T->Lchild);
       preorder(T->Rchild);

    }
}
void  inorder(BiTNode* T)
{
    if (T!=NULL)
    {
       inorder(T->Lchild);
       printf("%c ",T->data);
       inorder(T->Rchild);

    }

}
void  postorder(BiTNode* T)
{
    if (T!=NULL)
    {
       postorder(T->Lchild);
       postorder(T->Rchild);
       printf("%c ",T->data);
    }

}
void preorder_2(BiTNode* T)
{

	BiTNode *p=T;
	BiTNode *Sqstack[30];
	int num=0;
	while(p!=NULL||num>0)
	{
		while(NULL!=p)
		{
			printf("%C ",p->data);
			Sqstack[num++]=p;
			p=p->Lchild;
		}
		num--;
		p=Sqstack[num];
		p=p->Rchild;
	}
	printf("\n");

}
void inorder_2(BiTNode *T)
{
	BiTNode *p=T;
	int num=0;
	BiTNode *Sqstack[30];
	while(NULL!=p||num>0)
	{
		while(NULL!=p)
		{
			Sqstack[num++]=p;
			p=p->Lchild;
		}
		num--;
		p=Sqstack[num];
		printf("%c ",p->data);
		p=p->Rchild;
	}
	printf("\n");
}
void postorder_2(BiTNode *T)
{
	BiTNode *p=T;
	BiTNode *Sqstack[30];
	int num=0;
	BiTNode *visited=NULL;
	while(NULL!=p||num>0)
	{
		while(NULL!=p)
		{
			Sqstack[num++]=p;
			p=p->Lchild;
		}
		p=Sqstack[num-1];
		if(NULL==p->Rchild||visited==p->Rchild)
		{
			printf("%c ",p->data);
			num--;
			visited=p;
			p=NULL;
		}
		else
		{
			p=p->Rchild;
		}
	}
	printf("\n");
}

BiTNode* inorderTheading(BiTNode *T,BiTNode *th)
{
    if(!(th=(BiTNode*)malloc(sizeof(BiTNode))))
       {
           printf("error!");
           exit(0);
       }
       th->Ltag=Link;
       th->Rtag=Thread;
       th->Rchild=th;
       if (!T)
        th->Lchild=th;
       else
       {
           th->Lchild=T;
           pre=th;
           inthreading(T);
           pre->Rchild=th;
           pre->Rtag=Thread;
           th->Rchild=pre;
       }
       return th;
}
void inthreading(BiTNode *p)
{
    if (p)
    {
        inthreading(p->Lchild);
        if (!p->Lchild)
        {
            p->Ltag=Thread;
            p->Lchild=pre;
        }
        if (!pre->Rchild)
        {
            pre->Rtag=Thread;
            pre->Rchild=p;
        }
        pre=p;
        inthreading(p->Rchild);
    }
}
void inorderthread_in(BiTNode *T)
{
    BiTNode *p;
    p=T->Lchild;
    while(p!=T)
    {
        while(p->Ltag==Link)
            p=p->Lchild;
        printf("%c ",p->data);
        while(p->Rtag==Thread&&p->Rchild!=T)
        {
            p=p->Rchild;
            printf("%c ",p->data);
        }
        p=p->Rchild;
    }
}
