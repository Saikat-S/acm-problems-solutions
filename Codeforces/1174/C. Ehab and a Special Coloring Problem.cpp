/***************************************************
 * Problem Name : C. Ehab and a Special Coloring Problem.cpp
 * Problem Link : https://codeforces.com/contest/1174/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-06-04
 * Problem Type : Div 2 - C
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
char ar[MAX];
vector<int>prime;
void seive() {
    ar[1] = 1;

    for (int i = 4; i < MAX; i += 2) {
        ar[i] = 1;
    }

    int sq = sqrt (MAX);

    for (int i = 3; i <= sq; i++) {
        if (ar[i] == 0) {
            for (int j = i + i; j < MAX; j += i) {
                ar[j] = 1;
            }
        }
    }
}
int main () {
    __FastIO;
    seive();
    int n;
    cin >> n;
    map<int, int>mp;
    vector<int>vec;
    vec.pb (1);
    mp[1] = 2;
    int k = 1;

    for (int i = 3; i <= n; i++) {
        if (ar[i] == 0) {
            vec.pb (++k);
            prime.pb (i);
            mp[i] = k;

        } else {
            if (i & 1) {
                for (int j = 0; j < (int) prime.size(); j++) {
                    if (i % prime[j] == 0) {
                        vec.pb (mp[prime[j]]);
                        break;
                    }
                }

            } else {
                vec.pb (1);
            }
        }
    }

    for (int i = 0; i < (int) vec.size(); i++) {
        cout << vec[i] << " ";
    }

    nl;
    return 0;
}
