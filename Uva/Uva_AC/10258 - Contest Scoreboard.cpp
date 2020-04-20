/***************************************************
 * Problem Name : 10258 - Contest Scoreboard.cpp
 * Problem Link : https://onlinejudge.org/external/102/10258.pdf
 * OJ           : Uva
 * Verdict      : AC 
 * Date         : 2020-03-28
 * Problem Type : STL
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
vector<string> purse (string str) {
    stringstream ss;
    ss << str;
    vector<string>vec;
    string num;

    while (ss >> num) {
        vec.pb (num);
    }

    return vec;
}

bool cmp (pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
    if (a.first == b.first) {
        if (a.second.first == b.second.first) {
            return a.second.second < b.second.second;

        } else {
            return a.second.first < b.second.first;
        }

    } else {
        return a.first > b.first;
    }
}

int main () {
    __FastIO;
    //~ cout << setprecision (10) << fixed;
    int tc;
    cin >> tc;
    cin.ignore();
    cin.ignore();
    int t = 1;

    while (t <= tc) {
        int user, prob_id, sb_time;
        string ver;
        vector<pair<int, pair<int, int> > >vec (105);
        map<int, map<int, int> >mp, ac;
        map<int, bool>p_user;
        string str;

        while (getline (cin, str) ) {
            if (str.size() == 0) break;

            vector<string>vv = purse (str);
            user = toInt (vv[0]), prob_id = toInt (vv[1]), sb_time = toInt (vv[2]),
            ver = vv[3];

            if (ver[0] == 'C') {
                if (ac[user][prob_id] == 1) continue;

                int now_time = sb_time + mp[user][prob_id] * 20;
                int cnt = vec[user].first + 1;
                int total_time = vec[user].second.first + now_time;
                vec[user] = {cnt, {total_time, user}};
                ac[user][prob_id] = 1;

            } else if (ver[0] == 'I') {
                mp[user][prob_id]++;
            }

            int cnt = vec[user].first;
            int total_time = vec[user].second.first;
            vec[user] = {cnt, {total_time, user}};
            p_user[user] = true;
        }

        sort (all (vec), cmp);

        if (t != 1) nl;

        t++;

        for (auto it : vec) {
            if (p_user[it.second.second] == false) continue;

            cout << it.second.second << " " << it.first << " " << it.second.first << "\n";
        }
    }

    return 0;
}
