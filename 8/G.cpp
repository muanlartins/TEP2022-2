#include <bits/stdc++.h>

using namespace std;

#define MAXN 205

int v, e;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> color;
bool bipartido = true;
map<bool, int> cnt;
int total;

void dfs(int s, bool c) {
    vis[s] = 1;
    color[s] = c;
    cnt[c]++;
    for (auto u : adj[s]) {
        if (color[u] == color[s]) {
            bipartido = false;
            return;
        }
        if (!vis[u]) dfs(u, !c);
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> v >> e;
        adj.clear();
        adj.resize(v);
        vis.clear();
        vis.resize(v);
        color.clear();
        color.resize(v, -1);
        total = 0;
        bipartido = true;

        for (int i=0;i<e;i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        for (int i=0;i<v;i++) if (!vis[i]) {
            cnt.clear();
            dfs(i, 0);
            total += max(1, min(cnt[0], cnt[1]));
        }

        cout << (bipartido ? total : -1) << '\n';
    }
}