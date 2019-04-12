/***************************************************
 * Problem Name : Easy Prime!.cpp
 * Problem Link : https://toph.co/p/easy-prime
 * OJ           : Toph
 * Verdict      : AC
 * Date         : 2019-03-20
 * Problem Type : DS
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
#define __FileRead freopen ("/home/saikat/Desktop/logN/input.txt", "r", stdin);
#define __FileWrite freopen ("/home/saikat/Desktop/logN/output.txt", "w", stdout);
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
int n;
int ar[MAX], tree[MAX * 4];
char seive[10000005];
void primeSieve (int n) {
    int sq = sqrt (n);
    seive[0] = 1, seive[1] = 1;

    for (int i = 4; i <= n; i += 2) {
        seive[i] = 1;
    }

    for (int i = 3; i <= sq; i++) {
        if (seive[i] == 0) {
            for (int j = i + i; j <= n; j += i) {
                seive[j] = 1;
            }
        }
    }
}
void build (int nod, int low, int high) {
    if (low == high) {
        if (seive[ar[low]] == 0) {
            tree[nod] = 1;

        } else {
            tree[nod] = 0;
        }

        return;
    }

    int mid = (high + low) / 2;
    build (nod * 2, low, mid);
    build (nod * 2 + 1, mid + 1, high);
    tree[nod] = tree[nod * 2] + tree[nod * 2 + 1];
}

void update (int nod, int low, int high, int pos, int val) {
    if (pos > high || pos < low) {
        return;
    }

    if (low == high) {
        if (low == pos) {
            if (seive[val] == 0) {
                tree[nod] = 1;

            } else {
                tree[nod] = 0;
            }
        }

        return;
    }

    int mid = (high + low) / 2;
    update (nod * 2, low, mid, pos, val);
    update (nod * 2 + 1, mid + 1, high, pos, val);
    tree[nod] = tree[nod * 2] + tree[nod * 2 + 1];
}

int query (int nod, int low, int high, int qlow, int qhigh) {
    if (qlow > high || qhigh < low) {
        return 0;
    }

    if (qlow <= low && qhigh >= high) {
        return tree[nod];
    }

    int mid = (high + low) / 2;
    int a = query (nod * 2, low, mid, qlow, qhigh);
    int b = query (nod * 2 + 1, mid + 1, high, qlow, qhigh);
    return  a + b;
}

int main () {
    __FastIO;
    primeSieve (10000003);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    build (1, 0, n - 1);
    int q;
    cin >> q;

    while (q--) {
        int c, l, r;
        cin >> c >> l >> r;

        if (c == 1) {
            int ans = query (1, 0, n - 1, l - 1, r - 1);
            cout << ans << "\n";

        } else {
            update (1, 0, n - 1, l - 1, r);
        }
    }

    return 0;
}
