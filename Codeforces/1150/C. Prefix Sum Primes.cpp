/***************************************************
 * Problem Name : C. Prefix Sum Primes.cpp
 * Problem Link : https://codeforces.com/contest/1150/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-04-29
 * Problem Type : Div 2 - C
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
char ar[1000005];
void Seive (int n) {
    ar[0] = ar[1] = 1;

    for (int i = 4; i <= n; i += 2) ar[i] = 1;

    int sq = sqrt (n);

    for (int i = 3; i <= sq; i++) {
        if (ar[i] == 0) {
            for (int j = i * i; j <= n; j += 2 * i) ar[j] = 1;
        }
    }
}

int main () {
    __FastIO;
    Seive (1000000);
    int n;
    cin >> n;
    int one = 0, two = 0;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        if (x == 1) {
            one++;
        }

        if (x == 2) {
            two++;
        }
    }

    if (one == 0) {
        for (int i = 1; i <= n; i++) {
            cout << 2 << " ";
        }

        nl;
        exit (0);
    }

    if (two == 0) {
        for (int i = 1; i <= n; i++) {
            cout << 1 << " ";
        }

        nl;
        exit (0);
    }

    int one1 = one, two1 = two;
    int sum1[MAX], sum2[MAX];
    int cnt1 = 0, cnt2 = 0;
    sum1[0] = 0;
    sum2[0] = 0;

    if (one > 0) {
        one--;
    }

    static int ans1[MAX];
    static int ans2[MAX];
    sum1[1] = 1;
    ans1[1] = 1;

    for (int i = 2; i <= n; i++) {
        int x = 0, xx = 0;

        if (one > 0) {
            x = sum1[i - 1] + 1;
        }

        if (two > 0) {
            xx = sum1[i - 1] + 2;
        }

        if (ar[x] == 0) {
            ans1[i] = 1;
            sum1[i] = x;
            one--;
            cnt1++;

        } else if (ar[xx] == 0) {
            ans1[i] = 2;
            sum1[i] = xx;
            two--;
            cnt1++;

        } else {
            if (two > 0) {
                ans1[i] = 2;
                sum1[i] = xx;
                two--;

            } else if (one > 0) {
                ans1[i] = 1;
                sum1[i] = x;
                one--;
            }
        }
    }

    if (two1 > 0) {
        two1--;
        cnt2++;
    }

    sum2[1] = 2;
    ans2[1] = 2;

    for (int i = 2; i <= n; i++) {
        int x = 0, xx = 0;

        if (one1 > 0) {
            x = sum2[i - 1] + 1;
        }

        if (two1 > 0) {
            xx = sum2[i - 1] + 2;
        }

        if (ar[x] == 0) {
            ans2[i] = 1;
            sum2[i] = x;
            one1--;
            cnt2++;

        } else if (ar[xx] == 0) {
            ans2[i] = 2;
            sum2[i] = xx;
            two1--;
            cnt2++;

        } else {
            if (two1 > 0) {
                ans2[i] = 2;
                sum2[i] = xx;
                two1--;

            } else if (one1 > 0) {
                ans2[i] = 1;
                sum2[i] = x;
                one1--;
            }
        }
    }

    if (cnt1 >= cnt2) {
        for (int i = 1; i <= n; i++) {
            cout << ans1[i] << " ";
        }

        nl;

    } else {
        for (int i = 1; i <= n; i++) {
            cout << ans2[i] << " ";
        }

        nl;
    }

    return 0;
}
