#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        map<char, int> f;
        for (auto c : s) f[c]++;
        int sum = 0;
        for (auto c : s) sum += (c-'0');

        bool even = (f['0']-1 > 0) || f['2'] || f['4'] || f['6'] || f['8'];

        if (f['0'] && !(sum%3) && even) cout << "red\n";
        else cout << "cyan\n";
    }

    return 0;
}