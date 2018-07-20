#include<iostream>
#include<cstdio>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
int main()
{
    ll n,x,mx;
    while(scanf("%lld", &n)==1 && n!=0) {
        map<ll,ll>mp;
        set<ll>st;
        mx=0;
        for(ll i = 1; i<=n; i++) {
            scanf("%lld",&x);
            if(mp[x] == 0) {
                st.insert(x);
            }
            if(mx<x)
            {
                mx=x;
            }
            mp[x]+=1;
        }
        //~ map<int,int>::iterator it;
        set<ll>::iterator it;
        ll y;
        for(it = st.begin(); it!= st.end(); it++) {
            y = mp[*it];
            for(ll i = 1; i<=y; i++) {
                printf("%lld", *it);
                if(i==y && *it == mx){
                    printf("\n");
                }
                else printf(" ");
            }
        }
    }
    return 0;
}

