/***************************************************
 * Problem Name : A.cpp
 * Problem Link : https://codeforces.com/contest/1174/problem/A
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-06-04
 * Problem Type : Div 2 - A
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
    //~ __FastIO;
    int n;
    cin >> n;
    vector<int>vec;

    for (int i = 0; i < 2 * n; i++) {
        int x;
        cin >> x;
        vec.pb (x);
    }

    sort (all (vec) );
    ll s1 = 0;

    for (int i = 0; i < n; i++) {
        s1 += (ll) vec[i];
    }

    ll s2 = 0;

    for (int i = n; i < 2 * n; i++) {
        s2 += (ll) vec[i];
    }

    if (s1 == s2) {
        cout << -1 << "\n";

    } else {
        for (int i = 0; i < 2 * n; i++) {
            cout << vec[i] << " ";
        }

        nl;
    }

    return 0;
}
