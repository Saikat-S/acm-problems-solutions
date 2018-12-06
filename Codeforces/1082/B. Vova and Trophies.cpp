/***************************************************
 * Problem Name : B. Vova and Trophies.cpp
 * Problem Link : https://codeforces.com/contest/1082/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-12-04
 * Problem Type : Edu Round - B
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
    __FastIO;
    int n;
    string str;
    cin >> n;
    cin >> str;
    vector<pii>vec;
    int cnt = 0, pre = 0;
    int mx = 0;
    int G = 0;

    for (int i = 0; i < n; i++) {
        if (str[i] == 'G') G++;
    }

    for (int i = 0; i < n; i++) {
        if (str[i] == 'G') {
            cnt++;

        } else {
            int tmp;

            if (pre == 0) {
                tmp = cnt;

                if (tmp != G) tmp++;

            } else {
                tmp = cnt + pre;

                if (tmp != G) tmp++;
            }

            mx = max (mx, tmp);
            pre = cnt;
            cnt = 0;

            if (i != n - 1 && str[i + 1] == 'S') pre = 0;
        }
    }

    int tmp;

    if (pre == 0) {
        if (G != cnt) tmp = ++cnt;
        else tmp = cnt;

    } else {
        tmp = cnt + pre;

        if (tmp != G) tmp++;
    }

    mx = max (mx, tmp);
    cout << mx << "\n";
    return 0;
}
