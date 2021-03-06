/***************************************************
 * Problem Name : C.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-09-06
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
    int n;
    cin >> n;
    ll a[n + 3], b[n + 3];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort (a, a + n );
    sort (b, b + n);
    ll A = 0, B = 0;

    for (int i = n - 1, ii = n - 1;;) {
        if (i >= 0 && ii >= 0) {
            if (a[i] >= b[ii]) {
                A += a[i];
                i--;

                if (i >= 0) {
                    if (b[ii] >= a[i]) {
                        B += b[ii];
                        ii--;

                    } else {
                        i--;
                    }

                } else {
                    B += b[ii];
                    ii--;
                }

            } else {
                ii--;

                if (ii >= 0) {
                    if (b[ii] >= a[i]) {
                        B += b[ii];
                        ii--;

                    } else {
                        i--;
                    }

                } else {
                    i--;
                }
            }

        } else if (i >= 0) {
            A += a[i];
            i--;
            i--;

        } else if ( ii >= 0) {
            ii--;

            if (ii >= 0) {
                B += b[ii];
                ii--;
            }

        } else break;
    }

    //~ cout <<A << " "<< B<<"\n";
    cout << (A - B) << "\n";
    return 0;
}
