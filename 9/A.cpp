#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n);
    map<int, bool> f;
    for (int i=0;i<=n;i++) f[i] = false;

    for (auto &x : a) cin >> x;
    
    sort(a.begin(), a.end(), greater<int>());

    bool ok = true;
    for (auto x : a) {
      while (x > n || f[x]) x/=2;
      x ? f[x] = true : ok = false;
    }

    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}