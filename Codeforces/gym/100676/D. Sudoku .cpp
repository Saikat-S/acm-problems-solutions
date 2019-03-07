/***************************************************
 * Problem Name : D. Sudoku .cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-02-21
 * Problem Type :
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
#define __FileRead freopen ("/home/saikat/Desktop/logN/input.txt", "r", stdin);
#define __FileWrite freopen ("/home/saikat/Desktop/logN/output.txt", "w", stdout);
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
#define MOD 1000000007
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
    __FastIO;
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc--) {
        char str[13][13];
        int n = 9;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> str[i][j];
            }
        }

        int x = 0, y = 0;
        bool flag = false;

        for (int c = 0; c < n; c++) {
            //~ debug;
            set<int>st;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if ( (i >= x && i < (x + 3) ) && (j >= y && j < (y + 3) ) ) {
                        //~ cout << str[i][j] << " ";
                        st.insert ( (str[i][j] - '0') );
                    }
                }
            }

            //~ nl;

            if ( (int) st.size() != 9) {
                flag = true;
                break;
            }

            //~ x = x + 3;
            y = y + 3;

            if (y >= 9) {
                y = 0;
                x = x + 3;
            }
        }

        if (flag == true) {
            cout << "Invalid\n";

        } else {
            flag = false;

            for (int i = 0; i < n; i++) {
                set<int>st;

                for (int j = 0; j < n; j++) {
                    st.insert (str[i][j] - '0');
                }

                if ( (int) st.size() != 9) {
                    flag = true;
                    break;
                }
            }

            if (flag == true) {
                cout << "Invalid\n";
                //~ break;

            } else {
                flag = false;

                for (int j = 0; j < n; j++) {
                    set<int>st;

                    for (int i = 0; i < n; i++) {
                        st.insert (str[i][j] - '0');
                    }

                    if ( (int) st.size() != 9) {
                        flag = true;
                        break;
                    }
                }

                if (flag == true) {
                    cout << "Invalid\n";

                } else {
                    cout << "Valid\n";
                }
            }
        }
    }

    return 0;
}
