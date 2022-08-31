#include <bits/stdc++.h>

using namespace std;

int main() { 
    int t; cin >> t;

    while (t--) {
        string s; cin >> s;

        int n = s.size()-1;
        
        int fia = -1, fib = -1, lia = -1, lib = -1;

        for (int i=s.size()-1;i>=0;i--) if (s[i] == '0') { lia = i; break; }
        for (int i=s.size()-1;i>=0;i--) if (s[i] == '5') { lib = i; break; }

        for (int i=lia-1;i>=0;i--) if (s[i] == '0' || s[i] == '5') { fia = i; break; }
        for (int i=lib-1;i>=0;i--) if (s[i] == '2' || s[i] == '7') { fib = i; break; }

        int ans = INT_MAX;
        if (fib != -1 && lib != -1) ans = min(ans, n-1-fib);
        if (fia != -1 && lia != -1) ans = min(ans, n-1-fia);

        cout << ans << '\n';
    }

    return 0; 
}