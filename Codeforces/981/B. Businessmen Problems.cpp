/***************************************************
 * Problem Name : B. Businessmen Problems.cpp
 * Problem Link : http://codeforces.com/contest/981/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-07-26
 * Problem Type : Div 2- B
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
    int id, v;
};
bool cmp (st a, st b) {
    return a.v  > b.v;
}
int main () {
    __FastIO;
    int n, m;
    st ar[MAX], br[MAX];
    map<int, int>A;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, v;
        cin >> x >> v;
        ar[i].id = x;
        ar[i].v = v;
        A[x] = v;
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int x, v;
        cin >> x >> v;
        br[i].id = x;
        br[i].v = v;
        A[x] = max (A[x], v);
    }

    sort (ar, ar + n, cmp);
    sort (br, br + m, cmp);
    ll sum = 0;
    map<int, int>mp;

    for (int i = 0; ; i++) {
        if (i >= n && i >= m) break;

        if (i < n && i < m) {
            if (ar[i].id == br[i].id && mp[ar[i].id] == 0) {
                sum += A[br[i].id];
                mp[br[i].id] = 1;

            } else {
                if (mp[ar[i].id] == 0) {
                    sum += A[ar[i].id];
                    mp[ar[i].id] = 1;
                }

                if (mp[br[i].id] == 0) {
                    sum += A[br[i].id];
                    mp[br[i].id] = 1;
                }
            }

        } else if ( i < n && mp[ar[i].id] == 0) {
            sum += A[ar[i].id];
            mp[ar[i].id] = 1;

        } else if ( i < m && mp[br[i].id] == 0) {
            sum += A[br[i].id];
            mp[br[i].id] = 1;
        }
    }

    cout << sum << "\n";
    return 0;
}
