/***************************************************
 * Problem Name : 1140 - How Many Zeroes?.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1140
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-01-28
 * Problem Type : digit dp
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
int n;
ll dp[20][20][3][3];
vector<int>vec;
ll digitDp (int pos, int cnt,  int isChoto, int isBoro) {
    if (pos == n) {
        return cnt;
    }

    if (dp[pos][cnt][isChoto][isBoro] != -1) {
        return dp[pos][cnt][isChoto][isBoro];
    }

    ll ans = 0;
    int high;

    if (isChoto == 0) {
        high = vec[pos];

    } else {
        high = 9;
    }

    for (int i = 0; i <= high; i++) {
        int new_cnt = cnt;
        int new_isChoto = isChoto;
        int new_isBoro = isBoro;

        if (i == 0 && isBoro == 1) new_cnt++;

        if (i < high) {
            new_isChoto = 1;
        }

        if (i > 0) {
            new_isBoro = 1;
        }

        ans += (ll) digitDp (pos + 1, new_cnt,  new_isChoto, new_isBoro);
    }

    return dp[pos][cnt][isChoto][isBoro] = ans;
}

ll solve (ll num) {
    vec.clear();

    while (num > 0) {
        int rem = num % 10;
        vec.pb (rem);
        num /= 10;
    }

    reverse (all (vec) );
    n = (int) vec.size();
    SET (dp, -1);
    ll ans = digitDp (0, 0, 0, 0);
    return ans;
}

int main () {
    //~ __FastIO;
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        ll a, b;
        cin >> a >> b;
        ll bb = solve (b);
        ll aa = solve (a - 1);

        if (a == 0) bb++;

        cout << "Case " << t << ": " << (bb - aa ) << "\n";
    }

    return 0;
}
