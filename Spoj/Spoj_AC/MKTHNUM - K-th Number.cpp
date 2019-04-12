/***************************************************
 * Problem Name : MKTHNUM - K-th Number.cpp
 * Problem Link : https://www.spoj.com/problems/MKTHNUM/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2019-03-07
 * Problem Type : Segment Tree
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
int ar[MAX];
vector<vector<int> >tree (MAX * 4);
vector<int>qr;
vector<int> mergeTree (int left, int right) {
    vector<int>vec ( (int) tree[left].size() + (int) tree[right].size() );
    merge (all (tree[left]), all (tree[right]), vec.begin() );
    return vec;
}

void build (int nod, int low, int high) {
    if (low == high) {
        tree[nod].pb (ar[low]);
        return;
    }

    int mid = (high + low) / 2;
    build (nod * 2, low, mid);
    build (nod * 2 + 1, mid + 1, high);
    tree[nod] = mergeTree (nod * 2, nod * 2 + 1);
}

void query (int nod, int low, int high, int qlow, int qhigh) {
    if (qlow > high || qhigh < low) {
        return;
    }

    if (qlow <= low && qhigh >= high) {
        qr.pb (nod);
        return;
    }

    int mid = (high + low) / 2;
    query (nod * 2, low, mid, qlow, qhigh);
    query (nod * 2 + 1, mid + 1, high, qlow, qhigh);
}

int binary (int l, int r, int n, int kth) {
    int low = 0, high = n - 1;
    int pos = 0;

    while (high >= low) {
        int mid = (high + low) / 2;
        int sum = 0;

        for (int i = 0; i < (int) qr.size(); i++) {
            int nod = qr[i];
            int x = upper_bound (all (tree[nod]), tree[1][mid] - 1) - tree[nod].begin();
            sum += x;
        }

        if (sum >= kth) {
            high = mid - 1;

        } else {
            pos = mid;
            low = mid + 1;
        }
    }

    return pos;
}


int main () {
    __FastIO;
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    build (1, 0, n - 1);

    while (q--) {
        int l, r, kth;
        cin >> l >> r >> kth;
        qr.clear();
        query (1, 0, n - 1, l - 1, r - 1);
        int pos = binary (l - 1, r - 1, n, kth);
        cout << tree[1][pos] << "\n";
    }

    return 0;
}
