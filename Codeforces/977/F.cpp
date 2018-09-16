/***************************************************
 * Problem name : F.cpp
 * OJ           :
 * Verdict      : Trying
 * Date         : 2018-05-06
 * Problem Type :
 * Author Name  : Saikat Sharma
 * University   : CSE,MBSTU
 ***************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<vector>
#include<queue>
#include<cstdlib>
#include<deque>
#include<stack>
#include<map>
#include<set>
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sp printf(" ")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define pb push_back
#define MAX 200005
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
/************************************ Code Start Here ******************************************************/
ll L[MAX], I[MAX];
int LIS_NlogK(ll n , ll ar[]) {
    I[0] = -1000000005;
    for (int i = 1; i <= n; i++) {
        I[i] = 1000000005;
    }
    int Maxlen = 0;
    for (int i = 0; i < n; i++) {
        int low = 0, high = Maxlen, mid;
        while (high >= low) {
            mid = (low + high) / 2;
            if (I[mid] <  ar[i]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        I[low] = ar[i];
        L[i] = low;
        if (Maxlen < low) {
            Maxlen = low;
        }
    }
    return Maxlen;
}
void LIS_Solution(int ar[], int n) {
    vector<int>Sol;
    int i = 0;
    for (int j = 1 ; j < n; j++) {
        if (L[j] >= L[i]) {
            i = j;
        }
    }
    Sol.push_back(ar[i]);
    int top = i;
    for (int i = top - 1; i >= 0; i--) {
        if ( ar[i] < ar[top] && L[i] == L[top] - 1) {
            Sol.push_back(ar[i]);
            top = i;
        }
    }
    int sz = Sol.size();
    for (int i = sz - 1 ; i >= 0; i--) {
        printf("%d ", Sol[i]);
    }
    printf("\n");
}
int main () {
    //~ __FastIO;
    int n;
    ll ar[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &ar[i]);
    }
    int ans = LIS_NlogK(n, ar);
    printf("%d\n", ans);
    return 0;
}
