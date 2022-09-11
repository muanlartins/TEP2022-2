#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int m, n;
        cin >> m >> n;

        vector<int> a(m), u(n);

        for (auto &x : a) cin >> x;
        for (auto &x : u) cin >> x;

        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, less<int>> pq2;

        int i = 0, j = 0, k = 1;
        while (j < n) {
            if (i == u[j]) {
                j++;
                if (pq2.size() < k) {
                    int x = pq1.top(); pq1.pop();
                    pq2.push(x);
                }
                cout << pq2.top() << '\n';
                k++;
            } else {
                if (pq2.size() < k) {
                    pq1.push(a[i]);
                    int x = pq1.top(); pq1.pop();
                    pq2.push(x);
                } else if (pq2.top() > a[i]) {
                    int x = pq2.top(); pq2.pop();
                    pq1.push(x);
                    pq2.push(a[i]);
                } else pq1.push(a[i]);
                i++;
            }
        }

        if (t) cout << '\n';
    }

    return 0;
}