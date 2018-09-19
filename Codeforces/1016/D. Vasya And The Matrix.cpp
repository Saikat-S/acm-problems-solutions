/***************************************************
 * Problem Name : D. Vasya And The Matrix.cpp
 * Problem Link : http://codeforces.com/contest/1016/problem/D
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2018-08-10
 * Problem Type : Edu - D
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
    //~ __FastIO;
    int n, m;
    cin >> n >> m;
    int row[n + 3], col[m + 3];

    for (int i = 0; i < n; i++) {
        cin >> row[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> col[i];
    }

    ll A = row[0];

    for (int i = 1; i < n; i++) A ^= row[i];

    ll B = col[0];

    for (int i = 1; i < m; i++) B ^= col[i];

    if (A != B) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        ll Xor;

        if (i == 0 ) {
            Xor = row[i];

            for (int j = 0; j < m; j++) Xor ^= col[j];

            cout << Xor << " ";

            for (int j = 1; j < m; j++) cout << col[j] << " ";

            nl;
            continue;
        }

        for (int j = 0; j < m; j++) {
            if (j == 0) cout << row[i] << " ";
            else cout << "0 ";
        }

        nl;
    }

    return 0;
}
