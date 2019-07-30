/***************************************************
 * Problem Name : D. Perfect Security.cpp
 * Problem Link : https://codeforces.com/problemset/problem/948/D
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-07-17
 * Problem Type : Data Structure(Trie-minXor)
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
struct TrieNode {
    TrieNode *child[2];
    int isEnd;
};
string ans;
TrieNode *getNode() {
    TrieNode *pNode = new TrieNode;
    pNode->isEnd = 0;

    for (int i = 0; i < 2; i++) {
        pNode->child[i] = NULL;
    }

    return pNode;
}

vector<int> getBinary (int n) {
    vector<int>vec;

    while (n > 0) {
        int rem = n % 2;
        vec.pb (rem);
        n /= 2;
    }

    int x = 32 - (int) vec.size();

    while (x--) vec.pb (0);

    reverse (all (vec) );
    return vec;
}

void insert (TrieNode *root, vector<int>key) {
    TrieNode *tmpNode = root;

    for (int i = 0; i < (int) key.size(); i++) {
        int indx = key[i];

        if (tmpNode->child[indx] == NULL) {
            tmpNode->child[indx] = getNode();
        }

        tmpNode = tmpNode->child[indx];
    }

    tmpNode->isEnd++;
}
void search (TrieNode *root, vector<int>key, int depth = 0) {
    if (root == NULL) {
        return ;
    }

    if (depth == (int) key.size() ) {
        return;
    }

    if (key[depth] == 0) {
        if (root->child[0] != NULL) {
            ans += (0 + '0');
            search (root->child[0], key, depth + 1);

        } else if (root->child[1] != NULL) {
            ans += (1 + '0');
            search (root->child[1], key, depth + 1);
        }

    } else if (key[depth] == 1) {
        if (root->child[1] != NULL) {
            ans += (1 + '0');
            search (root->child[1], key, depth + 1);

        } else if (root->child[0] != NULL) {
            ans += (0 + '0');
            search (root->child[0], key, depth + 1);
        }

    } else {
        return;
    }
}
bool isEmpty (TrieNode *root) {
    for (int i = 0; i < 2; i++) {
        if (root->child[i] != NULL) {
            return false;
        }
    }

    return true;
}

TrieNode *remove (TrieNode *root, vector<int>key, int depth = 0) {
    if (root == NULL) {
        return NULL;
    }

    if (depth == (int) key.size() ) {
        if (root->isEnd > 0) {
            root->isEnd--;
        }

        if (isEmpty (root) && root->isEnd == 0) {
            delete (root);
            root = NULL;
        }

        return root;
    }

    int indx = key[depth];
    root->child[indx] = remove (root->child[indx], key, depth + 1);

    if (isEmpty (root) && root->isEnd == 0) {
        delete (root);
        root = NULL;
    }

    return root;
}
int main () {
    __FastIO;
    int n;
    cin >> n;
    TrieNode *root = getNode();
    int *ar = (int *) calloc (n, sizeof (int) );
    int *pr = (int *) calloc (n, sizeof (int) );

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> pr[i];
        insert (root, getBinary (pr[i]) );
    }

    int *o = (int *) calloc (n, sizeof (int) );

    for (int i = 0; i < n; i++) {
        ans = "";
        search (root, getBinary (ar[i]) );
        int mn = 0;

        for (int i = 0; i < (int) ans.size(); i++) {
            int val = ans[i] - '0';

            if (val == 1) {
                mn += (ll) (1LL << (31LL - i) );
            }
        }

        o[i] = ar[i] ^ mn;
        remove (root, getBinary (mn) );
    }

    for (int i = 0; i < n; i++) {
        cout << o[i] << " ";
    }

    nl;
    return 0;
}
