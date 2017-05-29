#include <stdio.h>
#include <stdlib.h>
#include "include/backstp.h"
#define max 10
int n=5;
int cw=0;
int x[13];
int bestx[13];
int w[13][13];
char course[max][40]={"introde","c_program","algorithm","Math","Data"};
int co[5][5]={0,0,0,0,0,1,1,0,0,0,2,1,2,0,0,3,1,2,3,0,0,0,0,0,0};
int a[5][5]={0,1,2,3,4,1,0,2,3,1,2,1,0,2,3,1,2,1,0,3,1,2,3,2,0};
void InitQueue(LinkQueue *Q)
 {    Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
     if (!(Q->front)) exit(0);
     Q->front->next=NULL;
 }
 int QueueEmpty(LinkQueue Q)
 {    if(Q.front==Q.rear)
         return 1;
     else
        return 0;
 }
 void EnQueue(LinkQueue *Q, ElemType e)
 {    QueuePtr p;
     p=(QueuePtr)malloc(sizeof(QNode));
     if (!p) exit(0);
     p->data=e; p->next=NULL;
     Q->rear->next=p;
     Q->rear=p; }
 void DeQueue(LinkQueue *Q, ElemType *e)
 {    QueuePtr p;
     if(Q->front!=Q->rear)
         {    p=Q->front->next;
             *e=p->data;
             Q->front->next=p->next;
             if (Q->rear==p) Q->rear=Q->front;
             free(p); }
 }
void CreateGraph()
 {    int i,j,k=0;
      int link[n][n];
      int num[n];
      for (i=0;i<n;i++)
        num[i]=0;
      int v1,v2;ArcNode *newarc;
     G.vexnum=n;
     int count;
     for(i=0;i<G.vexnum;i++)
    {
        G.vexhead[i].firstarc=NULL;
        G.vexhead[i].name=i;
        G.vexhead[i].indegree=0;
    }
     for(j=0;j<G.vexnum;j++)
         {    count=co[j][0];
             G.vexhead[j].indegree=count;
              v2=j;
              for (i=0;i<count;i++)
              {
                v1=co[j][i];
                link[v1-1][num[v1-1]]=j;
                num[v1-1]++;
              }
         }
    for (i=0;i<G.vexnum;i++)
    {
        k=num[i];
        for (j=0;j<k;j++)
        {
            newarc=(ArcNode*)malloc(sizeof(ArcNode));
            newarc->vexpos=link[i][j];
            if(G.vexhead[i].firstarc==NULL)
            {    newarc->next=NULL;
                    G.vexhead[i].firstarc=newarc; }
            else
                {    newarc->next=G.vexhead[i].firstarc->next;
                    G.vexhead[i].firstarc->next=newarc; }
        }

    }
}
void PrintGraph()
 {    int i;
    ArcNode *p;
     printf("\n输出有向图:\n");
     for(i=0; i<G.vexnum; i++)
         {
             printf("\n顶点:%d   ",G.vexhead[i].name+1);
             printf("入度:%3d\n", G.vexhead[i].indegree);
             p=G.vexhead[i].firstarc;
             printf("邻接点:");
             while(p!=NULL)
                 {
                    printf("%s   %d  %d ",course[G.vexhead[p->vexpos].name],G.vexhead[p->vexpos].name,p->vexpos);
                     p=p->next;
                 }
             printf("\n");
         }
 }
 void TopologicalSort()
 {
    int i,k,count;ElemType e;ArcNode *p;
     LinkQueue Q;
     InitQueue(&Q);
     for(i=0; i<G.vexnum; i++)
         if(!G.vexhead[i].indegree)
            EnQueue(&Q,i);
     count=0;
     while(!QueueEmpty(Q))
     {
         DeQueue(&Q,&e);
         printf("%s ",course[G.vexhead[e].name]);
         count++;
         for(p=G.vexhead[e].firstarc;p;p=p->next)
         {
             k=p->vexpos;
             if(!(--G.vexhead[k].indegree))
                 EnQueue(&Q,k);
         }
     }
printf("\n");
     if(count<G.vexnum)
       printf("Impossible!");
 }
void initial()
{
int i,j;
for (i=1;i<n;i++)
{
x[i]=i;
for (j=1;j<n;j++)
w[i][j]=a[i][j];
}}
void backstp(int i)
{
    int j,temp;
    cw=0;
    bestw=INF;
    if (i==n)
    {
        if (cw+w[x[n-1]][x[n]]+w[x[n]][1]<bestw)
        {
            bestw=cw+w[x[n-1]][x[n]]+w[x[n]][1];
            for (j=1;j<=n;j++)
                bestx[j]=x[j];
        }
    }
     else
     {
         for (j=i;j<=n;j++)
         {
           if (cw+w[x[i-1]][j]<bestw)
           {
               temp=x[i];
               x[i]=x[j];
               x[j]=temp;
               cw=cw+w[x[i-1]][x[i]];
               backstp(i+1);
               cw=cw-w[x[i-1]][x[i]];
               temp=x[i];
               x[i]=x[j];
               x[j]=temp;
           }
         }
     }

}
int p()
{
return bestw;
}
