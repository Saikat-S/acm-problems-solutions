#include<stdio.h>
#include<math.h>
int rec (int n)
{
	if (n==1) return 1;
	if (n==2) return 4;
	if(n==3) return 12;
	else{
		return pow(2,n)+ rec(n-1);
	}
	
}
int main()
{
	int n,tc,i;
	scanf("%d", &tc);
	for(i= 1; i<=tc; i++){
		scanf("%d", &n);
		printf("%d\n",rec(n));
	}
    return 0;	
}


