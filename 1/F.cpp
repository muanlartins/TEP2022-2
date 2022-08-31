#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> v(k);

        for (auto &x : v) cin >> x;

        sort(v.begin(), v.end(), greater<int>());

        int ans = 0;
        long long sum = 0;
        for (auto x : v) {
            sum += n-x;
            if (sum < n) ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}