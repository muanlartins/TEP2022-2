#include <bits/stdc++.h>

using namespace std;

map<string, vector<pair<string, pair<int, int>>>> adj;
map<string, bool> vis;
string camila;
pair<int, int> cost;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a%b);
}

void dfs(string s, pair<int, int> c) {
    vis[s] = 1;
    if (s == camila) { 
        cost = {c.first, c.second};
        return;
    }
    for (auto u : adj[s]) {
        if (!vis[u.first]) {
            int x = c.first * u.second.first;
            int y = c.second * u.second.second;

            int d = gcd(x, y);

            x /= d;
            y /= d;

            dfs(u.first, {x, y});
        }
    }
}

int main() {
    char c; 
    while (cin >> c) {
        if (c == '!') {
            int x; cin >> x;
            string a; cin >> a;
            string eq; cin >> eq;
            int y; cin >> y;
            string b; cin >> b;

            int d = gcd(x, y);

            x /= d;
            y /= d;

            adj[a].push_back({b, {x, y}});
            adj[b].push_back({a, {y, x}});
        } else if (c == '?') {
            string a, eq;
            cin >> a >> eq >> camila;

            vis.clear();
            dfs(a, {1,1});

            (vis[camila]) ?
            cout 
                << cost.first
                << ' ' 
                << a 
                << " = " 
                << cost.second
                << ' '
                << camila 
                << '\n'
            :
            cout 
                << "?"
                << ' ' 
                << a 
                << " = " 
                << '?'
                << ' '
                << camila 
                << '\n';
        } else if (c == '.') return 0;
    }
}