/***************************************************
 * Problem Name : B. Planning The Expedition.cpp
 * Problem Link : http://codeforces.com/contest/1011/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-07-26
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
int main () {
    __FastIO;
    int n, m;
    cin >> n >> m;
    set<int>st;
    map<int, int>mp;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        st.insert (x);
        mp[x]++;
    }

    if (n > m) {
        cout << "0\n";
        return 0;
    }

    int ans = m / n;

    for (int i = ans; i >= 0; i--) {
        int cnt = 0;

        for (auto it  = st.begin(); it != st.end(); it++) {
            int val = *it;

            if (mp[val] >= i) {
                int x = mp[val] / i;
                cnt += x;
            }

            if (cnt >= n) {
                cout << i << "\n";
                return 0;
            }
        }
    }

    return 0;
}
