/***************************************************
 * Problem Name : Another Query on String.cpp
 * Problem Link : https://toph.co/p/another-query-on-string
 * OJ           : Toph
 * Verdict      : AC
 * Date         : 2019-04-15
 * Problem Type : DS(segment tree)
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
string ch;
int tree[MAX * 4][27];
void combine (int nod, int left, int right) {
    for (int i = 1; i <= 26; i++) {
        tree[nod][i] = tree[left][i] + tree[right][i];
    }
}

void build (int nod, int low, int high) {
    if (low == high) {
        tree[nod][ch[low] - 'a' + 1] = 1;
        return;
    }

    int mid = (high + low) / 2;
    build (nod * 2, low, mid);
    build (nod * 2 + 1, mid + 1, high);
    combine (nod, nod * 2, nod * 2 + 1);
}

int query (int nod, int qlow, int qhigh, int low, int high, int val) {
    if (qlow > high || qhigh < low) {
        return 0;
    }

    if (qlow <= low && qhigh >= high ) return tree[nod][val];

    int mid = (high + low) / 2;
    int a = query (nod * 2, qlow, qhigh, low, mid, val);
    int b = query (nod * 2 + 1, qlow, qhigh, mid + 1, high, val);
    return (a + b);
}
void update (int nod, int low, int high, int i, int val) {
    if (i > high  || i < low) return ;

    if (low >= i && high <= i) {
        tree[nod][ch[i] - 'a' + 1] = 0;
        tree[nod][val] = 1;
        return ;
    }

    int mid = (low + high) / 2;
    update (nod * 2, low, mid, i, val);
    update (nod * 2 + 1, mid + 1, high, i, val);
    combine (nod, nod * 2, nod * 2 + 1);
}


int main () {
    __FastIO;
    int n, q;
    cin >> n >> q;
    cin >> ch;
    SET (tree, 0);
    build (1, 0, n - 1);

    while (q--) {
        int c, x, y;
        char cc;
        cin >> c;

        if (c == 1) {
            cin >> x >> cc;
            update (1, 0, n - 1, x - 1, cc - 'a' + 1);
            ch[x - 1] = cc;

        } else {
            cin >> x >> y >> cc;
            int ans = query (1, x - 1, y - 1, 0, n - 1, cc - 'a' + 1);
            cout << ans << '\n';
        }
    }

    return 0;
}
//~ Input
//~ 3 4
//~ abc
//~ 2 1 3 c
//~ 1 1 c
//~ 2 1 3 c
//~ 2 2 2 b
//~ output
//~ 1
//~ 2
//~ 1
