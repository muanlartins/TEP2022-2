#include <bits/stdc++.h>

using namespace std;

#define MAXN 30001
int friends, ans;
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int s) {
    vis[s] = true;
    friends++;
    for (auto u : adj[s]) if (!vis[u]) dfs(u);
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        friends = ans = 0;
        for (int i=1;i<=n;i++) adj[i].clear();
        for (int i=1;i<=n;i++) vis[i] = false;
        for (int i=0;i<m;i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i=1;i<=n;i++) if (!vis[i]) {
            dfs(i);
            ans = max(ans, friends);
            friends = 0;
        }
        cout << ans << '\n';
    }
}