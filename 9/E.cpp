#include <bits/stdc++.h>

using namespace std;

vector<int> d;
vector<bool> vis;
vector<vector<int>> adj;
int n, m; 

void dfs(int s) {
  vis[s] = 1;
  for (auto u : adj[s])
    if (!vis[u]) dfs(u);
}

int main() {
  while (cin >> n >> m) {
    adj.clear();
    adj.resize(n);
    vis.clear();
    vis.resize(n, true);
    d.clear();
    d.resize(n);

    while (m--) {
      int x, y; cin >> x >> y;
      d[x]++;
      d[y]++;

      adj[x].push_back(y);
      adj[y].push_back(x);
      vis[x] = vis[y] = 0;
    }

    int f = 0;
    for (int i=0;i<n;i++) if (d[i]%2) f = 1;
    if (f) cout << "Not Possible\n";
    else {
      int components = 0;
      for (int i=0;i<n;i++){
        if (components > 1) break;
        if (!vis[i]) dfs(i), components++;
      }
      cout << (components == 1 ? "Possible\n" : "Not Possible\n"); 
    }
  }

  return 0;
}