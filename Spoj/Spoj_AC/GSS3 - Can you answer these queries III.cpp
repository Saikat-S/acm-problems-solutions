/***************************************************
 * Problem Name : GSS3 - Can you answer these queries III.cpp
 * Problem Link : https://www.spoj.com/problems/GSS3/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2019-11-29
 * Problem Type : Data Strcuture (Segment Tree)
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
 ***************************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
#include <deque>
#include <stack>
#include <bitset>
#include <cassert>
#include <map>
#include <set>
#include <cassert>
#include <iomanip>

using namespace std;
typedef long long ll;

#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define SET(a,v) memset(a,v,sizeof(a))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 50005
#define INF 1000000009
#define MOD 1000000007
/************************************ Code Start Here ******************************************************/
struct Tree {
    ll left_sum, right_sum, total_sum, max_sum;
    Tree() {
        left_sum = -INF;
        right_sum = -INF;
        total_sum = -INF;
        max_sum = -INF;
    }
} tr[MAX * 4];

int ar[MAX];


Tree combine (Tree a, Tree b) {
    Tree tmp;
    tmp.left_sum = max (a.left_sum, a.total_sum + b.left_sum);
    tmp.right_sum = max (b.right_sum, b.total_sum + a.right_sum);
    tmp.total_sum = a.total_sum + b.total_sum;
    tmp.max_sum = max3 (a.max_sum, b.max_sum, a.right_sum + b.left_sum);
    return tmp;
}

void build (int nod, int low, int high) {
    if (low > high) return;

    if (low == high) {
        tr[nod].left_sum = ar[low];
        tr[nod].right_sum = ar[low];
        tr[nod].total_sum = ar[low];
        tr[nod].max_sum = ar[low];
        return;
    }

    int mid = (high + low) / 2;
    build (nod * 2, low, mid);
    build (nod * 2 + 1, mid + 1, high);
    tr[nod] = combine (tr[nod * 2], tr[nod * 2 + 1]);
}

void update (int nod, int low, int high, int pos, int val) {
    if (pos > high || pos < low) {
        return;
    }

    if (low >= pos && high <= pos) {
        tr[nod].left_sum = val;
        tr[nod].right_sum = val;
        tr[nod].total_sum = val;
        tr[nod].max_sum = val;
        return;
    }

    int mid = (high + low) / 2;
    update (nod * 2, low, mid, pos, val);
    update (nod * 2 + 1, mid + 1, high, pos, val);
    tr[nod] = combine (tr[nod * 2], tr[nod * 2 + 1]);
}

Tree query (int nod, int low, int high, int qlow, int qhigh) {
    if (qlow > high || qhigh < low) {
        Tree tmp;
        return tmp;
    }

    if (low >= qlow && high <= qhigh) {
        return tr[nod];
    }

    int mid = (high + low) / 2;
    Tree a = query (nod * 2, low, mid, qlow, qhigh);
    Tree b = query (nod * 2 + 1, mid + 1, high, qlow, qhigh);
    return combine (a, b);
}

int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    build (1, 0, n - 1);
    int q;
    cin >> q;

    while (q--) {
        int l, r;
        int c;
        cin >> c;
        cin >> l >> r;

        if (c == 0) {
            update (1, 0, n - 1, l - 1, r);

        } else {
            Tree ans = query (1, 0, n - 1, l - 1, r - 1);
            cout << ans.max_sum << "\n";
        }
    }

    return 0;
}
