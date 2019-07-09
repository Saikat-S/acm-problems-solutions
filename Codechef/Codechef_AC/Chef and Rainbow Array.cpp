/***************************************************
 * Problem Name : Chef and Rainbow Array.cpp
 * Problem Link : https://www.codechef.com/problems/RAINBOWA
 * OJ           : Codechef
 * Verdict      : Trying
 * Date         : 2018-12-11
 * Problem Type : Easy
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
#define MAX 105
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
    int tc, n;
    cin >> tc;

    while (tc--) {
        cin >> n;
        int ar[MAX];

        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        if(ar[0] != 1){
			cout << "no\n";
			continue;
		}
        bool flag = false;
        //~ int x = 1;

        for (int i = 0, j = n - 1; i <= j;) {
            if (i == j) {
                if (ar[i] - ar[i - 1] >= 2) {
                    flag = true;
                    break;

                } else break;
            }

            if (ar[i] != ar[j]) {
                //~ cout << "2\n";
                flag = true;
                break;

            } else {
                if ((ar[i] - ar[i - 1]) >= 2 && i != 0) {
                    flag = true;
                    break;

                } else {
                    i++, j--;
                }
            }
        }

        if (flag) cout << "no\n";
        else cout << "yes\n";
    }

    return 0;
}
