/***************************************************
 * Problem name : 1109 - False Ordering .cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1109
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2017-11-02
 * Problem Type : Number Theory
 * Author Name  : Saikat Sharma
 * University   : CSE,MBSTU
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
#define SET(a) memset(a,-1,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pb push_back
#define MAX 1000
//~ #define MAX 10
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
struct Array {
    int x, d;
};
bool comp(Array a, Array b) {
    if (a.d > b.d) return 0;
    else if (a.d == b.d) return a.x > b.x;
    else {
        return 1;
    }
}
vector<Array>Ar;
vector<ll>prime;
char ar[MAX];
int arr[MAX];
void Seive(ll n) {
    ar[0] = ar[1] = 1;
    for (int i = 4; i <= n; i += 2) ar[i] = 1;
    prime.push_back(2);
    ll sq = sqrt(n);
    for (int i = 3; i <= sq; i++) {
        if (ar[i] == 0) {
            for (int j = i * i; j <= n; j += 2 * i) ar[j] = 1;
        }
    }
    for (int i = 3; i <= n; i++) {
        if (ar[i] == 0) prime.push_back(i);
    }
}
int NOD(int n) {
    int sq = sqrt(n), ans = 1;
    for (int i = 0; i < (int)prime.size() && prime[i] <= sq; i++) {
        if (n % prime[i] == 0) {
            int cnt = 0;
            while (n % prime[i] == 0) {
                cnt++;
                n /= prime[i];
            }
            cnt++;
            sq = sqrt(n);
            ans *= cnt;
        }
    }
    if ( n > 1) {
        ans *= 2;
    }
    return ans;
}
void preCal() {
    for (int i = 1; i <= MAX; i++) {
        Array get;
        get.x = i;
        get.d = NOD(i);
        Ar.push_back(get);
    }
    sort(Ar.begin(), Ar.end(), comp);
}
int main () {
    Seive(sqrt(MAX));
    preCal();
    //~ for(int i = 0; i<(int)Ar.size(); i++){
        //~ printf("%d ", Ar[i].x);
    //~ }
    int tc, n;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%d", &n);
        printf("Case %d: %d\n", t, Ar[n-1].x);
    }
    return 0;
}

