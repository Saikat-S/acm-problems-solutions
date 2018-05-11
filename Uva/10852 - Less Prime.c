#include<stdio.h>
#include<math.h>
typedef long long ll;
int prime(ll n){
	ll i,len;
	len = sqrt(n);
	for(i = 2; i<=len; i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
int main()
{
	ll tc,t,num,c,ans,i;
	scanf("%lld", &tc);
	
	for(t = 1; t<=tc ; t++){
		scanf("%lld",&num);
		for(i = num/2+1; ;i++){
			c = prime(i);
			if(c == 1){
				ans = i;
				break;
			}
	    }
	    printf("%lld\n",ans);
	}
	return 0;
}

