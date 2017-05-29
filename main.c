#include <stdio.h>
#include "include/dijkstra.h"
#include "include/backstp.h"
#include "include/tree.h"
#define  MAX 10
#define max 10
#define  INF 2147483647
#define Link 1
#define Thread 0
#define MAXSIZE 100
int main ()
{
 int i,j;
initial();
    backstp(2);
   i=p();
    printf("tsp:\n%d\n",i);
 int pre[MAX];
 int dist[MAX];
 printf("disjistra:\n");
 dijkstra(0,pre,dist);
     CreateGraph();
     printf("\n");
     PrintGraph();
     TopologicalSort();
    /* printf("\nthe input can be abc###de###:\n");
     BiTNode *T=NULL;
    BiTNode *th=NULL;
    T=createtree(T);
    printf("preorder_1:\n");
    preorder(T);
    printf("\n");
    printf("inorder_1:\n");
    inorder(T);
    printf("\n");
    printf("postorder_1:\n");
    postorder(T);
    printf("\n");
    printf("preorder_2:\n");
    preorder_2(T);
    printf("inorder_2:\n");
    inorder_2(T);
    printf("postoreder_2:\n");
    postorder_2(T);
    printf("inorderthread_in\n");
    th=inorderTheading(T,th);
    inorderthread_in(th);*/
 return 0;
}
