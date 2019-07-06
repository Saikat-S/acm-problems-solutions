/***************************************************
 * Problem Name : B. Pairs.cpp
 * Problem Link : https://codeforces.com/contest/1169/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-05-28
 * Problem Type : Div 2 - B
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
#define MAX 300005
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
int main () {
    //~ __FastIO;
    int n, m;
    cin >> n >> m;
    vector<pii>vec;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        vec.pb (pii (x, y) );
    }

    sort (all (vec) );
    int x = vec[0].first;
    int cnt = 1;
    bool vis[MAX];
    bool vis1[MAX];
    SET (vis, 0);
    SET (vis1, 0);
    pii top;

    for (int i = 1; i < m; i++) {
        int f = vec[i].first;
        int s = vec[i].second;

        if (f == x || s == x) {
            cnt++;
            vis[i] = true;
            vis1[i] = true;

        } else {
            top = vec[i];
        }
    }

    int y = top.first;
    int cnt1 = 0;

    for (int i = 1; i < m; i++) {
        int f = vec[i].first;
        int s = vec[i].second;

        if (vis[i] == false) {
            if (f == y || s == y) {
                cnt1++;
            }
        }
    }

    if (cnt + cnt1 == m) {
        cout << "YES\n";
        exit (0);
    }

    y = top.second;
    cnt1 = 0;

    for (int i = 1; i < m; i++) {
        int f = vec[i].first;
        int s = vec[i].second;

        if (vis1[i] == false) {
            if (f == y || s == y) {
                cnt1++;
            }
        }
    }

    if (cnt + cnt1 == m) {
        cout << "YES\n";
        exit (0);
    }

    // second part as x = vec[0].second
    x = vec[0].second;
    cnt = 1;
    SET (vis, 0);
    SET (vis1, 0);

    for (int i = 1; i < m; i++) {
        int f = vec[i].first;
        int s = vec[i].second;

        if (f == x || s == x) {
            cnt++;
            vis[i] = true;
            vis1[i] = true;

        } else {
            top = vec[i];
        }
    }

    y = top.first;
    cnt1 = 0;

    for (int i = 1; i < m; i++) {
        int f = vec[i].first;
        int s = vec[i].second;

        if (vis[i] == false) {
            if (f == y || s == y) {
                cnt1++;
            }
        }
    }

    if (cnt + cnt1 == m) {
        cout << "YES\n";
        exit (0);
    }

    y = top.second;
    cnt1 = 0;

    for (int i = 1; i < m; i++) {
        int f = vec[i].first;
        int s = vec[i].second;

        if (vis1[i] == false) {
            if (f == y || s == y) {
                cnt1++;
            }
        }
    }

    if (cnt + cnt1 == m) {
        cout << "YES\n";
        exit (0);
    }

    cout << "NO\n";
    return 0;
}
