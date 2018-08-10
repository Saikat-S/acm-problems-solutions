/***************************************************
 * Problem Name : 12100 - Printer Queue.cpp
 * Problem Link : https://uva.onlinejudge.org/external/121/12100.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-07-17
 * Problem Type : STL
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
ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
bool cmp (pii a, pii b) {
    if (a.second == b.second ) return a.first < b.first;
    else return a.second > b.second ;
}
int main () {
    __FastIO;
    int tc, n, m;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n >> m;
        //~ int ar[n + 3];
        queue<pii>q;
        vector<pii>v;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            q.push (pii (i, x) );
            v.pb (pii (i, x) );
        }

        sort (all (v), cmp);
        //~ for (int i = 0; i < n; i++) {
        //~ cout << v[i].second << " " << v[i].first << "\n";
        //~ }
        int i = 0, ans;

        while (!q.empty() ) {
            pii top = q.front();
            q.pop();

            if (top.second == v[i].second) {
                i++;

                if (top.first == m) {
                    ans = i;
                    break;
                }

            } else {
                q.push (top);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
