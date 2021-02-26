/***************************************************
 * Problem Name : 1224 - DNA Prefix.cpp
 * Problem Link : http://www.lightoj.com/volume_showproblem.php?problem=1224
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-07-18
 * Problem Type : Data Structure (Trie)
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
    TrieTree *child[4];
    int word, ans;
    
    TrieTree *getNode() {
        TrieTree *nNode = new TrieTree;
        nNode->word = 0;

        for (int i = 0; i < 4; i++) {
            nNode->child[i] = NULL;
        }

        return nNode;
    }
    int get (char ch) {
        if (ch == 'A') return 0;
        else if (ch == 'C') return 1;
        else if (ch == 'G') return 2;
        else return 3;
    }
    void insert (TrieTree *root, string key) {
        TrieTree *tmpNode = root;

        for (int i = 0; i < (int) key.size(); i++) {
            int indx = get (key[i]);

            if (tmpNode->child[indx] == NULL) {
                tmpNode->child[indx] = getNode();
            }

            tmpNode = tmpNode->child[indx];
            tmpNode->word++;
        }
    }
    void search (TrieTree *root, int depth = 0) {
        if (root == NULL) {
            return;
        }

        ans = max (ans, root->word * depth);

        for (int i = 0; i < 4; i++) {
            if (root->child[i] != NULL) {
                search (root->child[i], depth + 1);
            }
        }
    }
    void del (TrieTree *root) {
        for (int i = 0; i < 4; i++) {
            if (root->child[i] != NULL) {
                del (root->child[i]);
            }
        }

        delete (root);
    }
};
int main () {
    __FastIO;
    int tc, n;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n;
        TrieTree Trie;
        TrieTree *root = Trie.getNode();

        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            Trie.insert (root, str);
        }

        Trie.ans = 0;
        Trie.search (root);
        cout << "Case " << t << ": " << Trie.ans << "\n";
        Trie.del (root);
    }

    return 0;
}

