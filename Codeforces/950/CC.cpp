/***************************************************
 * Problem Name : CC.cpp
 * Problem Link : https://codeforces.com/contest/950/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-06-05
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
int main () {
    __FastIO;
    string str;
    cin >> str;
    int n = (int) str.size();
    int zebra = 0, almost_ze = 0;
    set<int>zero, one;

    for (int i = 0; i < n; i++) {
        if (str[i] == '0') {
            if (almost_ze == 0) {
                zebra++;

            } else {
                almost_ze--;
                zebra++;
            }

        } else {
            if (zebra == 0) {
                cout << -1 << "\n";
                exit (0);

            } else {
                zebra--;
                almost_ze++;
            }
        }
    }

    if (almost_ze != 0 ) {
        cout << -1 << "\n";
        exit (0);
    }

    vector<int>vec[MAX];
    int k = 0;

    for (int i = 0; i < n; i++) {
        if (str[i] == '0') {
            if (one.empty() ) {
                k++;
                vec[k].pb (i);
                zero.insert (k);

            } else {
                auto it = one.begin();
                int x = *it;
                vec[x].pb (i);
                one.erase (it);
                zero.insert (x);
            }

        } else {
            auto it = zero.begin();
            int x = *it;
            vec[x].pb (i);
            zero.erase (it);
            one.insert (x);
        }
    }

    cout << k << "\n";

    for (int i = 1; i <= k; i++) {
        cout << (int) vec[i].size() << " ";

        for (int j = 0; j < (int) vec[i].size(); j++) {
            cout << vec[i][j] + 1 << " ";
        }

        nl;
    }

    return 0;
}
