#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        if (n == 1) {

            int x; cin >> x;

            string res = x == 1 ? "YES\n" : "NO\n";

            cout << res;

        } else {

            vector<int> v(n);

            for (int i=0;i<n;i++) cin >> v[i];

            sort(v.begin(), v.end(), greater<int>());

            int x = v[0], y = v[1];

            string res = abs(x-y) <= 1 ? "YES\n" : "NO\n";

            cout << res;
        }
    }

    return 0;
}