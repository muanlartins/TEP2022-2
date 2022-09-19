#include <bits/stdc++.h>

using namespace std;

vector<long long> a;
int n;
long long h;

bool f(long long k) {
    long long ans = k;
    for (int i=0;i<a.size()-1;i++) ans += min(a[i+1]-a[i], k);
    return ans >= h;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> h;
        
        a.resize(n);

        for (auto &x : a) cin >> x;

        long long l=0, r=1e18, ans;
        while (l <= r) {
            long long m = r + (l-r)/2;
            if (f(m)) {
                ans = m;
                r = m-1;
            } else l = m+1;
        }

        cout << ans << '\n';
    }

    return 0;
}