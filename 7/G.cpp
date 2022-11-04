#include <bits/stdc++.h>

using namespace std;

string t[3];
bool row(char c) {
    bool winner = false;
    for (int i=0;i<3;i++) winner |= (t[i][0] == c && t[i][1] == c && t[i][2] == c);
    return winner;
}

bool col(char c) {
    bool winner = false;
    for (int i=0;i<3;i++) winner |= (t[0][i] == c && t[1][i] == c && t[2][i] == c);
    return winner;
}

bool diag(char c) {
    return (t[0][0] == c && t[1][1] == c && t[2][2] == c) || (t[0][2] == c && t[1][1] == c && t[2][0] == c);
}

int main() {
    int n; cin >> n;
    while (n--) {
        bool possible = true;
        for (int i=0;i<3;i++) cin >> t[i];
        map<char, int> f;
        for (int i=0;i<3;i++) for (int j=0;j<3;j++) f[t[i][j]]++;
        if (f['O'] > f['X'] || (f['X'] - f['O']) > 1) possible = false;
        bool xwin = row('X') || col('X') || diag('X');
        if (xwin && f['X']-f['O'] != 1) possible = false;
        bool owin = row('O') || col('O') || diag('O');
        if (owin && f['X']-f['O'] != 0) possible = false;
        if (xwin && owin) possible = false;

        cout << (possible ? "yes\n" : "no\n");
    }
}