/***************************************************
 * Problem Name : B.cpp
 * Problem Link : https://codeforces.com/contest/1102/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-01-09
 * Problem Type : Div 3 - B
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
#define Pow2(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 5005
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
int main () {
    //~ __FastIO;
    int n, k;
    cin >> n >> k;
    int ar[MAX];
    int cr[MAX];
    int cnt[MAX];
    SET (cnt, 0);
    int mx = 0;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        cnt[ar[i]]++;
        mx = max (mx, cnt[ar[i]]);
    }

    if (mx > k) {
        cout << "NO\n";

    } else {
        map<pii, int>chk;

        for (int i = 0; i < k; i++) {
            cr[i] = i + 1;
            chk[pii (ar[i], cr[i])] = 1;
        }

        for (int i = k; i < n; i++) {
            int x = ar[i];
            int y;

            for (int j = 1; j <= k; j++) {
                if (chk[pii (x, j)] == 0) {
                    y = j;
                    chk[pii (x, j)] = 1;
                    break;
                }
            }

            cr[i] = y;
        }

        cout << "YES\n";

        for (int i = 0; i < n; i++) {
            cout << cr[i] << " ";
        }

        nl;
    }

    return 0;
}
