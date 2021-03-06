/***************************************************
 * Problem Name : B. Yet Another Array Partitioning Task.cpp
 * Problem Link : https://codeforces.com/contest/1114/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-05-07
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll>vec (n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    vector<ll>tmp = vec;
    sort (tmp.rbegin(), tmp.rend() );
    ll sum  = 0;
    multiset<ll>st;

    for (int i = 0; i < (m * k); i++) {
        sum += tmp[i];
        st.insert (tmp[i]);
    }

    vector<int>ans;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        auto it = st.find (vec[i]);

        if (it != st.end() ) {
            st.erase (it);
            cnt++;

            if (cnt == m) {
                ans.pb (i + 1);
                cnt = 0;
            }
        }
    }

    cout << sum << "\n";

    for (int i = 0; i < (int) ans.size() - 1; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
