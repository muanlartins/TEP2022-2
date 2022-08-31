#include <bits/stdc++.h>

using namespace std;

void resetaFrequencia(map<char, int> &f) {
    string alfabeto = "abcdefghijklmnopqrstuvwxyz";
    for (auto letra : alfabeto) f[letra] = 0;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s; cin >> s;
        int n = s.size();

        map<char, int> f;
        resetaFrequencia(f);

        int res = 0;

        for (int i=0;i<n;i++) {
            f[s[i]] ++;
            if (f[s[i]] == 2) {
                res += 2;
                resetaFrequencia(f);
            }
        }

        cout << n - res << endl;
    }

    return 0;
}