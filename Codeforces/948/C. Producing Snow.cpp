/***************************************************
 * Problem Name : C. Producing Snow.cpp
 * Problem Link : https://codeforces.com/contest/948/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-07-18
 * Problem Type : Div 2 - C
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
#include <random>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define __FileRead freopen ("input.txt", "r", stdin);
#define __FileWrite freopen ("output.txt", "w", stdout);
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<ll,ll>
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

template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
/************************************ Code Start Here ******************************************************/
int main () {
    __FastIO;
    int n;
    cin >> n;
    int *ar = (int *) calloc (n, sizeof (int) );
    int *tr = (int *) calloc (n, sizeof (int) );
    ll *ans = (ll *) calloc (n, sizeof (ll) );

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> tr[i];
    }

    multiset<ll>st;
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        st.insert (ar[i] + sum);

        while (!st.empty() ) {
            ll val  = *st.begin();

            if (val <= sum + tr[i]) {
                ans[i] += (ll)(val - sum);
                st.erase (st.find (val) );

            } else {
                break;
            }
        }

        sum += (ll)tr[i];
        ans[i] += (ll) st.size() * (ll)tr[i];
    }

    for (int i = 0; i<n;i++) {
        cout << *(ans+i) << " ";
    }

    nl;
    return 0;
}
