/***************************************************
 * Problem Name : C. Little Girl and Maximum Sum.cpp
 * Problem Link : https://codeforces.com/contest/276/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-01-27
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
#define FileRead freopen ("/home/saikat/Desktop/logN/input.txt", "r", stdin);
#define FileWrite freopen ("/home/saikat/Desktop/logN/output.txt", "w", stdout);
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
    int n, q;
    cin >> n >> q;
    int ar[MAX];

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    sort (ar, ar + n);
    int sum[MAX];
    SET (sum, 0);

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        sum[l]++;

        if (r < n) sum[r]--;
    }

    ll total = 0;
    int br[MAX];

    for (int i = 0; i < n; i++) {
        total += sum[i];
        br[i] = total;
    }

    sort (br, br + n);
    total = 0;

    for (int i = 0; i < n; i++) {
        total += (ar[i] * 1LL * br[i]);
    }

    cout << total << "\n";
    return 0;
}
