#include<stdio.h>
#include<string.h> //for strlen()
int main()
{
    int n;
    printf("Enter the number of frames: ");
    scanf("%d",&n);
    int frames[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the max size of frame[%d]: ",i+1);
        scanf("%d",&frames[i]);
    }
    char s[n][50];
    for(int i=0;i<n;i++)
    {
        printf("Enter the String: ");
        scanf("%s",&s[i]);    //%[^\n]
        if(strlen(s[i]) > frames[i])
        {
            printf("Enter a string less than %d :",frames[i]);
            scanf("%s",&s[i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<strlen(s[i]);j++)
        {
            count++;
        }
        printf("Character count in frame %d is %d\n",i+1,count);
    }
}
