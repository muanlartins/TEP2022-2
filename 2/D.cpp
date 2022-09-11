#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
int inTree[100100];
int depth[100100];
vector<vector<int>> t;

void dfs(int v, int d, int num, int p) {
  inTree[v] = num;
  depth[v] = d;
  t[num].push_back(0);

  for (int i = 0; i < g[v].size(); i++) {
    if (g[v][i] == p) continue;
    dfs(g[v][i], d + 1, num, v);
  }
}

void add(int p, int v, int num) {
  for (int i = p; i < t[num].size(); i += (i & (-i))) t[num][i] += v;
}

int find(int p, int num) {
  int res = 0;
  for (int i = p; i > 0; i -= (i & (-i))) res += t[num][i];
  return res;
}

int main() {
  int n, q;
  cin >> n >> q;
  g.resize(n);

  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  t.resize(g[0].size() + 1);

  int inRoot = 0;

  for (int i = 0; i < g[0].size(); i++) {
    t[i].push_back(0);
    dfs(g[0][i], 1, i, 0);
  }

  t[t.size() - 1].resize(n + 10);
  for (int i = 0; i < q; i++) {
    int ty;
    scanf("%d", &ty);
    if (ty == 0) {
      int v, val, dist;
      scanf("%d%d%d", &v, &val, &dist);
      v--;
      if (v == 0) {
        inRoot += val;
        add(1, val, t.size() - 1);
        add(dist + 1, -val, t.size() - 1);
      } else {
        if (dist >= depth[v]) {
          int left = dist - depth[v];
          inRoot += val;
          add(1, val, t.size() - 1);
          add(left + 1, -val, t.size() - 1);
          add(left + 1, val, inTree[v]);
          add(depth[v] + dist + 1, -val, inTree[v]);
        } else {
          add(depth[v] - dist, val, inTree[v]);
          add(depth[v] + dist + 1, -val, inTree[v]);
        }
      }
    } else {
      int v;
      scanf("%d", &v);
      v--;
      if (v == 0)
        printf("%d\n", inRoot);
      else {
        int res = find(depth[v], inTree[v]) + find(depth[v], t.size() - 1);
        printf("%d\n", res);
      }
    }
  }

  return 0;
}