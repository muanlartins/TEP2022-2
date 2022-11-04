#include <bits/stdc++.h>

using namespace std;

int main() {
    int k; 
    while (cin >> k) {
        vector<pair<int, int>> v;
        for (int y=k+1;y<=2*k;y++) {
            if (!((y*k)%(y-k))) {
                int x = (y*k)/(y-k);
                v.push_back({x, y});
            }
        }
        cout << v.size() << '\n';
        for (auto p : v)
            printf("1/%d = 1/%d + 1/%d\n", k, p.first, p.second);
    }

    return 0;
}