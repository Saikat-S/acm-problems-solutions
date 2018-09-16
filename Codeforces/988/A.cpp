#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
typedef long long ll;
int main () {
    int n, k;
    cin >> n >> k;
    set<int>st;
    int ar[n + 5];

    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        st.insert (ar[i]);
    }

    int sz = st.size();

    if (sz >= k) {
        map<int, int>mp;
        int cnt = 0;
        cout <<"YES\n";
        for (int i = 1; i <= n; i++) {
            if (mp[ar[i]] == 0) {
                cout << i << " ";
                mp[ar[i]] = 1;
                cnt++;
                if(cnt == k) break;
            }
        }

        cout << "\n";

    } else cout << "NO\n";

    return 0;
}

