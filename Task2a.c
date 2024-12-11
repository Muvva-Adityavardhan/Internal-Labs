#include<stdio.h>
#include<stdlib.h> //for rand()
int main()
{
    int n=10;
    printf("The number of frames is : %d\n",n);
    int i=1,j=1;
    while(n > 0)
    {
        printf("\nSending Frame %d\n",i);
        int x = rand()%10;
        if(x%10 == 0)
        {
            printf("Waiting for Acknowledgement %d seconds\n",1);
            printf("Resending the frame %d\n",i);
        }
        printf("Acknowldegement for frame %d\n",j);
        n--;
        i++;
        j++;
    }
}
