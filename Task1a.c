#include<stdio.h>
int main()
{
    int a[20],b[30],n;
    printf("Enter the frame length:");
    scanf("%d",&n);
    printf("Enter the data(0 and 1s only):");
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int i=0,count=0,j=0;
    while(i<n)
    {
        if(a[i]==1)
        {
            count++;
            if(count==6){
                b[j++]=0;
                count=0;
            }
            b[j]=a[i];
        }
        else{
            b[j]=a[i];
            count=0;
        }
        i++;j++;
    }
    printf("After stuffing the frame:");
    for(int i=0;i<j;i++) printf("%d ",b[i]);
}
