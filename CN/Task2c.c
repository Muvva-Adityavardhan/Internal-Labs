#include<stdio.h>
#include<stdbool.h>
int main()
{
    int start=0,sent=0,ack=0,count=0,windowsize,frames;
    printf("Enter the total number of frames:");
    scanf("%d",&frames);
    printf("Enter the windowsize:");
    scanf("%d",&windowsize);
    bool ackrec[frames];
    for(int i=0;i<frames;i++) ackrec[i]=false;
    while(sent < frames)
    {
        for(int i=0;i<windowsize && (start+i)<frames;i++)
        {
            printf("Sending frame %d\n",start+i);
            sent++;
        }
        do{
            for(int i=0;i<windowsize && (start+i)<frames;i++)
            {
                if(!ackrec[start+i])
                {
                    printf("Acknowledgment for frame %d is:",start+i);
                    scanf("%d",&ack);
                    if(ack == start+i)
                    {
                        count++;
                        ackrec[start+i]=true;
                    }
                }
            }
            for(int i=0;i<windowsize && (start+i)<frames;i++)
            {
                if(!ackrec[start+i]){
                    printf("Resending frame %d\n",start+i);
                }
            }
        }while(count < sent);
        start=sent;
    }
    printf("ALL FRAMES HAVE BEEN SENT\n");
}
