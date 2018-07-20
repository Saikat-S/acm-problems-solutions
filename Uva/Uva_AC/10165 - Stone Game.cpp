#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int main()
{
	ll n,x,sum;
	while(scanf("%lld", &n) == 1 && n!=0){
		sum = 0;
		for(int i = 1; i<=n ; i++){
			scanf("%lld", &x);
			sum^=x;
			printf("%lld ", sum);
		}
		if(sum){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}
