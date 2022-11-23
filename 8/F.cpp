#include <bits/stdc++.h>

#define MAXN 25

using namespace std;

int lands, ans;
bool vis[MAXN][MAXN];
char g[MAXN][MAXN];
int m, n, x, y;

void ff(int i, int j) {
    vis[i][j] = true;
    lands++;
    if(!vis[i][(j+1)%n]) ff(i, (j+1)%n);
    if(!vis[i][(j-1+n)%n]) ff(i, (j-1+n)%n);
    if(i+1 < m && !vis[i+1][j]) ff(i+1, j);
    if(i-1 >= 0 && !vis[i-1][j]) ff(i-1, j);
}

int main() {
    while (cin >> m >> n) {
        memset(vis, 0, sizeof vis);

        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                cin >> g[i][j];

        cin >> x >> y;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(g[i][j] == 'w')
                    vis[i][j] = 1;

        ff(x,y);

        ans = 0;
        for (int i=0;i<m;i++) 
            for (int j=0;j<n;j++)
                if (!vis[i][j]) {
                    lands = 0;
                    ff(i, j);
                    ans = max(lands, ans);
                }
        
        cout << ans << '\n';
    }

    return 0;
}