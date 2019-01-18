/***************************************************
 * Problem Name : C. Ehab and a 2-operation task.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2018-12-04
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
int main () {
    __FastIO;
    int n;
    cin >> n;
    int ar[n + 3];

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    //~ vector<pii>vec;
    vector<int>V;

    for (int i = 0; i < n; i++) ar[i] += n;

    int i = n - 1;

    while (i != 0) {
        int x = ar[i] - 1;
        int xx = ar[i - 1];
        x = abs (xx - x);
        //~ vec.pb (pii (i, x) );
        V.pb (x);
        //~ VV.pb (x);

        for (int j = 0; j < i; j++) {
            ar[j] %= x;
        }

        i--;
        //~ if (i != 0  && ar[i] > ar[i - 1]) i--;
        //~ else if (i != 0) {
        //~ int x = ar[i] - 1;
        //~ int xx = ar[i - 1];
        //~ x = xx - x;
        //~ vec.pb (pii (i, x) );
        //~ V.pb (i);
        //~ VV.pb (x);
        //~ for (int j = 0; j < i; j++) {
        //~ ar[j] %= x;
        //~ }
        //~ }
    }

    cout << (int) V.size() + 1 << "\n";
    cout << "1 " << n << " " << n << "\n";
    int val = n;

    for (int i = 0; i < (int) V.size(); i++) {
        cout << "2 " << val-- << " " << V[i] << "\n";
    }

    //~ debug;
    //~ for(int i = 0; i<n; i++){
    //~ cout << ar[i]<< " ";
    //~ }
    //~ nl;
    return 0;
}

