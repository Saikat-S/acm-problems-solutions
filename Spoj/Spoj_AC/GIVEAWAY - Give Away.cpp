/***************************************************
 * Problem Name : GIVEAWAY - Give Away.cpp
 * Problem Link : http://www.spoj.com/problems/GIVEAWAY/en/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2018-05-25
 * Problem Type : Data Structure (sqrt root decomposition)
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
#define MAX 500005
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
vector<int>block[750];
int ar[MAX];
int blockSz, N;

//~ int Lower(int id, int value) {
    //~ int high = (int)block[id].size()-1, low = 0, ans = -1;
    //~ while (high >= low) {
        //~ int mid = (high + low) / 2;
        //~ if (block[id][mid] == value) {
            //~ ans = mid;
            //~ high = mid - 1;
        //~ } else if (block[id][mid] > value) {
            //~ high = mid - 1;
        //~ } else {
            //~ low = mid + 1;
        //~ }
    //~ }
    //~ if (ans == -1) {
        //~ ans = high+1;
    //~ }
    //~ return ans;
//~ }

void update(int i, int pre, int value) {
    int id =  i/blockSz;
    ar[i] = value;
    //~ int l = id * blockSz;
    //~ int r = l + block[id].size() -1;
    //~ block[id].clear();
    //~ for(int i = l; i<=r; i++){
		//~ block[id].pb(ar[i]);
	//~ }
    
    int x = (int)(lower_bound(all(block[id]), pre) - block[id].begin());
    //~ int x = Lower(id, value);
    block[id][x] = value;
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
        if(ar[i] >=value) sum++;
    }
    for (int i = l + 1; i < r; i++) {
        //~ cout << block[i][0];nl;
        //~ cout << block[i][1];nl;
        //~ cout << block[i].size();nl;
        int x = (int)(lower_bound(all(block[i]), value) - block[i].begin());
        //~ int x = Lower(i, value);
        //~ cout << " i : " << x <<"\n";
        int sz = (int)block[i].size();
        //~ cout <<sz;nl;00
        sum+=(sz-x);
        //~ cout << sum2;nl;
    }
    for (int i = r * blockSz; i <= R; i++) {
        if(ar[i] >=value) sum++;
    }
    return sum;
}
int main () {
    __FastIO;
    int Q;
    cin >> N;
    //~ ar.resize(N);
    blockSz = (int)sqrt(N);
    //~ cout << blockSz <<"\n";
    //~ return 0;
    for(int i = 0; i<N; i++) {
        cin >> ar[i];
        int id = i/blockSz;
        block[id].pb(ar[i]);
    }
    //~ int x ;
    //~ cin >>x ;
    //~ int X = (int)(lower_bound(all(ar), x) - ar.begin());
    //~ int X = lower(x);
    //~ cout << X<<"\n";
    
    for(int i = 0; i<=blockSz; i++) {
        sort(all(block[i]));
    }
    cin >> Q;
    for(int q = 1; q<=Q; q++) {
        int c, l, r;
        int value;
        cin >> c;
        if(c == 0) {
            cin >> l >> r >> value;
            int ans = query(l-1, r-1, value);
            cout << ans <<"\n";
        }
        else {
            cin >> l >> value;
            int id = l-1;
            int pre = ar[id];
            update(id, pre, value);
        }
    }
    return 0;
}

