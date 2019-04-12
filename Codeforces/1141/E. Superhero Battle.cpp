/***************************************************
 * Problem Name : E. Superhero Battle.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2019-03-20
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
#define __FileRead freopen ("/home/saikat/Desktop/logN/input.txt", "r", stdin);
#define __FileWrite freopen ("/home/saikat/Desktop/logN/output.txt", "w", stdout);
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
#define MAX 200005
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
ll H;
ll binary (ll val) {
    ll low = 1LL, high = 1000000000000000005LL;
    ll ans = 0;

    while (high >= low) {
        ll mid = (high + low+1LL) / 2LL;

        if (mid * val >= H) {
            high = mid - 1LL;

        } else {
            low = mid + 1LL;
            ans = mid;
        }
    }

    return ans;
}	

int main () {
    //~ __FastIO;
    ll n;
    ll ar[MAX];
    cin >> H >> n;
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        sum += ar[i];
    }

    ll hh = H;
    ll cnt = 0;

    for (int i = 0; i < n; i++) {
        hh  = hh - (ar[i] * -1LL);
        cnt++;

        if (hh <= 0) {
            cout << cnt << "\n";
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        hh = hh - (ar[i] * -1LL);
        cnt++;

        if (hh <= 0) {
            cout << cnt << "\n";
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        hh = hh - (ar[i] * -1LL);
        cnt++;

        if (hh <= 0) {
            cout << cnt << "\n";
            return 0;
        }
    }

    if (sum >= 0) {
        cout << -1 << "\n";

    } else {
        //~ cout << sum << "\n";
        sum = sum * -1LL;
        ll ans = binary (sum);
        ans -= 3;
        //~ cout << ans << "\n";
        ll val = sum * ans;
        cnt = ans * n;

        //~ cout << val << "\n";
        while (val < H) {
            for (int i = 0; i < n; i++) {
                if (val >= H) {
					cout << cnt << "\n";
                    //~ break;
                    //~ assert(false);
                    return 0;
                }

                val = val + (ar[i] * -1);
                cnt++;
                //~ cout << val << " "<< ar[i] <<"\n";
            }
        }
    }

    return 0;
}
