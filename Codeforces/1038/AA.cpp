#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
typedef long long ll;
int main () {
    int n, k;
    string str;
    cin >> n >> k;
    cin >> str;
    vector<int>v;
    map<char, int>mp;

    for (int i = 0; i < n; i++) {
        mp[str[i]]++;
    }

    int x = 100000;

    for (int i = 1, ch = 'A'; i <= k; i++, ch++) {
        x = min (x, mp[ch]);
    }

    cout << x *k << "\n";
    return 0;
}

