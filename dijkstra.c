#include <stdio.h>
#include <stdlib.h>
#include "include/dijkstra.h"
#define  MAX 10
#define max 10
#define  INF 2147483647
void dijkstra(int vs, int prev[], int dist[])
{
    int i,j,k;
    int tmp;
    int min;
int a[5][5]={0,1,2,3,4,1,0,2,3,1,2,1,0,2,3,1,2,1,0,3,1,2,3,2,0};
 for (i=0;i<n;i++)
 {
     for (j=0;j<n;j++)
       matrix[i][j]=a[i][j];
 }
    int flag[MAX];
    for (i = 0; i < n; i++)
    {
        flag[i] = 0;
        prev[i] = 0;
        dist[i] = matrix[vs][i];
    }
    flag[vs] = 1;
    dist[vs] = 0;
    for (i = 1; i < n; i++)
    {
        min = INF;
        for (j = 0; j < n; j++)
        {
            if (flag[j]==0 && dist[j]<min)
            {
                min = dist[j];
                k = j;
            }
        }
        flag[k] = 1;
        for (j = 0; j < n; j++)
        {
            tmp = (matrix[k][j]==INF ? INF : (min + matrix[k][j]));
            if (flag[j] == 0 && (tmp  < dist[j]) )
            {
                dist[j] = tmp;
                prev[j] = k;
            }
        }
    }
        printf("%d", dist[n-1]);
}
