/***************************************************
 * Problem Name : 1269 - Consecutive Sum.cpp
 * Problem Link : lightoj.com/volume_showproblem.php?problem=1269
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-07-17
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
#define pll pair <int, int>
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
#define MAX 50005
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
int lcm (int a, int b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
struct TrieNode {
    TrieNode *child[2];
};
vector<int>key;
int xorNum1;
int xorNum2;
TrieNode *getNode() {
    TrieNode *pNode = new TrieNode;

    for (int i = 0; i < 2; i++) {
        pNode->child[i] = NULL;
    }

    return pNode;
}
void insert (TrieNode *root) {
    TrieNode *tmpNode = root;

    for (int i = 0; i < (int) key.size(); i++) {
        int indx = key[i];

        if (tmpNode->child[indx] == NULL) {
            tmpNode->child[indx] = getNode();
        }

        tmpNode = tmpNode->child[indx];
    }
}
void search_max (TrieNode *root, int depth = 0) {
    if (root == NULL) {
        return ;
    }

    if (depth == (int) key.size() ) {
        return;
    }

    if (key[depth] == 0) {
        if (root->child[1] != NULL) {
            xorNum1 += (1 << (31 - depth) );
            search_max (root->child[1], depth + 1);

        } else if (root->child[0] != NULL) {
            search_max (root->child[0], depth + 1);
        }

    } else if (key[depth] == 1) {
        if (root->child[0] != NULL) {
            xorNum1 += (1 << (31 - depth) );
            search_max (root->child[0], depth + 1);

        } else if (root->child[1] != NULL) {
            search_max (root->child[1], depth + 1);
        }

    } else {
        return;
    }
}
void search_min (TrieNode *root, int depth = 0) {
    if (root == NULL || depth == (int) key.size() ) {
        return ;
    }

    if (key[depth] == 1) {
        if (root->child[1] != NULL) {
            search_min (root->child[1], depth + 1);

        } else if (root->child[0] != NULL) {
            xorNum2 += (1 << (31 - depth) );
            search_min (root->child[0], depth + 1);
        }

    } else if (key[depth] == 0) {
        if (root->child[0] != NULL) {
            search_min (root->child[0], depth + 1);

        } else if (root->child[1] != NULL) {
            xorNum2 += (1 << (31 - depth) );
            search_min (root->child[1], depth + 1);
        }

    } else {
        return;
    }
}

void getBinary (int num) {
    key.clear();

    while (num > 0) {
        key.pb (num % 2);
        num /= 2;
    }

    int x = 32 - (int) key.size();

    while (x--) key.pb (0);

    reverse (all (key) );
}

void del (TrieNode *root) {
    for (int i = 0; i < 2; i++) {
        if (root->child[i] != NULL) {
            del (root->child[i]);
        }
    }

    delete (root);
}

int main () {
    __FastIO;
    int tc, n;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n;
        int *ar = (int *) calloc (n, sizeof (int) );
        int *sum = (int *) calloc (n, sizeof (int) );

        for (int i = 0; i < n; i++) {
            cin >> ar[i];

            if (i == 0) sum[i] = ar[i];
            else sum[i] = sum[i - 1] ^ ar[i];
        }

        // F(L, R) = xor of L to R
        // F(L, R) = F(1, R) xor F(1, L-1)
        // find F(L, i) where xor is max ans L<=i
        // F(L,i) = F(1, i) xor F(1, L-1)
        TrieNode *root = getNode();
        getBinary (0);
        insert (root);
        int ans_max = 0, ans_min = ar[0];

        for (int i = 0; i < n; i++) {
            xorNum1 = 0;
            xorNum2 = 0;
            getBinary (sum[i]);
            search_max (root);
            search_min (root);
            insert (root);
            ans_max = max (ans_max, xorNum1);
            ans_min = min (ans_min, xorNum2);
        }

        cout << "Case " << t << ": " << ans_max << " " << ans_min << "\n";
        del (root);
    }

    return 0;
}
