#include<stdio.h>
int main()
{
    int tc,i,a,b;
 
    scanf("%d",&tc);
 
    for(i=1;i<=tc;i++)
    {
        scanf("%d",&a);
 
        b= a/2;
        a= a%2+a/2;
 
        printf("%d %d\n",a,b);
    }
 
    return 0;
}
