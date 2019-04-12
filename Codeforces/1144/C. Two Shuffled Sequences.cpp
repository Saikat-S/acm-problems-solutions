/***************************************************
 * Problem Name : C. Two Shuffled Sequences.cpp
 * Problem Link : https://codeforces.com/contest/1144/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-03-31
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
    //~ __FastIO;
    int n;
    cin >> n;
    int ar[MAX], chk[MAX];
    SET (chk, 0);
    bool flag = false;
    vector<int>v1, v2;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        chk[ar[i]]++;

        if (chk[ar[i]] == 1) {
            v1.pb (ar[i]);

        } else if (chk[ar[i]] == 2) {
            v2.pb (ar[i]);
        }

        if (chk[ar[i]] >= 3) {
            flag = true;
        }
    }

    if (flag) {
        cout << "NO\n";

    } else {
        sort (all (v1) );
        sort (all (v2) );
        reverse (all (v1) );
        cout << "YES\n";
        cout << (int) v2.size() << "\n";

        for (int i = 0; i < (int) v2.size(); i++) {
            cout << v2[i] << " ";
        }

        nl;
        cout << (int) v1.size() << "\n";

        for (int i = 0; i < (int) v1.size(); i++) {
            cout << v1[i] << " ";
        }

        nl;
    }

    return 0;
}
