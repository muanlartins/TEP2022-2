#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        int m = max({a, b, c});

        int ra = a == m && b != m && c != m ? 0 : m+1-a;
        int rb = b == m && a != m && c != m ? 0 : m+1-b;
        int rc = c == m && a != m && b != m ? 0 : m+1-c;

        cout << ra << " " << rb << " " << rc << "\n";
    }
}