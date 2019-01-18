/***************************************************
 * Problem Name : B. Build a Contest.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-01-13
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
#define Pow2(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
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
int main () {
    __FastIO;
    int n, m;
    int ar[MAX];
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> ar[i];
    }

    int chk[MAX];
    SET (chk, 0);
    vector<int>vec;
    int cnt = 0;
    int ans = 0;

    for (int i = 0; i < m; i++) {
        int x = ar[i];

        if (chk[x] == 0) {
            cnt++;
            chk[x]++;

        } else {
            chk[x]++;
        }

        if (cnt >= n) {
            ans++;
            vec.pb (1);

            for (int j = 1; j <= n; j++) {
                chk[j]--;

                if (chk[j] == 0) cnt--;
            }

        } else {
            vec.pb (0);
        }
    }

    for (int i = 0; i < m ; i++) {
        cout << vec[i];
    }

    nl;
    return 0;
}
