/***************************************************
 * Problem Name : 12086 Potentiometers.cpp
 * Problem Link : https://uva.onlinejudge.org/external/120/12086.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-10-10
 * Problem Type : Data Structure (BIT)
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
ll tree[MAX];
int getNext (int id) {
    return id + (id & -id);
}
int getPar (int id) {
    return id - (id & -id);
}
void update (int id, int n, ll val) {
    id++;

    while (id <= n) {
        tree[id] += val;
        id = getNext (id);
    }
}
ll query (int id) {
    id++;
    ll sum = 0;

    while (id > 0) {
        sum += tree[id];
        id = getPar (id);
    }

    return sum;
}
int main () {
    __FastIO;
    int n, t = 1;

    while (cin >> n) {
        if (n == 0) break;

        ll ar[MAX];

        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }

        SET (tree, 0);

        for (int i = 0; i < n; i++) {
            update (i, n, ar[i]);
        }

        string str;

        if (t != 1) nl;

        cout << "Case " << t++ << ":\n";

        while (cin >> str) {
            if (str == "END") break;

            if (str[0] == 'M') {
                int l, r;
                cin >> l >> r;
                l--, r--;
                cout << (query (r) - query (l) ) + ar[l] << "\n";

            } else {
                int id, val;
                cin >> id >> val;
                id--;
                update (id, n, val - ar[id]);
                ar[id] = val;
            }
        }
    }

    return 0;
}
