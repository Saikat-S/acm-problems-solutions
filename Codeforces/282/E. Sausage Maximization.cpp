/***************************************************
 * Problem Name : E. Sausage Maximization.cpp
 * Problem Link : https://codeforces.com/contest/282/problem/E
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-07-21
 * Problem Type : Data Structure
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
struct TrieTree {
    TrieTree *child[2];
    vector<int>key;
    ll ans;
    TrieTree *createNode() {
        TrieTree *nNode = new TrieTree;

        for (int i = 0; i < 2; i++) {
            nNode->child[i] = NULL;
        }

        return nNode;
    }
    void insert (TrieTree *root) {
        TrieTree *tmpNode = root;

        for (int i = 0; i < (int) key.size(); i++) {
            int indx = key[i];

            if (tmpNode->child[indx] == NULL) {
                tmpNode->child[indx] = createNode();
            }

            tmpNode = tmpNode->child[indx];
        }
    }
    void search_max (TrieTree *root, int depth = 0) {
        if (root == NULL) {
            return ;
        }

        if (depth == (int) key.size() ) {
            return;
        }

        if (key[depth] == 0) {
            if (root->child[1] != NULL) {
                ans += (1LL << (39LL - depth) );
                search_max (root->child[1], depth + 1);

            } else if (root->child[0] != NULL) {
                search_max (root->child[0], depth + 1);
            }

        } else if (key[depth] == 1) {
            if (root->child[0] != NULL) {
                ans += (1LL << (39LL - depth) );
                search_max (root->child[0], depth + 1);

            } else if (root->child[1] != NULL) {
                search_max (root->child[1], depth + 1);
            }

        } else {
            return;
        }
    }
    void getBinary (ll num) {
        key.clear();

        while (num > 0) {
            key.pb (num % 2LL);
            num /= 2LL;
        }

        int x = 40 - (int) key.size();

        while (x--) key.pb (0);

        reverse (all (key) );
    }

};

int main () {
    __FastIO;
    int n;
    cin >> n;
    ll *ar = (ll *) calloc (n, sizeof (ll) );
    ll *sum = (ll *) calloc (n, sizeof (ll) );
    ll *cum = (ll *) calloc (n, sizeof (ll) );

    for (int i = 0; i < n; i++) {
        cin >> ar[i];

        if (i == 0) {
            sum[i] = ar[i];

        } else {
            sum[i] = sum[i - 1] ^ ar[i];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            cum[i] = ar[i];

        } else {
            cum[i] = cum[i + 1] ^ ar[i];
        }
    }

    TrieTree Trie;
    TrieTree *root = Trie.createNode();
    Trie.getBinary (0LL);
    Trie.insert (root);
    ll ans_max = 0;

    for (int i = 0; i < n; i++) {
        Trie.ans = 0;
        Trie.getBinary (cum[i]);
        Trie.search_max (root);
        ans_max = max (ans_max, Trie.ans);
        Trie.getBinary (sum[i]);
        Trie.insert (root);
    }

    Trie.ans = 0;
    Trie.getBinary (0);
    Trie.search_max (root);
    ans_max = max (ans_max, Trie.ans);
    cout << ans_max << "\n";
    return 0;
}

