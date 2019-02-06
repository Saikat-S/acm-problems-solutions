/***************************************************
 * Problem Name : B.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-01-23
 * Problem Type :
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
int main () {
    //~ __FastIO;
    int n;
    cin >> n;
    int ar[n + 3];
    int cnt[MAX];
    SET (cnt, 0);
    int mx1 = 0;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        cnt[ar[i]]++;
        mx1 = max (mx1, ar[i]);
    }

    //~ sort (ar, ar + n);
    //~ int mx2 = 0;
    //~ for (int i = n - 1; i >= 0; i--) {
    //~ int tmp =
    //~ for (int j = n - 1; j >= 0; j--) {
    //~ }
    //~ }

    if (cnt[mx1] == 2) {
        cout << mx1 << " " << mx1 << "\n";
        return 0;
    }

    int mx2 = 0;
    int mx3 = 0;

    for (int i = 0; i < n; i++) {
        int x = ar[i];

        if (mx1 % x != 0) {
            mx3 = max (mx3, x);

        } else {
            if (cnt[x] == 2) {
                mx2 = max (mx2, x);
            }
        }
    }

    if (mx3 == 0) {
        cout << mx1 << " " << mx2 << "\n";

    } else {
        cout << mx1 << " " << mx3 << "\n";
    }

    return 0;
}
