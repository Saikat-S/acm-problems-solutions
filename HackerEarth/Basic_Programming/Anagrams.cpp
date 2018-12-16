/***************************************************
 * Problem Name : Anagrams.cpp
 * Problem Link : Basic Programming Input/Output Basics of Input/Output
 * OJ           : HackerEarth
 * Verdict      : AC
 * Date         : 2018-12-08
 * Problem Type : Very Easy
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
    //~ __FastIO;
    int tc;
    string str1, str2;
    cin >> tc;

    while (tc--) {
        cin >> str1 >> str2;
        map<char, int>mp, mpp;
        int a = (int) str1.size();
        int b = (int) str2.size();
        int ans = a + b;

        for (int i = 0; i < (int) str1.size(); i++) {
            mp[str1[i]]++;
        }

        set<char>st;

        for (int i = 0; i < (int) str2.size(); i++) {
            mpp[str2[i]]++;
        }

        for (char i = 'a'; i <= 'z'; i++) {
            if (mp[i] != 0 && mpp[i] != 0) st.insert (i);
        }

        int cnt = 0;

        for (auto it = st.begin(); it != st.end(); it++) {
            cnt += 2 * min (mp[*it], mpp[*it]);
        }

        cout << ans - cnt << "\n";
    }

    return 0;
}
