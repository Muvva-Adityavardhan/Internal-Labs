#include<stdio.h>
int main()
{
    int frames,windowsize;
    int start=0,sent=0,ack=0,i;
    printf("Enter the total number of frames : ");
    scanf("%d",&frames);
    printf("Enter the window size : ");
    scanf("%d",&windowsize);
    if(windowsize <= 0 || frames <= 0 || windowsize > frames){
        printf("Invalid Window size and Total number of frames\n");
        return 1;
    }
    while(sent < frames)
    {
        for(i=0;i<windowsize && (start+i)<frames;i++)
        {
            printf("Frame %d has been transmitted\n",start+i);
        }
        printf("Please enter the last acknowledgment received (0 to %d):",start+i-1);
        scanf("%d",&ack);
        if(ack < 0 || ack > start+i-1)
        {
            printf("Invalid acknowledgment received: Enter again!!!\n");
            printf("Please enter the last acknowledgment received (0 to %d):",start+i-1);
            scanf("%d",&ack);
        }
        printf("Acknowledgment %d Received\n",ack);
        start = ack+1;
        sent = start;
    }
}
