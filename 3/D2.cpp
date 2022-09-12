#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    while (getline(cin, a) && getline(cin, b)) {
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        string intersection = "";

        for (int i=0, j=0;i<a.size() && j<b.size();) {
            if (a[i] == b[j]) {
                intersection += a[i]; i++; j++;
            } else {
                while (a[i] < b[j] && i < a.size()) i++;
                while (b[j] < a[i] && j < b.size()) j++;
            }
        }

        sort(intersection.begin(), intersection.end());

        cout << intersection << '\n';
    }

    return 0;
}