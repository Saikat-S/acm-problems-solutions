/***************************************************
 * Problem Name : D. Dr. Evil Underscores.cpp
 * Problem Link : https://codeforces.com/contest/1285/problem/D
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2020-01-10
 * Problem Type : Div/Edu - D (Trie)
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
#define rev(v) reverse(v.begin(), v.end())
#define Sqr(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
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
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
vector<int>key;
struct TrieTree {
    TrieTree *child[2];
    TrieTree *create_node() {
        TrieTree *newNode = new TrieTree;

        for (int i = 0; i < 2; i++) {
            newNode->child[i] = NULL;
        }

        return newNode;
    }
    void insert (TrieTree *root) {
        TrieTree *tmpNode = root;

        for (int i = 0; i < (int) key.size(); i++) {
            int indx = key[i];

            if (tmpNode->child[indx] == NULL) {
                tmpNode->child[indx] = create_node();
            }

            tmpNode = tmpNode->child[indx];
        }
    }
    int get_max (TrieTree *root, int depth) {
        if (root == NULL || depth < 0 ) return 0LL;

        int val = (1 << depth);

        if (root->child[0] != NULL && root->child[1] != 0) {
            int res1 = val + get_max (root->child[0], depth - 1);
            int res2 = val + get_max (root->child[1], depth - 1);
            return min (res1, res2);

        } else {
            if (root->child[0] != NULL) {
                return get_max (root->child[0], depth - 1);

            } else if (root->child[1] != NULL) {
                return get_max (root->child[1], depth - 1);
            }
        }

        return 0LL;
    }
    void get_binary (ll num) {
        key.clear();

        while (num > 0) {
            key.pb (num % 2);
            num /= 2;
        }

        int x = 31 - (int) key.size();

        while (x--) key.pb (0);

        reverse (all (key) );
    }
};

int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int n;
    ll ar[MAX];
    cin >> n;
    TrieTree Trie;
    TrieTree *root = Trie.create_node();

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        Trie.get_binary (ar[i]);
        Trie.insert (root);
    }

    int ans = Trie.get_max (root, 30);
    cout << ans << "\n";
    return 0;
}
