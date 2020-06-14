/***************************************************
 * Problem Name : B.cpp
 * Problem Link : https://codeforces.com/contest/1/problem/B
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2020-06-05
 * Problem Type : Div/Edu -
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
 ***************************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
#include <deque>
#include <stack>
#include <bitset>
#include <cassert>
#include <map>
#include <set>
#include <cassert>
#include <iomanip>
#include <random>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;

#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define __FileRead freopen ("input.txt", "r", stdin)
#define __FileWrite freopen ("output.txt", "w", stdout)
#define SET(a,v) memset(a,v,sizeof(a))
#define SZ(v) (int)v.size()
#define pii pair<int,int>
#define pil pair <int, ll>
#define pli pair <ll, int>
#define pll pair <ll, ll>
#define debug cout <<"######\n"
#define debug1(x) cout <<"### " << x << " ###\n"
#define debug2(x,y) cout <<"# " << x <<" : "<< y <<" #\n"
#define nl cout << "\n";
#define sp cout << " ";
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define all(v) v.begin(), v.end()
#define rall(v) v.begin(), v.end()
#define srt(v) sort(v.begin(), v.end())
#define r_srt(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.rbegin(), v.rend())
#define Sqr(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define MAX 100005
#define INF 1000000009
#define MOD 1000000007

template<class T>
using min_heap = priority_queue<T, std::vector<T>, std::greater<T>>;
template<typename T>
using ordered_set  = tree<T, null_type, less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

template <typename T> string toString ( T Number ) {
    stringstream ss;
    ss << Number;
    return ss.str();
}
template<typename T> int toInt (T str) {
    stringstream ss;
    ss << str;
    int num;
    ss >> num;
    return num;
}
ll lcm ( ll a, ll b ) {
    return ( a / __gcd ( a, b ) ) * b;
}
/************************************ Code Start Here ******************************************************/

void number_to_string(string str) {
	int num = toInt(str);
	string ss = "";
	while(num>0){
		char ch = (char)('A'+(num-1)%26);
		//~ cout << ch << " :\n";
		ss = ch + ss;
		if(!(num%26))num-=26;
		num/=26;
	}
	cout << ss << "\n";
}
void solve1 (string str) {
    int sum = 0;
    int z = 1;

    for (int i = (int) str.size() - 1; i >= 0; i--) {
		int tmp = ((str[i]-'A')+1)*z;
		//~ cout << str[i] << " : " << tmp << "\n";
		sum += tmp;
		z*=26;
    }
    cout << sum << "\n";
}


string fun (string str) {
    string row = "", col = "";
    int i;

    for (i = 1; i < (int) str.size(); i++) {
        if (str[i] == 'C') break;	

        row += str[i];
    }

    for (i = i + 1; i < (int) str.size(); i++) {
        col += str[i];
    }

    cout << row << " " << col << "\n";
    return str;
}

int main () {
    //~ __FastIO;
    //~ cout << setprecision (10) << fixed;
    //~ cout << (52%26);
    //~ number_to_string ("55");
    //~ solve1("BC");
    int tc;
    cin >> tc;

    while (tc--) {
        string str;
        cin >> str;
        number_to_string (str);
        //~ if (str[0] == 'R') {
        //~ cout << fun (str) << "\n";
        //~ }
    }

    return 0;
}
