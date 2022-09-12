#include <bits/stdc++.h>

using namespace std;

int n, m; 
vector<vector<int>> adj;
vector<bool> vis;
vector<int> ans;

void dfs(int s) {
    vis[s] = 1;
    for (auto u : adj[s]) if (!vis[u]) dfs(u);
    ans.push_back(s);
}

int main() {
    while (true) {
        cin >> n >> m;
        if (!n && !m) return 0;

        adj.clear(); adj.resize(n+1);
        vis.clear(); vis.resize(n+1);
        ans.clear();

        for (int i=0;i<m;i++) {
            int x, y; cin >> x >> y;

            adj[x].push_back(y);
        }

        for (int i=1;i<=n;i++) if (!vis[i]) dfs(i);
        reverse(ans.begin(), ans.end());

        for (auto x : ans) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}