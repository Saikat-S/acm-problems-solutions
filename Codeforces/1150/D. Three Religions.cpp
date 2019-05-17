/***************************************************
 * Problem Name : D. Three Religions.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2019-04-29
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
map<char, int>mp;
string str, a, b, c;
int n;
bool vis[MAX];
bool isHappy1() {
    SET (vis, false);
    bool fa = false;
    bool fb = false;
    bool fc = false;
    for (int i = 0; i < n; i++) {
        int ii = i;
        int j = 0;

        //~ bool f = false;
        for (; j < (int) a.size();) {
            if (str[ii] == a[j]) {
                //~ f = true;
                ii++;
                j++;

                if (ii >= n ) break;

            } else {
                break;
            }
        }
        if(j == (int)a.size()){
			for(int iii = i; iii <ii; iii++){
				vis[iii] = true;
			}
			fa = true;
			//~ cout << " ----- hahah1---- \n";
			break;
		}
    }
    for (int i = 0; i < n; i++) {
        int ii = i;
        int j = 0;

        //~ bool f = false;
        for (; j < (int) b.size();) {
            if (str[ii] == b[j] && vis[ii] == false) {
                //~ f = true;
                ii++;
                j++;

                if (ii >= n ) break;

            } else {
                break;
            }
        }
        if(j == (int)b.size()){
			for(int iii = i; iii <ii; iii++){
				vis[iii] = true;
			}
			//~ cout << " ----- hahah2---- \n";
			fb = true;
			break;
		}
    }
    for (int i = 0; i < n; i++) {
        int ii = i;
        int j = 0;

        //~ bool f = false;
        for (; j < (int) c.size();) {
            if (str[ii] == c[j] && vis[ii] == false) {
                //~ f = true;
                ii++;
                j++;

                if (ii >= n ) break;

            } else {
                break;
            }
        }
        if(j == (int)c.size()){
			//~ cout << " ----- hahah3---- \n";
			fc = true;
			break;
		}
    }

    if(fa == true && fb == true && fc == true){
		return true;
	}else{
		return false;
	}
}
bool isHappy2() {
    SET (vis, false);
    bool fa = false;
    bool fb = false;
    bool fc = false;
    for (int i = 0; i < n; i++) {
        int ii = i;
        int j = 0;

        //~ bool f = false;
        for (; j < (int) b.size();) {
            if (str[ii] == b[j]) {
                //~ f = true;
                ii++;
                j++;

                if (ii >= n ) break;

            } else {
                break;
            }
        }
        if(j == (int)b.size()){
			for(int iii = i; iii <ii; iii++){
				vis[iii] = true;
			}
			fb = true;
			//~ cout << " ----- hahah1---- \n";
			break;
		}
    }
    for (int i = 0; i < n; i++) {
        int ii = i;
        int j = 0;

        //~ bool f = false;
        for (; j < (int) a.size();) {
            if (str[ii] == a[j] && vis[ii] == false) {
                //~ f = true;
                ii++;
                j++;

                if (ii >= n ) break;

            } else {
                break;
            }
        }
        if(j == (int)a.size()){
			for(int iii = i; iii <ii; iii++){
				vis[iii] = true;
			}
			//~ cout << " ----- hahah2---- \n";
			fa = true;
			break;
		}
    }
    for (int i = 0; i < n; i++) {
        int ii = i;
        int j = 0;

        //~ bool f = false;
        for (; j < (int) c.size();) {
            if (str[ii] == c[j] && vis[ii] == false) {
                //~ f = true;
                ii++;
                j++;

                if (ii >= n ) break;

            } else {
                break;
            }
        }
        if(j == (int)c.size()){
			//~ cout << " ----- hahah3---- \n";
			fc = true;
			break;
		}
    }

    if(fa == true && fb == true && fc == true){
		return true;
	}else{
		return false;
	}
}
bool isHappy3() {
    SET (vis, false);
    bool fa = false;
    bool fb = false;
    bool fc = false;
    for (int i = 0; i < n; i++) {
        int ii = i;
        int j = 0;

        //~ bool f = false;
        for (; j < (int) c.size();) {
            if (str[ii] == c[j]) {
                //~ f = true;
                ii++;
                j++;

                if (ii >= n ) break;

            } else {
                break;
            }
        }
        if(j == (int)c.size()){
			for(int iii = i; iii <ii; iii++){
				vis[iii] = true;
			}
			fc = true;
			//~ cout << " ----- hahah1---- \n";
			break;
		}
    }
    for (int i = 0; i < n; i++) {
        int ii = i;
        int j = 0;

        //~ bool f = false;
        for (; j < (int) b.size();) {
            if (str[ii] == b[j] && vis[ii] == false) {
                //~ f = true;
                ii++;
                j++;

                if (ii >= n ) break;

            } else {
                break;
            }
        }
        if(j == (int)b.size()){
			for(int iii = i; iii <ii; iii++){
				vis[iii] = true;
			}
			//~ cout << " ----- hahah2---- \n";
			fb = true;
			break;
		}
    }
    for (int i = 0; i < n; i++) {
        int ii = i;
        int j = 0;

        //~ bool f = false;
        for (; j < (int) a.size();) {
            if (str[ii] == a[j] && vis[ii] == false) {
                //~ f = true;
                ii++;
                j++;

                if (ii >= n ) break;

            } else {
                break;
            }
        }
        if(j == (int)a.size()){
			//~ cout << " ----- hahah3---- \n";
			fa = true;
			break;
		}
    }

    if(fa == true && fb == true && fc == true){
		return true;
	}else{
		return false;
	}
}

int main () {
    __FastIO;
    int q;
    cin >> n >> q;
    cin >> str;
    a = "";
    b = "";
    c = "";

    while (q--) {
        char cc;
        cin >> cc;

        if (cc == '+') {
            int x;
            cin >> x >> cc;

            if (x == 1) a += cc;

            if (x == 2) b += cc;

            if (x == 3) c += cc;
            
            cout << a << " " << b << " " << c << "  --\n";
            
            
            if (isHappy1() || isHappy2() || isHappy3()) {
                cout << "YES\n";

            } else {
                cout << "NO\n";
            }

        } else {
            int x;
            cin >> x;

            if (x == 1) {
                int sz = (int) a.size();

                if (sz > 0) {
                    a.erase (a.begin() + (sz - 1) );
                }
            }

            if (x == 2) {
                int sz = (int) b.size();

                if (sz > 0) {
                    b.erase (b.begin() + (sz - 1) );
                }
            }

            if (x == 3) {
                int sz = (int) c.size();

                if (sz > 0) {
                    c.erase (c.begin() + (sz - 1) );
                }
            }
            cout << a << " " << b << " " << c << "  --1\n";
            if (isHappy1() || isHappy2() || isHappy3()) {
                cout << "YES\n";

            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
