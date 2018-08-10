/***************************************************
 * Problem Name : 725 - Division.cpp
 * Problem Link : https://uva.onlinejudge.org/external/7/725.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-07-16
 * Problem Type : AdHoc
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
#define pb push_back
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
ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
int main () {
    __FastIO;
    ll n;
    int t = 1;

    while (cin >> n) {
        if (n == 0) break;

        vector<string>v;
        vector<string>ans;

        for (int i = 1234; i <= 98675; i++) {
            ll mul = n * i;
            ll chk ;

            if (mul >= 10000 && mul < 1000000) {
                bool flag = 1;
                chk = i;
                map<int, int>mp;

                if (i < 10000) {
                    mp[0]++;
                }

                string str;

                while (chk != 0) {
                    int r = chk % 10;
                    chk /= 10;

                    if (mp[r] == 0) {
                        mp[r]++;
                        str.pb (r + '0');

                    } else {
                        flag = 0;
                        break;
                    }
                }

                if (flag) {
                    string s = "";
                    chk = mul;

                    while (chk != 0) {
                        int r = chk % 10;
                        chk /= 10;

                        if (mp[r] == 0) {
                            mp[r]++;
                            s.pb (r + '0');

                        } else {
                            flag = 0;
                            break;
                        }
                    }

                    if (flag) {
                        reverse (all (str) );
                        reverse (all (s) );
                        v.pb (s);
                        ans.pb (str);
                    }
                }
            }
        }

        if (t != 1) {
            nl;
        }

        if ( (int) v.size() == 0) {
            cout << "There are no solutions for " << n << ".\n";

        } else {
            for (int i = 0; i < (int) v.size(); i++) {
                cout << v[i] << " / ";
                string str = "";
                str = ans[i];

                if ( (int) str.size() == 4) {
                    cout << 0;
                }

                cout << ans[i];
                cout << " = " <<  n << "\n";
            }
        }
        t++;
    }

    return 0;
}
