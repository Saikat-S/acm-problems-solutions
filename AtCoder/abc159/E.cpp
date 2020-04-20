/***************************************************
 * Problem Name : E.cpp
 * Problem Link : https://atcoder.jp/contests/abc159/tasks/abc159_e
 * OJ           : atCoder
 * Verdict      : Trying
 * Date         : 2020-04-19
 * Problem Type :
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
#define pii pair<int,int>
#define pil pair <int, ll>
#define pli pair <ll, int>
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
#define rall(v) v.begin(), v.end()
#define srt(v) sort(v.begin(), v.end())
#define r_srt(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.rbegin(), v.rend())
#define Sqr(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
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
ll lcm ( ll a, ll b ) {
    return ( a / __gcd ( a, b ) ) * b;
}
/************************************ Code Start Here ******************************************************/
int main () {
    //~ __FastIO;
    //~ cout << setprecision (10) << fixed;
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>>vec (h, vector<char> (w) );

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> vec[i][j];
        }
    }
    
    
    //~ debug;
    
    int res = INF;

    for (int mask = 1; mask < (1 << h); mask++) {
        int n = __builtin_popcount (mask);
        vector<vector<int>>cum (n+1);
        int y = mask;
        int i = 0;
        vector<int>row;

        while (y > 0) {
            int rem = y % 2;
            y /= 2;

            if (rem == 1) {
                row.pb (i);
            }

            i++;
        }
        //~ debug;
        int N = 0;

        for (int j = 0; j < w; j++) {
            int sum = 0;

            for (int i = 0; i <= row[0]; i++) {
                if (vec[i][j] == '1') sum++;
            }

            cum[N].pb (sum);
        }
        //~ debug;
        
        N++;
        
        
        //~ cout << (int)row.size() << "  :row\n";
        
        for (int l = 0; l < (int) row.size(); l++) {
            if (l == (int) row.size() - 1) {
                if (row[l] == h - 1) break;
				//~ debug;

                for (int j = 0; j < w; j++) {
                    int sum = 0;

                    for (int i = row[l] + 1; i < h; i++) {
                        if (vec[i][j] == '1') sum++;
                    }
                    //~ debug;

                    cum[N].pb (sum);
                }

                N++;

            } else {
                for (int j = 0; j < w; j++) {
                    int sum = 0;

                    for (int i = row[l] + 1; i <= row[l + 1]; i++) {
                        if (vec[i][j] == '1') sum++;
                    }

                    cum[N].pb (sum);
                }

                N++;
            }
        }
        //~ debug;
        //~ cout << mask << " " << N << "  mask\n";
        bool flag = false;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < w; j++) {
                if (cum[i][j] > k) {
                    flag = true;
                    break;
                }
            }

            if (flag) break;
        }
        //~ debug;

        if (flag) continue;

        int cnt = __builtin_popcount (mask);
        vector<int>pre (N, 0);
        //~ debug;
        for (int j = 0; j < w; j++) {
            for (int i = 0; i < N; i++) {
                if (i == 0) {
                    pre[i] = cum[i][j];
                }else{
					pre[i] = pre[i] + cum[i][j];
				}
            }
            for(int i = 0; i<N; i++){
				if(pre[i]>k){
					cnt++;
					pre.resize(N, 0);
					break;
				}
			}
        }
        cout << n << " mask: " << cnt << "\n";
        res = min(res, cnt);
    }
    cout << res << "\n";

    return 0;
}
