/***************************************************
 * Problem Name : C. Zebras.cpp
 * Problem Link : https://codeforces.com/contest/950/problem/C
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2019-06-05
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
#define __FileRead freopen ("input.txt", "r", stdin);
#define __FileWrite freopen ("output.txt", "w", stdout);
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
#define MAX 200005
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
    string str;
    cin >> str;
    int n = (int) str.size();
    //~ cout << n << "\n";

    if (str[0] == '0' && str[n - 1] == '0') {
        //~ vector<int>zero, one;
        set<int>zero, one;

        for (int i = 0; i < n; i++) {
            if (str[i] == '0') {
                zero.insert (i);

            } else {
                one.insert (i);
            }
        }

        vector<int>vec[MAX];
        int k = 0;
        int pre_one = -1;

        if ( (int) one.size() == 66666) {
            while (1) {
                //~ int a, b, c;
                if (!zero.empty() ) {
                    if ( (int) zero.size() == 1) {
                        auto it = zero.begin();
                        vec[k++].pb (*it);
                        zero.erase (it);

                    } else {
                        auto it1 = zero.begin();
                        auto it3 = zero.end();
                        it3--;

                        if (!one.empty() ) {
                            auto it2 = one.begin();

                            if (*it1 > *it2) {
                                cout << -1 << "\n";
                                exit (0);

                            } else {
                                vec[k].pb (*it1);
                                vec[k].pb (*it2);
                                vec[k++].pb (*it3);
                                zero.erase (it1);
                                zero.erase (it3);
                                one.erase (it2);
                            }

                        } else {
                            vec[k++].pb (*it1);
                            zero.erase (it1);
                        }
                    }

                } else {
                    break;
                }
            }

        } else {
            while (1) {
                //~ int a, b, c;
                if (!zero.empty() ) {
                    while (1) {
                        int pre_zero = -1;

                        if (pre_one == -1) {
                            if (!zero.empty() ) {
                                auto it = zero.begin();
                                vec[k].pb (*it);
                                pre_zero = *it;
                                zero.erase (it);

                            } else {
                                break;
                            }

                        } else {
                            auto it = zero.lower_bound (pre_one + 1);

                            if (it != zero.end() ) {
                                pre_zero = *it;
                                zero.erase (it);
                            }

                            if (pre_zero == -1) {
                                cout << -1 << "\n";
                                exit (0);

                            } else {
                                vec[k].pb (pre_zero);
                            }
                        }

                        if (!one.empty() ) {
                            //~ int x = -1;
                            auto it = one.lower_bound (pre_zero + 1);

                            if (it != one.end() ) {
                                vec[k].pb (*it);
                                pre_one = *it;
                                one.erase (it);
                            }

                            if (zero.empty() ) {
                                cout << -1 << "\n";
                                exit (0);
                            }

                        } else {
                            break;
                        }
                    }

                    k++;
                    pre_one = -1;

                } else {
                    break;
                }
            }
        }

        cout << k << "\n";

        for (int i = 0; i < k; i++) {
            cout << (int) vec[i].size() << " ";

            for (int j = 0; j < (int) vec[i].size(); j++) {
                cout << vec[i][j] + 1 << " ";
            }

            nl;
        }

    } else {
        cout << -1 << "\n";
    }

    return 0;
}
