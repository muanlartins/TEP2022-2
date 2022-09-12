#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int r; cin >> r;
        vector<int> s(r);

        for (auto &x : s) cin >> x;

        sort(s.begin(), s.end());

        int ans = 0;
        int house = s[s.size()/2];
        for (auto x : s) ans += abs(house - x);

        cout << ans << '\n';
    }

    return 0;
}