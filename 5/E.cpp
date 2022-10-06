#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<long long> a(n+1);
        for (int i=1;i<=n;i++) cin >> a[i];

        int ans = 0;
        for (int i=1;i<=n;i++)
            for (int j=a[i]-i;j<=n;j+=a[i])

                if (j >= 0 && i < j && a[i]*a[j] == i+j) ans ++;
        
        cout << ans << endl;
    }

    return 0;
}