/***************************************************
 * Problem Name : Flipping Coins.cpp
 * Problem Link : https://www.codechef.com/problems/FLIPCOIN
 * OJ           : Codechef
 * Verdict      : AC
 * Date         : 2018-09-27
 * Problem Type : Data Structure (Segmet Tree with Lazy)
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
int ar[MAX], lazy[MAX * 3];
int head[MAX * 3], tail[MAX * 3];
void build (int nod, int low, int high) {
    if (low > high) return ;

    if (low == high) {
        tail[nod] = 1;
        head[nod] = 0;
        return ;
    }

    build (nod * 2, low, (high + low) / 2);
    build (nod * 2 + 1, ( (high + low) / 2) + 1, high);
    tail[nod] = tail[nod * 2] + tail[nod * 2 + 1];
    head[nod] = head[nod * 2] + head[nod * 2 + 1];
}
int query (int nod, int low, int high, int qlow, int qhigh) {
    if (low > high || qlow > high || qhigh < low) return 0;

    if (lazy[nod] != 0) {
        swap (head[nod], tail[nod]);

        if (low != high) {
            lazy[nod * 2] += lazy[nod];
            lazy[nod * 2] %= 2;
            lazy[nod * 2 + 1] += lazy[nod];
            lazy[nod * 2 + 1] %= 2;
        }

        lazy[nod] = 0;
    }

    if (low >= qlow && high <= qhigh) {
        return head[nod];
    }

    int q1 = query (nod * 2, low, (high + low) / 2, qlow, qhigh);
    int q2 = query (nod * 2 + 1, (high + low) / 2 + 1, high, qlow, qhigh);
    return q1 + q2;
}
void update (int nod, int low, int high, int qlow, int qhigh, int val) {
    if (low > high) return ;

    if (lazy[nod] != 0) {
        swap (head[nod], tail[nod]);

        if (low != high) {
            lazy[nod * 2] += lazy[nod];
            lazy[nod * 2] %= 2;
            lazy[nod * 2 + 1] += lazy[nod];
            lazy[nod * 2 + 1] %= 2;
        }

        lazy[nod] = 0;
    }

    if (low > high || qlow > high || qhigh < low) return;

    if (low >= qlow && high <= qhigh) {
        swap (head[nod], tail[nod]);

        if (low != high) {
            lazy[nod * 2] += val;
            lazy[nod * 2] %= 2;
            lazy[nod * 2 + 1] += val;
            lazy[nod * 2 + 1] %= 2;
        }

        return ;
    }

    update (nod * 2, low, (high + low) / 2, qlow, qhigh, val);
    update (nod * 2 + 1, (high + low) / 2 + 1, high, qlow, qhigh, val);
    head[nod] = head[nod * 2] + head[nod * 2 + 1];
    tail[nod] = tail[nod * 2] + tail[nod * 2 + 1];
}
int main () {
    __FastIO;
    int n, q;
    cin >> n >> q;
    build (1, 0, n - 1);

    while (q--) {
        int ch, x, y;
        cin >> ch >> x >> y;

        if (!ch) {
            update (1, 0, n - 1, x, y, 1);

        } else {
            cout << query (1, 0, n - 1, x, y) << "\n";
        }
    }

    return 0;
}
