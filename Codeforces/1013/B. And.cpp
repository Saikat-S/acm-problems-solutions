/***************************************************
 * Problem Name : B. And.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2018-07-30
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
#define pb push_back
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
int mp[MAX];
int ar[MAX];
int main () {
    //~ __FastIO;
    //~ cout << ( 100 & 80 )<<"\n";
    //~ cout << (64 & 80)<<"\n";
    //~ for(int i= 1; i<=100; i++){
    //~ for(int j= 1; j<=100; j++){
    //~ cout << i << " "<< j<<" = "<< (i&j)<<"\n";
    //~ }
    //~ }
    ll n, x;
    cin >> n >> x;
    set<int>st;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
		int xx;
        cin >> xx;
        mp[xx]++;
        st.insert (xx);
        ar[xx]++;
        if (mp[xx] >= 2) cnt++;
    }

    if (cnt != 0) {
        cout << "0\n";
        return 0;
    }
    int aa = 3, bb = 3;
    for (auto it = st.begin(); it != st.end(); it++) {
        int val = * it;
        int xx =  val & x;
        if(xx != val) mp[xx]++;
        //~ cout << val <<" " << mp[xx]<<" \n";
        if (mp[xx] >= 2) {
			//~ cout << xx <<"\n";
			if(ar[xx] == 0){
			  aa = 2;
			  //~ break;	
			}else{
				bb = 1;
			}
            //~ flag = 1;
        }
    }
    cnt = min(aa, bb);
    if(cnt != 3) cout << cnt <<"\n";
    else cout << "-1\n";
    return 0;
}
