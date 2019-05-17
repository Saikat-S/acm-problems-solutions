/***************************************************
 * Problem Name : C. Vasya and Multisets.cpp
 * Problem Link : https://codeforces.com/contest/1051/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-04-26
 * Problem Type : Edu - C
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
#define MAX 105
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
    int n;
    cin >> n;
    int ar[MAX];
    int chk[MAX];
    SET (chk, 0);
    set<int>st;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        chk[ar[i]]++;
        st.insert (ar[i]);
    }

    int cnt = 0, cnt1 = 0;

    for (auto it = st.begin(); it != st.end(); it++) {
        int x = *it;

        if (chk[x] == 1) {
            cnt++;

        } else if (chk[x] > 2) {
            cnt1++;
        }
    }

    if (cnt % 2 == 1 && cnt1 == 0) {
        cout << "NO\n";
        exit (0);
    }

    int c = 0;
    cout << "YES\n";

    if (cnt % 2 == 0) {
        for (int i = 0; i < n; i++) {
            if (chk[ar[i]] == 1 && c < (cnt / 2) ) {
                cout << "A";
                c++;

            } else {
                cout << "B";
            }
        }

    } else {
        cnt++;
        int f = 0;

        for (int i = 0; i < n; i++) {
            if (chk[ar[i]] == 1 && c < (cnt / 2) - 1) {
                cout << "A";
                c++;

            } else if (chk[ar[i]] > 2 && f == 0) {
                cout << "A";
                f = 1;

            } else {
                cout << "B";
            }
        }
    }

    nl;
    return 0;
}
