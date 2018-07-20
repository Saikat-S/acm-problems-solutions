#include<stdio.h>
#define MAX 10005
int main()
{
    int tc,i,n,j,k;
    int arr[MAX],a[MAX];

    scanf("%d", &tc);

    for(i = 1; i<=tc ; i++) {

        scanf("%d", &n);
        arr[1] = 1, arr[2] = 4,arr[3] = 12;

        if(n == 1) {
            printf("%d\n",arr[1]);
        }
        else if(n == 2) {
            printf("%d\n",arr[2]);
        }
        else if(n == 3){
			printf("%d\n",arr[3]);
		}
        else {
			a[1] = 8;
            for(j = 4,k=2; j<=n; j++,k++) {
				 a[k] = a[k-1]*2;
				 arr[j] = a[k] + arr[j-1];
            }
             printf("%d\n",arr[n]);
        }
       
    }
    return 0;
}

