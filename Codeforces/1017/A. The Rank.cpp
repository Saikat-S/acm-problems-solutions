/***************************************************
 * Problem Name : A. The Rank.cpp
 * Problem Link : http://codeforces.com/contest/1017/problem/A
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-08-09
 * Problem Type : Div 1 + Div 2 - A
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
struct st {
    int id, val;
};
bool cmp (st a, st b) {
    if (a.val == b.val) return a.id < b.id;
    else return a.val > b.val;
}
int main () {
    __FastIO;
    int n;
    cin >> n;
    st ar[n + 3];

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = 1; j <= 4; j++) {
            int x;
            cin >> x;
            sum += x;
        }

        ar[i].id = i + 1;
        ar[i].val = sum;
    }

    sort (ar, ar + n, cmp);

    for (int i = 0; i < n; i++) {
        if (ar[i].id == 1) {
            cout << i + 1 << "\n";
            return 0;
        }
    }

    return 0;
}
