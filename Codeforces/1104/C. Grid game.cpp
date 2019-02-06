/***************************************************
 * Problem Name : C. Grid game.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-01-22
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
#define FileRead freopen ("/home/saikat/Desktop/logN/input.txt", "r", stdin);
#define FileWrite freopen ("/home/saikat/Desktop/logN/output.txt", "w", stdout);
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
vector<pii>vec;
void check (int id, int zero, int one) {
    if (id == 0) {
        if (zero % 2 == 1) {
            vec.pb (pii (1, 1) );

        } else {
            vec.pb (pii (3, 1) );
        }

    } else {
        if (one % 4 == 1) {
            vec.pb (pii (1, 2) );

        } else if (one % 4 == 2) {
            vec.pb (pii (2, 2) );

        } else if (one % 4 == 3) {
            vec.pb (pii (3, 2) );

        } else {
            vec.pb (pii (4, 2) );
        }
    }
}
int main () {
    __FastIO;
    string str;
    cin >> str;
    int n = (int) str.size();
    int zero = 0, one = 0;

    for (int i = 0; i < n; i++) {
        if (str[i] == '0') zero++;
        else one++;

        check (str[i] - '0', zero, one);
    }

    for (int i = 0; i < (int) vec.size(); i++) {
        cout << vec[i].first << " " << vec[i].second << "\n";
    }

    return 0;
}
