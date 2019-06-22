/***************************************************
 * Problem Name : B - Guidebook.cpp
 * Problem Link : https://atcoder.jp/contests/abc128/tasks/abc128_b
 * OJ           : AtCoder
 * Verdict      : AC
 * Date         : 2019-05-27
 * Problem Type : B
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
int main () {
    __FastIO;
    map < string, int > mp;
    int n;
    cin >> n;
    int k = 1;
    vector<pii>vec[MAX];
    set<string>res;

    for (int i = 1; i <= n; i++) {
        string str;
        int p;
        cin >> str >> p;

        if (mp[str] == 0) {
            mp[str] = k++;
        }

        vec[mp[str]].pb (pii (p, i) );
        res.insert (str);
    }

    for (int i = 1; i < k; i++) {
        sort (all (vec[i]) );
        reverse (all (vec[i]) );
    }

    for (auto it = res.begin(); it != res.end(); it++) {
        string str = *it;

        for (int i = 0; i < (int) vec[mp[str]].size(); i++) {
            cout << vec[mp[str]][i].second << "\n";
        }
    }

    return 0;
}
