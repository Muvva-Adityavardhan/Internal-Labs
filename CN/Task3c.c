#include<stdio.h>
#include<stdlib.h>
int main()
{
    int bucket = 10;
    int tokens = 0;
    int token_rate=3;
    int interval_time=1;
    int required_tokens=4;
    int queries=6;
    int packet_size[6]={4,6,8,2,1,5};
    int queue=0;
    for(int i=0;i<queries;i++)
    {
        tokens += token_rate * interval_time;
        printf("Number of tokens present in the bucket %d\n",tokens);
        int n = packet_size[i];
        if(tokens < n)
        {
            printf("Not enough tokens, queuing the packet of size %d\n",n);
            queue+=n;
        }
        else
        {
            tokens-=required_tokens;
            printf("Processed Packet of size %d, Remaining Tokens in bucket are %d\n",n,tokens);
            while(queue > 0 && tokens >= required_tokens)
            {
                printf("Processing queued packet of size %d",queue);
                tokens -= required_tokens;
                queue=0;
            }
        }
    }
    printf("Tokens in bucket %d\n",tokens);
    printf("Packets in Queue %d\n",queue);
}
