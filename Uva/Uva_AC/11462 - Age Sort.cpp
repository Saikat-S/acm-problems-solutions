#include<iostream>
#include<cstdio>
#define MAX 2000000
using namespace std;
typedef long long ll;
ll ar[MAX];
ll total_node;
void max_heapify(int par) {
    ll L = 2*par;
    ll R = 2*par + 1;
    if(R<=total_node) {
        if(ar[R]>=ar[L] && ar[R]>ar[par]) {
            swap(ar[par],ar[R]);
            max_heapify(R);
        }
        else if(ar[L]>=ar[R] && ar[L]>ar[par]) {
            swap(ar[par],ar[L]);
            max_heapify(L);
        }
    }
    else if(L<=total_node) {
        if(ar[L]>ar[par]) {
            swap(ar[par],ar[L]);
            max_heapify(L);
        }
    }
}
void heapSort(void) {
    for(ll i = total_node; i>=1; i--) {
        swap(ar[1],ar[i]);
        total_node--;
        max_heapify(1);
    }
}
int main()
{
    while(scanf("%lld", &total_node) == 1 && total_node!=0) {

        ll n = total_node;
        for(ll i = 1; i<=total_node; i++) {
            scanf("%lld", &ar[i]);
        }
        for(ll i = total_node/2; i>=1; i--) {
            max_heapify(i);
        }
        heapSort();
        for(ll i = 1; i<=n; i++) {
			if(i == n) printf("%lld\n",ar[i]);
            else printf("%lld ", ar[i]);
        }
    }
    return 0;
}

