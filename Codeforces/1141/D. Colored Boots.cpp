/***************************************************
 * Problem Name : D. Colored Boots.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-03-19
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
#define MAX 150005
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
vector<int>v1[MAX], v2[MAX],a, b;
int main () {
    __FastIO;
    //~ int k = 1;
    //~ map<char, int>mp;
    //~ for(char i = 'a'; i<='z'; i++){
		//~ mp[i] = k++;
	//~ }
    int n;
    cin >> n;
    string A, B;
    cin >> A >> B;
    
    for (int i = 0; i < n; i++) {
		if(A[i] == '?'){
			a.pb(i);
		}else
        {
			//~ int x = mp[A[i]];
			int x = A[i];
			v1[x].pb (i);
		}
    }

    for (int i = 0; i < n; i++) {
        if(B[i] == '?'){
			b.pb(i);
		}else
        {
			//~ int x = mp[B[i]];
			int x = B[i];
			v2[x].pb (i);
		}
    }
    //~ debug;
    int ii = 0, jj = 0;
    vector<pii>vec;
    for(int i = 1; i<=26; i++){
		int x = v1[i].size();
		int xx = v2[i].size();
		if(x>=xx){
			for(int j = 0; j < xx; j++){
				vec.pb(pii(v1[i][j], v2[i][j]));
			}
			//~ debug;
			for(int j = xx; j<x; j++){
				if(jj<(int)b.size()){
					vec.pb(pii(v1[i][j], b[jj++]));
					//~ b.erase(b.begin()+0);
				}
			}
			//~ debug;
			
			
		}else{
			for(int j = 0; j<x; j++){
				vec.pb(pii(v1[i][j], v2[i][j]));
			}
			
			for(int j = x; j<xx; j++){
				if( ii< (int)a.size()){
					vec.pb(pii(a[ii++], v2[i][j]));
					//~ a.erase(a.begin()+0);
				}
			}
		}
	}
	while(ii<(int)a.size() && jj <(int)b.size()){
		vec.pb(pii(a[ii++], b[jj++]));
		//~ a.erase(a.begin()+0);
		//~ b.erase(b.begin()+0);
	}
	cout << (int)vec.size() << "\n";
	for(int i = 0; i<(int)vec.size(); i++){
		cout << vec[i].first+1 << " " <<  vec[i].second+1 << "\n";
	}

    return 0;
}
