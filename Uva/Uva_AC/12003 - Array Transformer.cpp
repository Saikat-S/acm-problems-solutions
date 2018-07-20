/***************************************************
 * Problem Name : 12003 - Array Transformer.cpp
 * Problem Link : https://uva.onlinejudge.org/external/120/12003.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-05-25
 * Problem Type : Data Structure(srt root decomposition)
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
#define MAX 300005
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
ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
vector<int>block[550];
int ar[MAX];
int blockSz;

void update(int i, int pre, int value) {
    int id =  i/blockSz;
    int x = (int)(lower_bound(all(block[id]), pre) - block[id].begin());
    block[id][x] = value;
    ar[i] = value;
    sort(all(block[id]));
}

int query(int L, int R, int value) {
    int l = L/blockSz;
    int r = R/blockSz;
    if (l == r) {
        int sum = 0;
        for (int i = L; i <= R; i++) {
            if(ar[i] >= value) sum++;
        }
        return sum;
    }
    int sum = 0;
    for (int i = L; i < (l + 1)*blockSz; i++) {
        if(ar[i] < value) sum++;
    }
    for (int i = l + 1; i < r; i++) {
        int x = (int)(lower_bound(all(block[i]), value) - block[i].begin());
        sum+=x;
    }
    for (int i = r * blockSz; i <= R; i++) {
        if(ar[i] < value) sum++;
    }
    return sum;
}
int main () {
    __FastIO;
    int n, m, u;
    cin >> n >> m >> u;
    blockSz = (int)sqrt(n);
    for(int i = 0; i<n; i++) {
        cin >> ar[i];
        int id = i/blockSz;
        block[id].pb(ar[i]);
    }
    
    for(int i = 0; i<=blockSz; i++) {
        sort(all(block[i]));
    }
    for(int q = 1; q<=m; q++) {
        int l, r, v, p;
            cin >> l >> r >> v >> p;
            int ans = query(l-1, r-1, v);
            int id = p-1;
            int value = ((ll)u *(ll)ans)/(r- l + 1); 
            int pre = ar[id];
            update(id, pre, value);
    }
    for(int i = 0; i<n; i++){
		cout << ar[i]<<"\n";
	}
    return 0;
}
