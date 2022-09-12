#include <bits/stdc++.h>

using namespace std;

string s;

int slump(int i) {
    if (s[i] == 'D' || s[i] == 'E') {
        int j = i+1;
        while (s[j] == 'F') j++;
        if (j != i+1) {
            if (s[j] == 'G') return j;
            else return slump(j);
        }
    }
    return -1;
}

int slimp(int i) {
    if (s[i] == 'A') {
        if (s[i+1] == 'H') return i+1;
        else if (s[i+1] == 'B') {
            int j = slimp(i+2);
            if (j == -1) return j;
            else {
                if (s[j+1] == 'C') return j+1;
                else return -1;
            }
        }
        else {
            int j = slump(i+1);
            if (j == -1) return j;
            else {
                if (s[j+1] == 'C') return j+1;
                else return -1;
            }
        }
    }
    return -1;
}

int slurpy() {
    return s.size() - 1 == slump(slimp(0)+1);
}

int main() {
    cout << "SLURPYS OUTPUT\n";

    int n; cin >> n;
    while (n--) {
        cin >> s;
        cout << (slurpy() ? "YES\n" : "NO\n");
    }

    cout << "END OF OUTPUT\n";
}