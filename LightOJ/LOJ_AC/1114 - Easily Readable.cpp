/***************************************************
 * Problem Name : 1114 - Easily Readable.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1114
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
struct TrieTree {
    TrieTree *child[52];
    int isEnd;

    TrieTree *createNode() {
        TrieTree *nNode = new TrieTree;
        nNode->isEnd = 0;

        for (int i = 0; i < 52; i++) {
            nNode->child[i] = NULL;
        }

        return nNode;
    }
    int get (char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            return (ch - 'A');

        } else {
            return ( (ch - 'a') + 26);
        }
    }
    void insert (TrieTree *root, string key) {
        TrieTree *tmpNode = root;

        for (int i = 0; i < (int) key.size(); i++) {
            int indx = get (key[i]);

            if (tmpNode->child[indx] == NULL) {
                tmpNode->child[indx] = createNode();
            }

            tmpNode = tmpNode->child[indx];
        }

        tmpNode->isEnd++;
    }
    int search (TrieTree *root, string key) {
        TrieTree *tmpNode = root;

        for (int i = 0; i < (int) key.size(); i++) {
            int indx = get (key[i]);

            if (tmpNode->child[indx] == NULL) {
                return 0;
            }

            tmpNode = tmpNode->child[indx];
        }

        if (tmpNode != NULL) return tmpNode->isEnd;
        else return 0;
    }

    string getString (string str) {
        int sz = (int) str.size();

        if (sz > 2) {
            sort (str.begin() + 1, str.end() - 1);
        }

        return str;
    }

    void del (TrieTree *root) {
        for (int i = 0; i < 52; i++) {
            if (root->child[i] != NULL) {
                del (root->child[i]);
            }
        }

        delete (root);
    }
};
int main () {
    //~ __FastIO;
    int tc, n, m;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n;
        TrieTree Trie;
        TrieTree *root = Trie.createNode();

        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            Trie.insert (root, Trie.getString (str) );
        }

        cin >> m;
        cin.ignore();
        cout << "Case " << t << ":\n";

        while (m--) {
            string str, q;
            getline (cin, str);
            int ans = 1;
            int x;
            stringstream ss;
            ss << str;

            while (ss >> q) {
                q = Trie.getString (q);
                x = Trie.search (root, Trie.getString (q) );
                ans *= x;
            }

            cout << ans << "\n";
        }

        Trie.del (root);
    }

    return 0;
}
