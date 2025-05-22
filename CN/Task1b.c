#include<stdio.h>
#include<string.h> //for strlen()
int main()
{
    char a[20],b[50],ch;
    int pos,n;
    printf("Enter the string:");
    scanf("%s",&a);
    n = strlen(a);
    printf("Enter the Position to add stuff bits:");
    scanf("%d",&pos);
    if(pos > n){
        printf("Please enter a position < %d",n);
        scanf("%d",&pos);
    }
    printf("Enter the character to stuff:");
    //scanf(" %c",&ch);
    ch = getche();
    printf("\n");
    b[0]='d';b[1]='l';b[2]='e';b[3]='s';b[4]='t';b[5]='x';
    int k=6,i=0;
    for(int i=0;i<pos-1;i++) b[k++]=a[i];
    b[k]='d';b[k+1]='l';b[k+2]='e';b[k+3]=ch;b[k+4]='d';b[k+5]='l';b[k+6]='e';
    k+=7;
    for(int i=pos;i<n;i++){
        b[k++]=a[i];
    }
    b[k]='d';b[k+1]='l';b[k+2]='e';b[k+3]='e';b[k+4]='t';b[k+5]='x';b[k+6]='\0';
    printf("The new String is:");
    printf("%s",b);
}
