#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;

        vector<int> ps(n+1);

        for (int i=0;i<n;i++) ps[i+1] = ps[i] + (s[i] == 'W');

        int ans = INT_MAX;

        for (int i=0;i<=n-k;i++) ans = min(ans, ps[i+k] - ps[i]);

        cout << ans << '\n';
    }
}