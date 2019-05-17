/***************************************************
 * Problem Name : BB.cpp
 * Problem Link : https://codeforces.com/contest/1163/problem/B/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-05-09
 * Problem Type : Div 2 - B,C
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
#define MAX 100005
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
    __FastIO;
    int n;
    int ar[MAX];
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }

    int uni = 0, ans = 0;
    int mp[MAX];
    SET (mp, 0);
    multiset<int>st;

    for (int i = 1; i <= n; i++) {
        int x = ar[i];
        int pre = mp[x];

        if (pre != 0) {
            auto it = st.lower_bound (pre);

            if (it != st.end() ) {
                st.erase (it);
            }
        }

        if (mp[x] == 0) {
            auto it = st.begin();

            if (it != st.end() ) {
                int cnt = *it;
                int tmp = cnt * uni;

                if (tmp == (i - 1) ) {
                    ans = max (ans, i);
                }
            }

            mp[x]++;
            uni++;

        } else {
            mp[x]++;
        }

        st.insert (mp[x]);
        auto it = st.begin();
        int cnt = *it;
        int tmp = (cnt * uni);

        if ( (i - tmp) == 1) {
            ans = max (ans, i);
        }

        if (cnt == 1) {
            it++;

            if (it != st.end() ) {
                cnt = *it;
                int tmp = (cnt * (uni - 1) );

                if (tmp == (i - 1) ) {
                    ans = max (ans, i);
                }
            }
        }
    }

    if ( (int) st.size() == 1) {
        ans = n;
    }

    cout << ans << "\n";
    return 0;
}
