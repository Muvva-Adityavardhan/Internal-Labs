#include<stdio.h>
#include<stdlib.h>
struct node
{
    int dist[20];
    int from[20];
}rt[10];
int main()
{
    int dmat[20][20],n,count=0;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    printf("Enter the cost matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&dmat[i][j]);
            dmat[i][i]=0;
            rt[i].dist[j]=dmat[i][j];
            rt[i].from[j]=j;
        }
    }
    do
    {
        count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(rt[i].dist[j] > dmat[i][k]+rt[k].dist[j])
                    {
                        rt[i].dist[j] = rt[i].dist[k]+rt[k].dist[j];
                        rt[i].from[j]=j;
                        count++;
                    }
                }
            }
        }
    }while(count != 0);
    for(int i=0;i<n;i++)
    {
        printf("\n\nState Value for Router %d is \n",i+1);
        for(int j=0;j<n;j++)
        {
            printf("Node %d via %d the distance = %d\n",j+1,rt[i].from[j]+1,rt[i].dist[j]);
        }
        printf("\n");
    }
}
