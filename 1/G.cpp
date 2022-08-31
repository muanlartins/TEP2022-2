#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        string s; cin >> s;

        int zeros = count(s.begin(), s.end(), '0');
        int ones = count(s.begin(), s.end(), '1');

        if (zeros == ones) cout << zeros-1 << '\n';
        else cout << min(zeros, ones) << '\n';
    }

    return 0;
}