#include<stdio.h>
int main()
{
    int num;

    while(scanf("%d",&num)==1)
    {
        if(num==42)
        {
            break;
        }
        printf("%d\n",num);
    }

    return 0;
}
