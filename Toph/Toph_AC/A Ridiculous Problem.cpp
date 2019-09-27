/***************************************************
 * Problem Name : A Ridiculous Problem.cpp
 * Problem Link : https://toph.co/p/a-ridiculous-problem
 * OJ           : Toph
 * Verdict      : AC
 * Date         : 2019-09-20
 * Problem Type : Easy
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
#define rev(v) reverse(v.begin(), v.end())
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
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
string str[10];
void check (char ch) {
    for (int i = 0; i < 10; i++) {
        str[i].clear();
    }

    if (ch == 'A') {
        str[0] = ".***.";
        str[1] = "*...*";
        str[2] = "*...*";
        str[3] = "*****";
        str[4] = "*...*";
        str[5] = "*...*";
        str[6] = "*...*";

    } else if (ch == 'B') {
        str[0] = "****.";
        str[1] = "*...*";
        str[2] = "*...*";
        str[3] = "****.";
        str[4] = "*...*";
        str[5] = "*...*";
        str[6] = "****.";

    } else if (ch == 'C') {
        str[0] = ".***.";
        str[1] = "*...*";
        str[2] = "*....";
        str[3] = "*....";
        str[4] = "*....";
        str[5] = "*...*";
        str[6] = ".***.";

    } else if (ch == 'D') {
        str[0] = "****.";
        str[1] = "*...*";
        str[2] = "*...*";
        str[3] = "*...*";
        str[4] = "*...*";
        str[5] = "*...*";
        str[6] = "****.";

    } else if (ch == 'E') {
        str[0] = "*****";
        str[1] = "*....";
        str[2] = "*....";
        str[3] = "****.";
        str[4] = "*....";
        str[5] = "*....";
        str[6] = "*****";

    } else if (ch == 'F') {
        str[0] = "*****";
        str[1] = "*....";
        str[2] = "*....";
        str[3] = "****.";
        str[4] = "*....";
        str[5] = "*....";
        str[6] = "*....";

    } else if (ch == 'G') {
        str[0] = ".***.";
        str[1] = "*...*";
        str[2] = "*....";
        str[3] = "*....";
        str[4] = "*..**";
        str[5] = "*...*";
        str[6] = ".***.";

    } else if (ch == 'H') {
        str[0] = "*...*";
        str[1] = "*...*";
        str[2] = "*...*";
        str[3] = "*****";
        str[4] = "*...*";
        str[5] = "*...*";
        str[6] = "*...*";

    } else if (ch == 'I') {
        str[0] = ".***.";
        str[1] = "..*..";
        str[2] = "..*..";
        str[3] = "..*..";
        str[4] = "..*..";
        str[5] = "..*..";
        str[6] = ".***.";

    } else if (ch == 'J') {
        str[0] = "..***";
        str[1] = "...*.";
        str[2] = "...*.";
        str[3] = "...*.";
        str[4] = "...*.";
        str[5] = "*..*.";
        str[6] = ".**..";

    } else if (ch == 'K') {
        str[0] = "*...*";
        str[1] = "*..*.";
        str[2] = "*.*..";
        str[3] = "**...";
        str[4] = "*.*..";
        str[5] = "*..*.";
        str[6] = "*...*";

    } else if (ch == 'L') {
        str[0] = "*....";
        str[1] = "*....";
        str[2] = "*....";
        str[3] = "*....";
        str[4] = "*....";
        str[5] = "*....";
        str[6] = "*****";

    } else if (ch == 'M') {
        str[0] = "*...*";
        str[1] = "**.**";
        str[2] = "*.*.*";
        str[3] = "*.*.*";
        str[4] = "*...*";
        str[5] = "*...*";
        str[6] = "*...*";

    } else if (ch == 'N') {
        str[0] = "*...*";
        str[1] = "*...*";
        str[2] = "**..*";
        str[3] = "*.*.*";
        str[4] = "*..**";
        str[5] = "*...*";
        str[6] = "*...*";

    } else if (ch == 'O') {
        str[0] = ".***.";
        str[1] = "*...*";
        str[2] = "*...*";
        str[3] = "*...*";
        str[4] = "*...*";
        str[5] = "*...*";
        str[6] = ".***.";

    } else if (ch == 'P') {
        str[0] = "****.";
        str[1] = "*...*";
        str[2] = "*...*";
        str[3] = "****.";
        str[4] = "*....";
        str[5] = "*....";
        str[6] = "*....";

    } else if (ch == 'Q') {
        str[0] = ".***.";
        str[1] = "*...*";
        str[2] = "*...*";
        str[3] = "*...*";
        str[4] = "*.*.*";
        str[5] = "*..*.";
        str[6] = ".**.*";

    } else if (ch == 'R') {
        str[0] = "****.";
        str[1] = "*...*";
        str[2] = "*...*";
        str[3] = "****.";
        str[4] = "*.*..";
        str[5] = "*..*.";
        str[6] = "*...*";

    } else if (ch == 'S') {
        str[0] = ".****";
        str[1] = "*....";
        str[2] = "*....";
        str[3] = ".***.";
        str[4] = "....*";
        str[5] = "....*";
        str[6] = "****.";

    } else if (ch == 'T') {
        str[0] = "*****";
        str[1] = "..*..";
        str[2] = "..*..";
        str[3] = "..*..";
        str[4] = "..*..";
        str[5] = "..*..";
        str[6] = "..*..";

    } else if (ch == 'U') {
        str[0] = "*...*";
        str[1] = "*...*";
        str[2] = "*...*";
        str[3] = "*...*";
        str[4] = "*...*";
        str[5] = "*...*";
        str[6] = ".***.";

    } else if (ch == 'V') {
        str[0] = "*...*";
        str[1] = "*...*";
        str[2] = "*...*";
        str[3] = "*...*";
        str[4] = ".*.*.";
        str[5] = ".*.*.";
        str[6] = "..*..";

    } else if (ch == 'W') {
        str[0] = "*...*";
        str[1] = "*...*";
        str[2] = "*...*";
        str[3] = "*.*.*";
        str[4] = "*.*.*";
        str[5] = "*.*.*";
        str[6] = ".*.*.";

    } else if (ch == 'X') {
        str[0] = "*...*";
        str[1] = "*...*";
        str[2] = ".*.*.";
        str[3] = "..*..";
        str[4] = ".*.*.";
        str[5] = "*...*";
        str[6] = "*...*";

    } else if (ch == 'Y') {
        str[0] = "*...*";
        str[1] = "*...*";
        str[2] = ".*.*.";
        str[3] = "..*..";
        str[4] = "..*..";
        str[5] = "..*..";
        str[6] = "..*..";

    } else if (ch == 'Z') {
        str[0] = "*****";
        str[1] = "....*";
        str[2] = "...*.";
        str[3] = "..*..";
        str[4] = ".*...";
        str[5] = "*....";
        str[6] = "*****";
    }
}
int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    string grid[10];

    for (int i = 0; i < 7; i++) {
        cin >> grid[i];
    }

    vector<char>vec;
    int n = grid[0].size();

    for (int j = 0; j < n;) {
        vector<char>tmp[10];

        for (int i = 0; i < 7; i++) {
            for (int k = 0, jj = j; k < 5 && j < n; k++, jj++) {
                tmp[i].pb (grid[i][jj]);
            }
        }

        j = j + 6;

        for (char ch = 'A'; ch <= 'Z'; ch++) {
            check (ch);
            bool f = false;

            for (int ii = 0; ii < 7; ii++) {
                for (int jj = 0; jj < 5; jj++) {
                    if (str[ii][jj] != tmp[ii][jj]) {
                        f = true;
                        break;
                    }
                }
            }

            if (!f) {
                vec.pb (ch);
                break;
            }
        }
    }

    for (int i = 0; i < (int) vec.size(); i++) {
        cout << vec[i];
    }

    nl;
    return 0;
}
