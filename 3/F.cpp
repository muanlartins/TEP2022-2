#include <bits/stdc++.h>

using namespace std;

int main() {
    while (true) {
        string s;
        getline(cin, s);
        if (s[0] == '.') break;

        int i;
        bool power = true;

        for (i=1;i<s.size()-1;i++) {
            if (s.size()%i != 0) continue;
            for (int j=i;j<s.size();j++) if(s[j] != s[j%i]) { power = false; break; }
            if (power) break;
            power = true;
        }

        cout << (power ? s.size()/i : s.size()) << '\n';
    }

    return 0;
}