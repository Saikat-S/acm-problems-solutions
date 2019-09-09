/***************************************************
 * Problem Name : 1039 - A Toy Company.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1039
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-08-30
 * Problem Type : Graph(bfs)
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;

#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define __FileRead freopen ("input.txt", "r", stdin)
#define __FileWrite freopen ("output.txt", "w", stdout)
#define SET(a,v) memset(a,v,sizeof(a))
#define SZ(v) (int)v.size()
#define pii pair<ll,ll>
#define pll pair <ll, ll>
#define debug cout <<"######\n"
#define debug1(x) cout <<"### " << x << " ###\n"
#define debug2(x,y) cout <<"# " << x <<" : "<< y <<" #\n"
#define nl cout << "\n";
#define sp cout << " ";
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define all(v) v.begin(), v.end()
#define srt(v) sort(v.begin(), v.end())
#define r_srt(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.begin(), v.end())
#define Sqr(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 100005
#define INF 1000000009
#define MOD 1000000007

template<class T>
using min_heap = priority_queue<T, std::vector<T>, std::greater<T>>;
template<typename T>
using ordered_set  = tree<T, null_type, less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

template <typename T> string toString ( T Number ) {
    stringstream ss;
    ss << Number;
    return ss.str();
}
template<typename T> int toInt (T str) {
    stringstream ss;
    ss << str;
    int num;
    ss >> num;
    return num;
}
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
int fx[] = {1, -1, 0, 0, 0, 0};
int fy[] = {0, 0, 1, -1, 0, 0};
int fz[] = {0, 0, 0, 0, 1, -1};

string sr, des;
int dis[31][31][31];
bool vis[31][31][31];


int bfs (string s, string d) {
    SET (dis, -1);
    queue<string>q;
    q.push (s);
    int x = s[0] - 'a';
    int y = s[1] - 'a';
    int z = s[2] - 'a';

    if (vis[x][y][z] == true) return -1;

    vis[x][y][z] = true;
    dis[x][y][z] = 0;

    while (!q.empty() ) {
        string u = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            char a = u[0] + fx[i];
            char b = u[1] + fy[i];
            char c = u[2] + fz[i];

            if (a == 'z' + 1) a = 'a';

            if (b == 'z' + 1) b = 'a';

            if (c == 'z' + 1) c = 'a';

            if (a == 'a' - 1) a = 'z';

            if (b == 'a' - 1) b = 'z';

            if (c == 'a' - 1) c = 'z';

            x = a - 'a';
            y = b - 'a';
            z = c - 'a';

            if (vis[x][y][z] == false) {
                int x1 = u[0] - 'a';
                int y1 = u[1] - 'a';
                int z1 = u[2] - 'a';
                dis[x][y][z] = dis[x1][y1][z1] + 1;
                vis[x][y][z]  = true;

                if (a == des[0] && b == des[1] && c == des[2]) {
                    return dis[x][y][z];
                }

                string v = "";
                v += a;
                v += b;
                v += c;
                q.push (v);
            }
        }
    }

    x = d[0] - 'a';
    y = d[1] - 'a';
    z = d[2] - 'a';
    return dis[x][y][z];
}


int main () {
    //~ __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> sr >> des;
        int n;
        cin >> n;
        SET (vis, false);

        for (int ii = 0; ii < n; ii++) {
            string a, b, c;
            cin >> a >> b >> c;

            for (int i = 0; i < (int) a.size(); i++) {
                for (int j = 0; j < (int) b.size(); j++) {
                    for (int k = 0; k < (int) c.size(); k++) {
                        int x = a[i] - 'a';
                        int y = b[j] - 'a';
                        int z = c[k] - 'a';
                        vis[x][y][z] = true;
                    }
                }
            }
        }

        int ans = bfs (sr, des);
        cout << "Case " << t << ": ";
        cout << ans << "\n";
    }

    return 0;
}
