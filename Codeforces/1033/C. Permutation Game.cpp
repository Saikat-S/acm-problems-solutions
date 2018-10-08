/***************************************************
 * Problem Name : C. Permutation Game.cpp
 * Problem Link : https://codeforces.com/contest/1033/problem/C
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2018-10-08
 * Problem Type : Div 1, 2 - C
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
int fun (int ar[], int n, int val, int id) {
    int pos = id + val;
    int mx = 0, ans = 0;
    while ( pos <= n) {
		//~ debug;
        if (ar[pos] > val) {
			if(ar[pos] > mx){
				mx = ar[pos];
				ans = pos;
			}
        }

        pos += val;
    }

    pos = (id - val);

    while (pos >= 1) {
        if (ar[pos] > val) {
            if(ar[pos] > mx){
				mx = ar[pos];
				ans = pos;
			}
        }

        pos = (pos - val);
    }

    return ans;
}
int main () {
    //~ __FastIO;
    int n;
    cin >> n;
    int ar[n + 3];

    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }

    string str = "";

    for (int i = 1; i <= n; i++) {
        int flag = 0;
        int val = ar[i];
        int id = i;

        while (1) {
            int x = fun (ar, n, val, id);
            cout << x << " --\n";
            if ( x == 0) {
                if (flag%2 == 0) {
                    str += "B";

                } else {
                    str += "A";
                }

                break;

            } else {
                val = ar[x];
                id = x;
                flag++;
            }
        }
        //~ break;
    }
    cout << str << "\n";

    return 0;
}
