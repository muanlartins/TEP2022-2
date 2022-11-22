#include <bits/stdc++.h>

using namespace std;

int main() {
  int len, w; cin >> len >> w;
  vector<int> a(len-1);

  for (auto &x : a) cin >> x;

  int l = 0, r = w-1;

  int ans = INT_MAX;

  for (int k=0;k<len-w;k++) {
    int soma = 0;
    for (int i=l+k;i<=r+k;i++) soma += a[i];
    ans = min(soma, ans);
  }

  cout << ans << '\n';

  return 0;
}