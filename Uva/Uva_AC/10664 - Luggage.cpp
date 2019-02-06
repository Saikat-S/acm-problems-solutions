/***************************************************
 * Problem Name : 10664 - Luggage.cpp
 * Problem Link : https://uva.onlinejudge.org/external/106/10664.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2019-02-06
 * Problem Type : dp
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
#define MAX 205
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
vector<int>coin, cap;
int C[MAX];
int n, need;
int dp[23][205][205];

int stringToNum (string str) {
    int num  = 0;
    int sz = str.size();

    for (int i = 0; i < sz; i++) {
        num = (num * 10) + (str[i] - '0');
    }

    return num;
}

int coin_change (int i, int make, int taken) {
    if (i >= n) {
        if (make == need) return 1;
        else return 0;
    }

    if (dp[i][taken][make] != -1) return dp[i][taken][make];

    int ret1 = 0, ret2 = 0;

    if ( (make + coin[i] <= need) && taken <= cap[i]) {
        ret1 = coin_change (i, make + coin[i], taken + 1);
    }

    ret2 = coin_change (i + 1, make, 1);
    return dp[i][taken][make] = (ret1 | ret2);
}
int main () {
    __FastIO;
    int tc;
    cin >> tc;
    string str;
    cin.ignore();

    while (tc--) {
        vector<int>ar;
        string tmp;
        getline (cin, str);
        stringstream ss;
        ss << str;

        while (ss >> tmp) {
            ar.pb (stringToNum (tmp) );
        }

        set<int>st;
        SET (C, 0);
        int sum = 0;

        for (int i = 0; i < (int) ar.size(); i++) {
            int x = ar[i];
            C[x]++;
            st.insert (x);
            sum += x;
        }

        for (auto it = st.begin(); it != st.end(); it++) {
            int x = *it;
            coin.pb (x);
            x = C[x];
            cap.pb (x);
        }

        if (sum % 2 == 1) {
            cout << "NO\n";

        } else {
            n = (int) coin.size();
            need = sum / 2;
            SET (dp, -1);
            int flag = coin_change (0, 0, 1);

            if (flag == 1) {
                cout << "YES\n";

            } else {
                cout << "NO\n";
            }
        }

        coin.clear(), cap.clear();
    }

    return 0;
}
