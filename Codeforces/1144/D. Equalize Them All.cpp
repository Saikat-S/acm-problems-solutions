/***************************************************
 * Problem Name : D. Equalize Them All.cpp
 * Problem Link : https://codeforces.com/contest/1144/problem/D
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-03-31
 * Problem Type : Div 3 - D
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
struct st {
    int q, ii, jj;
    st (int _q, int _ii, int _jj) {
        q = _q;
        ii = _ii;
        jj = _jj;
    }
};
int main () {
    //~ __FastIO;
    int n;
    int ar[MAX];
    cin >> n;
    map<int, int>mp;
    int mx = -1, ans = -1;
    int pos = -1;

    for (int i = 0 ; i < n; i++) {
        cin >> ar[i];
        mp[ar[i]]++;

        if (mp[ar[i]] >= mx) {
            mx = mp[ar[i]];
            ans = ar[i];
            pos = i;
        }
    }

    if (mx == n) {
        cout << 0 << "\n";
        exit (0);
    }

    vector<st>vec;

    for (int i = pos; i >= 0; i--) {
        if (ar[i] != ans) {
            if (ar[i] > ans) {
                vec.pb (st (2, i, i + 1) );

            } else {
                vec.pb (st (1, i, i + 1) );
            }
        }
    }

    for (int i = pos; i < n; i++) {
        if (ar[i] != ans) {
            if (ar[i] > ans) {
                vec.pb (st (2, i, i - 1) );

            } else {
                vec.pb (st (1, i, i - 1) );
            }
        }
    }

    cout << (int) vec.size() << "\n";

    for (int i = 0; i < (int) vec.size(); i++) {
        cout << vec[i].q << " " << vec[i].ii + 1 << " " << vec[i].jj + 1 << "\n";
    }

    return 0;
}
