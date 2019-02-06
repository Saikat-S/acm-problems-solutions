/***************************************************
 * Problem Name : 10534 - Wavio Sequence.cpp
 * Problem Link : https://uva.onlinejudge.org/external/105/10534.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2019-02-06
 * Problem Type : dp(LIS)
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
#define MAX 10005
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
int L[MAX], I[MAX];
int L1[MAX], I1[MAX];
vector<int>ar, ar1;
void LIS_NlogK (int n) {
    I[0] = -100000000;

    for (int i = 1; i <= n; i++) {
        I[i] = 100000000;
    }

    int Maxlen = 0;

    for (int i = 0; i < n; i++) {
        int low = 0, high = Maxlen, mid;

        while (high >= low) {
            mid = (low + high) / 2;

            if (I[mid] < ar[i]) {
                low = mid + 1;

            } else {
                high = mid - 1;
            }
        }

        I[low] = ar[i];
        L[i] = low;

        if (Maxlen < low) {
            Maxlen = low;
        }
    }
}

void LDS_NlogK (int n) {
    I1[0] = -100000000;

    for (int i = 1; i <= n; i++) {
        I1[i] = 100000000;
    }

    int Maxlen = 0;

    for (int i = 0; i < n; i++) {
        int low = 0, high = Maxlen, mid;

        while (high >= low) {
            mid = (low + high) / 2;

            if (I1[mid] < ar1[i]) {
                low = mid + 1;

            } else {
                high = mid - 1;
            }
        }

        I1[low] = ar1[i];
        L1[i] = low;

        if (Maxlen < low) {
            Maxlen = low;
        }
    }
}
int main () {
    __FastIO;
    int n;

    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ar.pb (x);
            ar1.pb (x);
        }

        LIS_NlogK (n);
        reverse (all (ar1) );
        LDS_NlogK (n);
        int LL[MAX];

        for (int i = 0, j = n - 1; i < n; i++, j--) {
            LL[j] = L1[i];
        }

        int mx = 0;

        for (int i = 0; i < n; i++) {
            int mn = min (L[i], LL[i]);
            mx = max (mx, mn);
        }

        cout << (mx * 2) - 1 << "\n";
        ar.clear();
        ar1.clear();
    }

    return 0;
}
