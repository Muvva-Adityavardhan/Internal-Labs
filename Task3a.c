#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void dijkstra(int graph[9][9], int src);
int minDist(int dist[], int sptSet[]);
void printSolution(int dist[]);
int main()
{

    int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 0, 10, 0, 2, 0, 0},
        {0, 0, 0, 14, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    dijkstra(graph, 0);
    return 0;
}
void dijkstra(int v[9][9],int src)
{
    int dist[9],sptSet[9];
    for(int i=0;i<9;i++){
        dist[i]=INT_MAX;
        sptSet[i]=0;
    }
    dist[src]=0;
    for(int i=0;i<9;i++)
    {
        int u = minDist(dist,sptSet);
        sptSet[u]=1;
        for(int j=0;j<9;j++)
            if(!sptSet[j] && v[u][j] && dist[j]>dist[u]+v[u][j])dist[j]=dist[u]+v[u][j];

    }
    printSolution(dist);
}
int minDist(int dist[], int sptSet[])
{
    int min = INT_MAX,min_index;
    for(int i=0;i<9;i++)
    {
        if(sptSet[i]==0 && dist[i] < min)
            min = dist[i],min_index=i;

    }
    return min_index;
}
void printSolution(int dist[])
{
    printf("Vertex  Distance from src\n");
    for(int i=0;i<9;i++)
        printf("%d\t\t%d\n",i,dist[i]);
}
