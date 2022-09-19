#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    sort(v.begin(), v.end());

    int q; cin >> q;
    while (q--) {
        int m; cin >> m;
        cout << (upper_bound(v.begin(), v.end(), m) - v.begin()) << '\n';
    }

    return 0;
}