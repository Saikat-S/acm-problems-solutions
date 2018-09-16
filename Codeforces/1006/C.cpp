/***************************************************
 * Problem Name : C.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-07-16
 * Problem Type :
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
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
#define pll pair <ll, ll>
#define debug cout <<"#########\n";
#define nl cout << "\n";
#define sp cout << " ";
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define all(v) v.begin(), v.end()
#define pb push_back
#define MAX 100005
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
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
struct st {
    ll val, a, c;
};
bool cmp (st a, st b) {
    return a.val > b.val;
}
int main () {
    __FastIO;
    int n;
    cin >> n;
    ll ar[n + 3];
    ll sum[n + 3];
    ll cum[n + 3];
    sum[0] = 0;
    cum[n + 1] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        sum[i] = sum[i - 1] + ar[i];
    }

    for (int i = n; i >= 1; i--) {
        cum[i] = cum[i + 1] + ar[i];
    }

    st A[n + 3];
    int cnt = 0;

    for (int i = 1, j = n; i < j;) {
        ll x = sum[i];
        ll xx = cum[j];

        if (x == xx) {
            A[cnt].val = x;
            A[cnt].a = i;
            A[cnt].c = j;
            cnt++;
            i++, j--;

        } else if (x > xx) {
            j--;

        } else i++;
    }

    if (cnt == 0) {
        cout << "0\n";

    } else {
        sort (A, A + cnt, cmp);
        cout << A[0].val << "\n";
    }

    return 0;
}
