#include<stdio.h>
int main()
{
	int sum,dif,i,tc,n,check;
	
	scanf("%d", &tc);
	
	while(tc--){
		scanf("%d %d", &sum,&dif);
		n = sum,check = 1;
		if(sum<dif){
			printf("impossible\n");
		}
		else if(sum == dif){
			printf("%d 0\n",sum);
		}
		else{
			for(i = 1; i<= n; i++){
				sum--;
				if((sum - i) == dif){
					check = 0;
					printf("%d %d\n",sum,i);
					break;
				}
			}
			if(check) printf("impossible\n");
		}
	}
	return 0;
}
