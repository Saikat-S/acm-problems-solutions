/***************************************************
 * Problem Name : 1212 - Double Ended Queue.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1212
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2018-09-29
 * Problem Type : Data Structure
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
int main () {
    //~ __FastIO;
    int tc, n, m;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n >> m;
        deque<int>dq;
        cout << "Case " << t << ":\n";

        while (m--) {
            string str;
            int val;
            cin >> str;

            if (str == "pushLeft") {
                cin >> val;

                if ( (int) dq.size() < n) {
                    cout << "Pushed in left: " << val << "\n";
                    dq.push_back (val);

                } else {
                    cout << "The queue is full\n";
                }

            } else if (str == "pushRight") {
                cin >> val;

                if ( (int) dq.size() >= n) {
                    cout << "The queue is full\n";

                } else {
                    cout << "Pushed in right: " << val << "\n";
                    dq.push_front (val);
                }

            } else if (str == "popLeft") {
                if (!dq.empty() ) {
                    cout << "Popped from left: " << dq.back() << "\n";
                    dq.pop_back();

                } else {
                    cout << "The queue is empty\n";
                }

            } else if (str == "popRight") {
                if (!dq.empty() ) {
                    cout << "Popped from right: " << dq.front() << "\n";
                    dq.pop_front();

                } else {
                    cout << "The queue is empty\n";
                }
            }
        }
    }

    return 0;
}
