/***************************************************
 * Problem name : Noora Number.cpp
 * Problem Link : https://toph.co/p/noora-number
 * OJ           : Toph
 * Verdict      : AC
 * Date         : 2019-01-30
 * Problem type : digitDP
 * Author name  : Saikat Sharma
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
int n;
ll dp[23][2][2][13][1803];
vector<int>B;

int setBit (int mask, int pos) {
    return mask = mask | (1 << pos);
}

ll digitDP (int pos, int isChoto, int isSuru, int mx, int mask) {
    if (pos == 20) {
        int cnt = __builtin_popcount (mask);

        if (cnt == mx && isSuru == 1) {
            //~ cout << str << " cnt : " << cnt  << " mx : "<< mx <<"  --\n";
            return 1LL;

        } else {
            return 0LL;
        }
    }

    ll &ans = dp[pos][isChoto][isSuru][mx][mask];

    if (ans != -1 && isChoto == 1) {
        return ans;
    }

    ans = 0;
    int low = 0, high = 9;

    if (isChoto == 0) high = B[pos];

    for (int i = low; i <= high; i++) {
        int newMask = mask;
        if(isSuru == 1 || i>0){
			newMask = setBit(newMask, i);
		}
        ans += digitDP (pos + 1, isChoto || (i < high), isSuru
                        || (i > 0), max (mx, i), newMask);
    }

    return ans;
}

ll solve (ll b) {
    B.clear();

    while (b > 0) {
        int rem = b % 10;
        B.pb (rem);
        b /= 10;
    }
    while((int)B.size()<20){
		B.pb(0);
	}
    reverse (all (B) );
    n = (int) B.size();
    //~ SET (dp, -1);
    ll ans = digitDP (0, 0, 0, 0, 0);
    return ans;
}
int main () {
    __FastIO;
    SET(dp, -1);
    int tc;
    cin >> tc;

    while (tc--) {
        ll a;
        cin >> a;
        ll ans = solve (a);
        cout << ans << "\n";
    }

    return 0;
}
