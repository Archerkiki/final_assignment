#define MAXSIZE 100
typedef struct PTnode
{
    char data;
    int parent;
}PTnode;
typedef struct
{
    PTnode node[MAXSIZE];
    int r,n;
}PTree;
typedef struct BiTNode
{
    char data;
    struct BiTNode *Lchild,*Rchild;
    short Rtag,Ltag;
}BiTNode ;

#define  MAX 10
#define max 10
#define  INF 2147483647
#define Link 1
#define Thread 0

#ifndef _CALC_H
#define _CALC_H

static BiTNode *pre;
BiTNode* createtree(BiTNode *T);
void  preorder(BiTNode *T);
void  inorder(BiTNode *T);
void  postorder(BiTNode *T);
void preorder_2(BiTNode *T);
void inorder_2(BiTNode *T);
void postorder_2(BiTNode *T);
BiTNode* inorderTheading(BiTNode *T,BiTNode *th);
void inthreading(BiTNode *p);
void inorderthread_in(BiTNode *T);
#endif 
