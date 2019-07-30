/***************************************************
 * Problem Name : B. Sport Mafia.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2019-07-17
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
#define INF 1000000007
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
ll get (ll n) {
    return (n * (n + 1LL) ) / 2LL;
}
ll nTh (ll sm) {
    ll NN = 8LL * sm + 1LL;
    NN = sqrt (NN) - 1LL;
    NN /= 2LL;
    ll SM = (NN * ( NN + 1LL ) ) / 2LL;

    if (SM < sm) NN++;

    return NN;
}

ll binary (ll n, ll k) {
    ll low = 0, high = INF;
    ll ans ;

    while (high >= low) {
        ll mid = (high + low) / 2LL;

        if (mid + nTh(mid)+k == n) {
            ans = mid;
            break;

        } else if ( (mid + k) > n) {
            high = mid - 1LL;

        } else {
            low = mid + 1LL;
        }
    }

    return ans;
}

ll bi (ll n) {
    ll low = 0, high = INF;
    ll ans;

    while (high >= low) {
        ll mid = (high + low) / 2LL;

        if (mid + nTh (mid) == n) {
            ans = mid;
            break;

        } else if ( (mid + nTh (mid) > n) ) {
            high = mid - 1LL;

        } else {
            low = mid + 1LL;
        }
    }

    return ans;
}

int main () {
    __FastIO;
    ll n, k;
    cin >> n >> k;

    if (k == 0) {
        cout << bi (n) << "\n";

    } else {
        ll x = nTh (k);
        //~ cout << x << "\n";
        cout << binary (n, x) << "\n";
    }

    return 0;
}
