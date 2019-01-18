/***************************************************
 * Problem Name : C. Doors Breaking and Repairing.cpp
 * Problem Link : https://codeforces.com/contest/1102/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-01-09
 * Problem Type : Div 3 - C
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
    int n,  x, y;
    int ar[MAX];
    cin >> n >> x >> y;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    int cnt = 0;

    if (x <= y) {
        int flag = 0;

        while (1) {
            if (flag == 0) {
                int f = 0;

                for (int i = 0; i < n; i++) {
                    int mx = max (0, ar[i] - x);

                    if (mx == 0 && ar[i] != 0) {
                        cnt++;
                        ar[i] = 0;
                        f = 1;
                        flag = 1;
                        break;
                    }
                }

                if (f == 0) {
                    break;
                }

            } else {
                for (int i = 0; i < n; i++) {
                    int mx = max (0, ar[i] - x);

                    if (mx == 0 && ar[i] != 0) {
                        ar[i] += y;
                        break;
                    }
                }

                flag = 0;
            }
        }

        cout << cnt << "\n";

    } else {
        cout << n << "\n";
    }

    return 0;
}
