#include <bits/stdc++.h>

using namespace std;

#define MAXN 510

int v, ans;
vector<vector<int>> mp;
vector<int> father, vis;

bool hungry(int s) {
  for (int k=0;k<mp[s].size();k++) {
    int son = mp[s][k];
    if (vis[son] != v) {
      vis[son] = v;
      if (father[son] == -1 || hungry(father[son])) {
        father[son] = s;
        return true;
      }
    }
  }
  return false;
}

int main() {
  int t; cin >> t;
  int casos = 1;
  while (t--) {
    int b, n; cin >> b >> n;

    mp.clear();
    mp.resize(MAXN);
    vis.clear();
    vis.resize(MAXN);
    father.clear();
    father.resize(MAXN, -1);
    v = 1;
    ans = 0;

    for (int i=0;i<b;i++)
      for (int j=0;j<n;j++) {
        int f; cin >> f;
        if (f) mp[i].push_back(j);
      }

    for (int i=0;i<b;i++){
      if (hungry(i)) ans++;
      v++;
    }

    cout << "Case " << casos++ << ": a maximum of " << ans << " nuts and bolts can be fitted together\n";
  }
}