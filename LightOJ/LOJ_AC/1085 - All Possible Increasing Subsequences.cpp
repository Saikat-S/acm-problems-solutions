/***************************************************
 * Problem Name : 1085 - All Possible Increasing Subsequences.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1085
 * OJ           : LightOJ
 * Verdict      : AC
 * Date         : 2018-09-30
 * Problem Type : Data Structure (segement tree)
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
ll tree[MAX * 3];
ll query (ll nod, ll low, ll high, ll qlow, ll qhigh) {
    if (low > high || qlow > high || qhigh < low) return 0;

    if (low >= qlow && high <= qhigh) {
        return tree[nod];
    }

    ll q1 = query (nod * 2, low, (high + low) / 2, qlow, qhigh);
    ll q2 = query (nod * 2 + 1, (high + low) / 2 + 1, high, qlow, qhigh);
    return (q1 + q2) % MOD;
}
void update (ll nod, ll low, ll high, ll pos, ll val) {
    if (low > high || pos > high || pos < low) return ;

    if (low >= pos && high <= pos) {
        tree[nod] += val;
        return ;
    }

    update (nod * 2, low, (high + low) / 2, pos, val);
    update (nod * 2 + 1, (high + low) / 2 + 1, high, pos, val);
    tree[nod] = (tree[nod * 2] + tree[nod * 2 + 1]) % MOD;
}
int main () {
    //~ __FastIO;
    int tc, n;
    scanf ("%d", &tc);

    for (int t  = 1; t <= tc; t++) {
        scanf ("%d", &n);
        ll ar[n + 5];
        set<ll>st;

        for (int i = 0; i < n; i++) {
            scanf ("%lld", &ar[i]);
            st.insert (ar[i]);
        }

        set<ll>::iterator it;
        map<ll, int>mp;
        int k = 1;

        for (it = st.begin(); it != st.end(); it++) {
            if (mp[*it] == 0) {
                mp[*it] = k++;
            }
        }

        k--;
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            ll val = query (1, 1, k, 1, mp[ar[i]] - 1);
            val++;
            ans = (ans + val) % MOD;
            update (1, 1, k, mp[ar[i]], val);
        }

        printf ("Case %d: %lld\n", t, ans);
        SET (tree, 0);
    }

    return 0;
}
