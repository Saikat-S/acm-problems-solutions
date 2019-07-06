/***************************************************
 * Problem Name : B. Lost Numbers.cpp
 * Problem Link : https://codeforces.com/contest/1167/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-05-31
 * Problem Type : Edu - B
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
#define __FileRead freopen ("input.txt", "r", stdin);
#define __FileWrite freopen ("output.txt", "w", stdout);
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
    set<int>st;
    st.insert (4);
    st.insert (8);
    st.insert (15);
    st.insert (16);
    st.insert (23);
    st.insert (42);
    int num;
    vector<int>vec;
    cout << "? " << 1 << " " << 1 << "\n";
    fflush (stdout);
    cin >> num;
    num = (int) sqrt (num);
    auto it = st.find (num);
    st.erase (it);
    vec.pb (num);
    cout << "? " << 2 << " " << 2 << "\n";
    fflush (stdout);
    cin >> num;
    num = (int) sqrt (num);
    it = st.find (num);
    st.erase (it);
    vec.pb (num);
    cout << "? " << 3 << " " << 4 << "\n";
    fflush (stdout);
    cin >> num;
    int a, b;

    for (it = st.begin(); it != st.end(); it++) {
        int x = *it;
        auto it_tmp = st.find (num / x);

        if (num % x == 0  && it_tmp != st.end() && x != num / x) {
            a = x;
            b = num / x;
            break;
        }
    }

    cout << "? " << 4 << " " << 5 << "\n";
    fflush (stdout);
    cin >> num;
    int c;

    if (num % a == 0 && (it = st.find (num / a) ) != st.end() && a != (num / a) ) {
        vec.pb (b);
        vec.pb (a);
        vec.pb (num / a);
        c = num / a;

    } else {
        vec.pb (a);
        vec.pb (b);
        vec.pb (num / b);
        c = num / b;
    }

    it = st.find (a);
    st.erase (it);
    it = st.find (b);
    st.erase (it);
    it = st.find (c);
    st.erase (it);
    cout << "! ";
    it = st.begin();
    vec.pb (*it);

    for (int i = 0; i < (int) vec.size(); i++) {
        cout << vec[i] << " ";
    }

    nl;
    return 0;
}
