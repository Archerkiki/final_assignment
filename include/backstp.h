#define  MAX 10
#define max 10
#define  INF 2147483647
#define Link 1
#define Thread 0
#define MAXSIZE 100
static int bestw=INF;
typedef int ElemType;
typedef struct QNode
 {    ElemType  data;
     struct QNode *next;
 }    QNode,*QueuePtr;
 typedef struct
 {    QueuePtr front;
     QueuePtr rear;
 }    LinkQueue;
 typedef struct ArcNode
 {    int vexpos;
     struct ArcNode *next;
 }    ArcNode;
 typedef struct VNode
 {
     int name;
     int indegree;
     ArcNode *firstarc;
 }    VNode,AdjList[max];
 typedef struct
 {    AdjList vexhead;
     int vexnum,arcnum;
 }    ALGraph ;
 ALGraph G;
#ifndef _CALC_H
#define _CALC_H
void InitQueue(LinkQueue *Q);
 int QueueEmpty(LinkQueue Q);
 void EnQueue(LinkQueue *Q, ElemType e);
void DeQueue(LinkQueue *Q, ElemType *e);
void backstp(int i);
void CreateGraph();
void PrintGraph();
void TopologicalSort();
int p();
void initial();
#endif //_CALC_H
