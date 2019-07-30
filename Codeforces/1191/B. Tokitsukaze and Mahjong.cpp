/***************************************************
 * Problem Name : B. Tokitsukaze and Mahjong.cpp
 * Problem Link : https://codeforces.com/contest/1191/problem/B
 * OJ           : Codeforces
 * Verdict      : AC	
 * Date         : 2019-07-12
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
    string a, b, c;
    cin >> a >> b >> c;
    vector<string>s;
    s.pb (a);
    s.pb (b);
    s.pb (c);
    sort (all (s) );
    a = s[0], b = s[1], c = s[2];
    int cnt = 4;
    //1 == 1 == 1
    if (a[0] == b[0] && b[0] == c[0]) {
        if (a[1] == b[1] && b[1] == c[1]) {
            cnt = min (cnt, 0);
        }

        if (a[1] == b[1] || a[1] == c[1] || b[1] == c[1]) {
            cnt = min (cnt, 1);

        } else {
            cnt = min (cnt, 2);
        }
    }

    //1 == 2 == 3
    if (a[0] + 1 == b[0] && b[0] + 1 == c[0]) {
        if (a[1] == b[1] && b[1] == c[1]) {
            cnt = min (cnt, 0);
        }

        if (a[1] == b[1] || a[1] == c[1] || b[1] == c[1]) {
            cnt = min (cnt, 1);

        } else {
            cnt = min (cnt, 2);
        }
    }

    if (a[0] == b[0]) {
        if (a[1] == b[1]) {
            cnt = min (cnt, 1);

        } else {
            cnt = min (cnt, 2);
        }
    }

    if (b[0] == c[0]) {
        if (b[1] == c[1]) {
            cnt = min (cnt, 1);

        } else {
            cnt = min (cnt, 2);
        }
    }
    if (a[0] == c[0]) {
        if (a[1] == c[1]) {
            cnt = min (cnt, 1);

        } else {
            cnt = min (cnt, 2);
        }
    }

    if ( (a[0] + 1) == b[0]) {
        if (a[1] == b[1]) {
            cnt = min (cnt, 1);

        } else {
            cnt = min (cnt, 2);
        }
    }
    if ( (a[0] + 2) == b[0]) {
        if (a[1] == b[1]) {
            cnt = min (cnt, 1);

        } else {
            cnt = min (cnt, 2);
        }
    }
    if ((a[0] + 1) == c[0]) {
        if (a[1] == c[1]) {
            cnt = min (cnt, 1);

        } else {
            cnt = min (cnt, 2);
        }
    }
    if ((a[0] + 2) == c[0]) {
        if (a[1] == c[1]) {
            cnt = min (cnt, 1);

        } else {
            cnt = min (cnt, 2);
        }
    }

    if ( (b[0] + 1) == c[0]) {
        if (b[1] == c[1]) {
            cnt = min (cnt, 1);

        } else {
            cnt = min (cnt, 2);
        }

    }
    if ( (b[0] + 2) == c[0]) {
        if (b[1] == c[1]) {
            cnt = min (cnt, 1);

        } else {
            cnt = min (cnt, 2);
        }					

    }
     else {
        cnt = min (cnt, 2);
    }
    cout << cnt << "\n";
    return 0;
}
