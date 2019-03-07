/***************************************************
 * Problem Name : C. Birthday.cpp
 * Problem Link : https://codeforces.com/contest/1131/problem/A
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2019-02-24
 * Problem Type : Div 2 - C
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
    //~ __FastIO;
    int n;
    cin >> n;
    //~ int ar[n + 3];
    map<int, int>mp;
    //~ set<int>st;
    vector<int>vec (n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        //~ st.insert(ar[i]);
        //~ if(mp[ar[i]] == 0) vec.pb(ar[i]);
        //~ mp[ar[i]]++;
    }

    sort (all (vec) );
    int x = 0, y = n - 1;
    int ar[n + 3];

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            ar[x++] = vec[i];

        } else {
            ar[y--] = vec[i];
        }
    }

    //~ for(int i = 0; i<(int)vec.size(); i++){
    //~ if(mp[vec[i]]>1){
    //~ for(int j = 1; j<mp[vec[i]]; j++){
    //~ cout << vec[i]<<" ";
    //~ }
    //~ mp[vec[i]] = 1;
    //~ }else{
    //~ cout << vec[i]<<" ";
    //~ mp[vec[i]] = 0;
    //~ }
    //~ }
    for (int i = 0; i < n; i++) {
        cout << ar[i] << " ";
    }

    nl;
    return 0;
}
