/***************************************************
 * Problem Name : C. Painting the Fence.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2019-03-05
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
#define MAX 5005
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
struct st {
    int l, r, ln;
};
bool cmp (st a, st b) {
    return a.ln > b.ln;
}
bool cmp1 (pii a, pii b) {
    if(a.first == b.first){
		return a.second < b.second;
	}
	else{
		return a.first < b.first;
	}
}
int main () {
    //~ __FastIO;
    int n, q;
    cin >> n >> q;
    st ar[MAX];

    for (int i = 0; i < q; i++) {
        cin >> ar[i].l >> ar[i].r;
        ar[i].ln = abs (ar[i].r - ar[i].l) + 1;
    }

    sort (ar, ar + q, cmp);
    int mp[MAX];
    SET (mp, 0);
    vector<pii>con;

    for (int i = 0; i < q; i++) {
        int cnt = 0;

        for (int j = ar[i].l; j <= ar[i].r; j++) {
            if (mp[j] == 0) {
                cnt++;
                mp[j]++;
            }
        }

        con.pb (pii (cnt, i) );
    }

    sort (all (con), cmp1);
    int xx = con[0].second;
    int yy = con[1].second;
    SET (mp, 0);
    int sum = 0;

    for (int i = 0; i < q; i++) {
        if (i != xx && i != yy) {
            for (int j = ar[i].l; j <= ar[i].r; j++) {
                if (mp[j] == 0) {
                    sum++;
                    mp[j]++;
                }
            }
        }
    }

    cout << sum << "\n";
    return 0;
}
