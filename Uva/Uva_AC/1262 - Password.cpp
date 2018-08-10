/***************************************************
 * Problem Name : 1262 - Password.cpp
 * Problem Link : https://uva.onlinejudge.org/external/12/1262.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-07-17
 * Problem Type : String
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
#define MAX 7
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
//~ }
int main () {
    __FastIO;
    int tc, k;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> k;
        string A[MAX], B[MAX];

        for (int i = 0; i < 6; i++) {
            cin >> A[i];
        }

        for (int i = 0; i < 6; i++) {
            cin >> B[i];
        }

        vector<char>V[MAX], VV[MAX];
        vector<string>AA, ans;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                char ch = A[j][i];
                V[i].pb (ch);
                ch = B[j][i];
                VV[i].pb (ch);
            }
        }

        for (int i = 0; i < 5; i++) {
            sort (all (V[i]) );
            sort (all (VV[i]) );
        }

        for (int i = 0; i < 5; i++) {
            string str = "";
            map<char, int>mp;

            for (int j = 0; j < 6; j++) {
                char ch = V[i][j];

                if (mp[ch] == 0) {
                    mp[ch] = 1;

                    for (int k = 0; k < 6; k++) {
                        if (ch == VV[i][k]) {
                            str += ch;
                            break;
                        }
                    }
                }
            }

            AA.pb (str);
        }

        for (int i = 0; i < (int) AA[0].size(); i++) {
            for (int j = 0; j < (int) AA[1].size(); j++) {
                for (int k = 0; k < (int) AA[2].size(); k++) {
                    for (int l = 0; l < (int) AA[3].size(); l++) {
                        for (int m = 0; m < (int) AA[4].size(); m++) {
                            string S = "";
                            S += AA[0][i];
                            S += AA[1][j];
                            S += AA[2][k];
                            S += AA[3][l];
                            S += AA[4][m];
                            ans.pb (S);
                        }
                    }
                }
            }
        }

        if (k <= (int) ans.size() ) {
            cout << ans[k - 1] << "\n";

        } else cout << "NO\n";
    }

    return 0;
}

