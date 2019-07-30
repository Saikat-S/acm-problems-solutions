/***************************************************
 * Problem Name : D. Prime Graph.cpp
 * Problem Link : https://codeforces.com/contest/1178/problem/D
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-07-21
 * Problem Type : CF GR - D
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
#define __FileRead freopen ("input.txt", "r", stdin);
#define __FileWrite freopen ("output.txt", "w", stdout);
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
#define MAX 500005
#define INF 1000000000
#define MOD 1000000007
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
vector<int>prime;
char ar[MAX];
void seive (int n) {
    ar[1] = 1;

    for (int i = 4; i < MAX; i += 2) ar[i] = 1;

    int sq = (int) sqrt (MAX);

    for (int i = 3; i <= sq; i++) {
        for (int j = i + i; j < MAX; j += i) {
            ar[j] = 1;
        }
    }

    for (int i = 1; i < MAX; i++) {
        if (ar[i] == 0) prime.pb (i);
    }
}

int main () {
    __FastIO;
    seive (MAX);
    int n;
    cin >> n;
    int m = (n * (n - 1) ) / 2;

    for (int i = 0; i < (int) prime.size(); i++) {
        vector<pii>adj;

        if (prime[i] <= m && prime[i] >= n) {
            map<int, int>mp;

            for (int j = 1; j <= n; j++) {
                if (j == n) {
                    adj.pb ({j, 1});
                    mp[j]++;
                    mp[1]++;

                } else {
                    adj.pb ({j, j + 1});
                    mp[j]++;
                    mp[j + 1]++;
                }
            }

            int xx  = prime[i] - n;

            for (int j = 2, k = n; xx > 0 && j <= n / 2; j++, k--) {
                adj.pb ({j, k});
                mp[j]++;
                mp[k]++;
                xx--;

                if (xx <= 0) break;
            }

            if (xx > 0) {
                adj.pb ({1, n / 2 + 1});
            }

            int f = 0;

            for (int i = 1; i <= n; i++) {
                if (ar[mp[i]] == 1) {
                    f = 1;
                    break;
                }
            }

            if (!f) {
                cout << (int) adj.size() << "\n";

                for (int j = 0; j < (int) adj.size(); j++) {
                    cout << adj[j].first << " " << adj[j].second << "\n";
                }

                exit (0);
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}
