/***************************************************
 * Problem Name : C. Palindromic Matrix.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2019-02-19
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
#define MAX 405
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
int arr[25][25];
int main () {
    //~ __FastIO;
    int n;
    int ar[MAX];
    cin >> n;
    map<int, int>mp;
    set<int>st;
    //~ queue<int>q;

    for (int i = 1; i <= n * n; i++) {
        cin >> ar[i];
        mp[ar[i]]++;
        st.insert (ar[i]);
    }

    //~ vector<int>vec;
    vector<int>V;

    for (auto it  = st.begin(); it != st.end(); it++) {
        //~ if (mp[*it] % 4 == 1) {
        //~ vec.pb (*it);
        //~ }
        V.pb (*it);
        //~ q.push (*it);
    }

    //~ sort (all (V) );

    //~ for (int i = (int) V.size() - 1; i >= 0; i--) {
    //~ q.push (V[i].second);
    //~ }

    if (n % 2 == 0) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] == 0) {
                    for (int k = 0; k < (int) V.size(); k++) {
                        int x = V[k];

                        if (mp[x] >= 4) {
                            arr[i][j] = x;
                            int jj = j - 1;
                            jj = n - jj;
                            arr[i][jj] = x;
                            int ii = i - 1;
                            ii = n - ii;
                            arr[ii][j] = x;
                            int iii = i - 1;
                            int jjj = j - 1;
                            iii = n - iii;
                            jjj = n - jjj;
                            arr[iii][jjj] = x;
                            mp[x] -= 4;
                            break;
                        }
                    }
                }
            }
        }

    } else {
        int pos = (n / 2) + 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] == 0) {
                    if (i == pos || j == pos) {
                    } else {
                        for (int k = 0; k < (int) V.size(); k++) {
                            int x = V[k];

                            if (mp[x] >= 4) {
                                arr[i][j] = x;
                                int jj = j - 1;
                                jj = n - jj;
                                arr[i][jj] = x;
                                int ii = i - 1;
                                ii = n - ii;
                                arr[ii][j] = x;
                                int iii = i - 1;
                                int jjj = j - 1;
                                iii = n - iii;
                                jjj = n - jjj;
                                arr[iii][jjj] = x;
                                mp[x] -= 4;
                                break;
                            }
                        }
                    }
                }
            }
        }

        for (int i = 1; i < pos; i++) {
			//~ debug;
            for (int k = 0; k < (int) V.size(); k++) {
                int xx = V[k];

                if (mp[xx] >= 2) {
					//~ debug;
                    arr[pos][i] = xx;
                    int X = i - 1;
                    X = n - X;
                    arr[pos][X] = xx;
                    mp[xx] -= 2;
                    break;
                }
            }
        }

        for (int i = 1; i < pos; i++) {
            for (int k = 0; k < (int) V.size(); k++) {
                int xx = V[k];

                if (mp[xx] >= 2) {
                    arr[i][pos] = xx;
                    int X = i - 1;
                    X = n - X;
                    arr[X][pos] = xx;
                    mp[xx] -= 2;
                    break;
                }
            }
        }

        for (int k = 0; k < (int) V.size(); k++) {
            int xx = V[k];

            if (mp[xx] >= 1) {
                arr[pos][pos] = xx;
                mp[xx] -= 1;
                break;
            }
        }
    }

    //~ debug;
    //~ cout << (int) q.size() << " -\n";
    bool flag = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == 0) {
                flag = true;
                break;
            }

            //~ cout << arr[i][j] << " ";
        }
        //~ nl;
    }

    if (flag == true) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << arr[i][j] << " ";
        }

        nl;
    }

    //~ }
    return 0;
}

