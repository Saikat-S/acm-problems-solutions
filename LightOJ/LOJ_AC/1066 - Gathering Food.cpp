/***************************************************
 * Problem Name : 1066 - Gathering Food.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1066
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-08-28
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
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

char ch[13][13];
bool vis[13][13];
int dis[13][13];
int n;

bool isValid (int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < n && ch[x][y] != '#'
        && vis[x][y] == false) {
        return true;

    } else {
        return false;
    }
}

void bfs (int sx, int sy, char cc) {
    vis[sx][sy] = true;
    dis[sx][sy] = 0;
    queue<pii>q;
    q.push ({sx, sy});

    while (!q.empty() ) {
        pii top = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int tx = top.first + fx[i];
            int ty = top.second + fy[i];

            if (isValid (tx, ty) ) {
                char c = ch[tx][ty];
                dis[tx][ty] = dis[top.first][top.second] + 1;
                vis[tx][ty] = true;

                if (isalpha (c) ) {
                    if (c == cc) {
                        return;
                    }else if(cc>c){
						q.push({tx,ty});
					}

                } else {
                    q.push ({tx, ty});
                }
            }
        }
    }
}

int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n;
        int cnt = 0;
        map<char, pii>mp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> ch[i][j];

                if (isalpha (ch[i][j]) ) {
                    cnt++;
                    mp[ch[i][j]] = {i, j};
                }
            }
        }

		int ans = 0;
		bool flag = false; 

        char c = 'A';
 
        for (int i = 1; i < cnt; i++) {
            pii sr = mp[c];
            pii des = mp[c + 1];
            
            SET(vis, false);
            SET(dis, -1);
            
            bfs(sr.first, sr.second, c+1);
            
            if(dis[des.first][des.second] == -1){
				flag = true;
				break;
			}
			ans+=dis[des.first][des.second];
			c++;
        }
        cout << "Case " << t<<": ";
        if(!flag) cout << ans;
        else cout << "Impossible";
        nl;
    }

    return 0;
}
