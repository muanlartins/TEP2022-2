#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        map<int, int> f;
        for (auto &x : v) cin >> x;
        for (auto x : v) f[x]++;

        if (!f[1]) { cout << "YES\n"; continue; }
        bool consecutives = false;
        for (auto x : v) consecutives |= (f[x-1] || f[x+1]);
        cout << (consecutives ? "NO\n" : "YES\n");
    }
}