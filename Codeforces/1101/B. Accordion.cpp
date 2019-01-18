/***************************************************
 * Problem Name : B. Accordion.cpp
 * Problem Link : https://codeforces.com/contest/1101/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-01-11
 * Problem Type : Edu R - B
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
    string str;
    cin >> str;
    int n;
    n = (int) str.size();
    char pre = '0';
    int a = 0;
    int b = 0;
    int c = 0;
    int ans = 0;
    int cnt = 0, pos = 0;
    int flag = 0;

    for (int i = 0; i < n; i++) {
        if (str[i] == '[' && pre == '0') {
            pre = str[i];

        } else if (pre == '[') {
            if (str[i] == ':' && a == 0) {
                a = 1;

            } else if (a == 1) {
                if (str[i] == '|') {
                    b++;

                } else if (str[i] == ':') {
                    if (b > cnt) {
                        cnt = b;
                        pos = i;
                    }

                    c = 1;

                } else if (c == 1) {
                    if (str[i] == ']') {
                        int x = 4 + cnt;
                        ans = max (x, ans);
                        flag = 1;
                    }
                }
            }
        }
    }

    if (flag == 0) {
        cout << -1 << "\n";

    } else {
        cout << ans << "\n";
    }

    return 0;
}
