/***************************************************
 * Problem Name : 1083 - Histogram.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1083
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2018-09-22
 * Problem Type : Data Structure
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
#define MAX 30005
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
int ar[MAX], tree[MAX * 3], mx, n;
void build (int nod, int low, int high) {
    if (low == high) {
        tree[nod] = low;
        return ;

    } else {
        int mid = (high + low) / 2;
        int left = nod * 2;
        int right = nod * 2 + 1;
        build (left, low, mid);
        build (right, mid + 1, high);
		
        if (ar[tree[left]] <= ar[tree[right]])
            tree[nod] = tree[left];
        else tree[nod] = tree[right];
    }
}
int query (int nod, int low, int high, int l, int r) {
    if (l > high || r < low) {
        return 0;
    }

    if (l <= low && r >= high) {
        return tree[nod];
    }

    int mid = (high + low) / 2;
    int left = nod * 2;
    int right = nod * 2 + 1;
    int a = query (left, low, mid, l, r);
    int b = query (right, mid + 1, high, l, r);

    if ( ar[a] <= ar[b]) return a;
    else return b;
}
void solve (int l, int r) {
    if (l > r) return ;

    int idx = query (1, 1, n, l, r);
    int xx = ar[idx] * (r - l + 1);
    mx = max (mx, xx);
    solve (l, idx - 1);
    solve (idx + 1, r);
}

int main () {
    __FastIO;
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> ar[i];
        }

        ar[0] = 100005;
        build (1, 1, n);
        mx = 0;
        solve (1, n);
        cout << "Case " << t << ": " << mx << "\n";
    }

    return 0;
}
