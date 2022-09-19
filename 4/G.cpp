#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int x; cin >> x;

        string w = "";
        for (int i=0;i<s.size();i++) w += "1";

        for (int i=0;i<s.size();i++) if (s[i] == '0') {
            if (i-x >= 0) w[i-x] = '0';
            if (i+x < s.size()) w[i+x] = '0';
        }

        bool possible = true;
        for (int i=0;i<s.size();i++) {
            if (s[i] == '1') {
                bool temp = false;
                if (i-x >= 0 && w[i-x] == '1') temp = true;
                if (i+x < s.size() && w[i+x] == '1') temp = true;
                if (!temp) possible = false;
            }
        }

        if (possible) cout << w << '\n';
        else cout << "-1" << '\n';
    }

    return 0;
}