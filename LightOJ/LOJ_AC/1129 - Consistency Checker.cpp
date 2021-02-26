/***************************************************
 * Problem Name : 1129 - Consistency Checker.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1129
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-07-16
 * Problem Type : Data Structure(Trie)
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
    TrieNode *child[10];
    bool isEnd;
};

TrieNode *getNode() {
    TrieNode *pNode = new TrieNode;
    pNode->isEnd = false;

    for (int i = 0; i < 10; i++) {
        pNode->child[i] = NULL;
    }

    return pNode;
}

void insert (TrieNode *root, string key) {
    TrieNode *tmpNode = root;

    for (int i = 0; i < (int) key.size(); i++) {
        int indx = key[i] - '0';

        if (tmpNode->child[indx] == NULL) {
            tmpNode->child[indx] = getNode();
        }

        tmpNode = tmpNode->child[indx];
    }

    tmpNode->isEnd = true;
}

bool isEmpty (TrieNode *root) {
    for (int i = 0; i < 10; i++) {
        if (root->child[i] != NULL) {
            return false;
        }
    }

    return true;
}


bool isConsistent (TrieNode *root) {
    if (root == NULL) {
        return false;
    }

    if (isEmpty (root) ) {
        return false;
    }

    if (root->isEnd == true) {
        return true;
    }

    bool f = false;

    for (int i = 0; i < 10; i++) {
        if (root->child[i] != NULL ) {
            f = f | isConsistent (root->child[i]);
        }
    }

    return f;
}

void del (TrieNode *root) {
    for (int i = 0; i < 10; i++) {
		if(root->child[i] != NULL) del (root->child[i]);
    }

    delete (root);
}


int main () {
    //~ __FastIO;
    int tc, n;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n;
        TrieNode *root = getNode();

        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            insert (root, str);
        }

        bool ans = isConsistent (root);

        //~ cout << ans << " ---\n";

        if (!ans) {
            cout << "Case " << t << ": YES\n";

        } else {
            cout << "Case " << t << ": NO\n";
        }

        del (root);
    }

    return 0;
}
/*
2
3
911
97625999
91125426
5
113
12340
123440
12345
98346
*/
