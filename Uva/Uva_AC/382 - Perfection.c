#include<stdio.h>
int main()
{
    int n, i,j,sum;
    int arr[1000];

    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&n)== 1 && n>0)
    {
        j = 0;
        sum = 0;
        for(i = 1; i<n; i ++)
        {
            if(n%i == 0)
            {
                arr[j++] = i;
            }
        }

        for(i = 0 ; i<j; i++)
        {
            sum = sum + arr[i];
        }
        if(sum == n)
        {
            printf("%5d  PERFECT\n",n);
        }
        else if(sum>n)
        {
            printf("%5d  ABUNDANT\n",n);
        }
        else if(sum<n)
        {
            printf("%5d  DEFICIENT\n",n);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
