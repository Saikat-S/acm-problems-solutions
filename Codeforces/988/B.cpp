/***************************************************
 * Problem Name : B.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-08-17
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
bool cmp (string a, string b) {
    if (a.size() == b.size() ) return a > b;
    else return a.size() > b.size();
}
int main () {
    __FastIO;
    int n;
    string str;
    vector<string>V, ans;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        V.push_back (s);
    }

    sort (V.begin(), V.end(), cmp);
    int flag = 0;

    for (int i = 1; i < n; i++) {
        string pp = V[i - 1];
        string cc = V[i];
        std::size_t found = pp.find (cc);

        if (found != std::string::npos) {
        } else {
            flag  =  1;
            break;
        }
    }

    if (flag == 0) {
        cout << "YES\n";

        for (int i = n - 1; i >= 0; i--) {
            cout << V[i] << "\n";
        }

        cout << "\n";

    } else cout << "NO\n";

    return 0;
}
