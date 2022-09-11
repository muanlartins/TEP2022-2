#include <bits/stdc++.h>

using namespace std;

int main() {
    int scenario = 1;

    int t;

    while (true) {
        cin >> t;
        if (t == 0) return 0;

        cout << "Scenario #" << scenario++ << '\n';

        map<int, int> team;

        for (int j=0;j<t;j++) {
            int n; cin >> n;

            for (int i=0;i<n;i++) {
                int x; cin >> x;
                team[x] = j;
            }
        }

        queue<int> big;
        vector<queue<int>> small(t);

        while (true) {
            string s; cin >> s;

            if (s == "STOP") break;
            if (s == "ENQUEUE") {
                int x; cin >> x;
                if (small[team[x]].empty()) big.push(team[x]);
                small[team[x]].push(x);
            }
            if (s == "DEQUEUE") {
                int x = big.front();
                if (!small[x].empty()) {
                    cout << small[x].front() << '\n';
                    small[x].pop();
                }
                if (small[x].empty()) big.pop();
            }
        }

        cout << '\n';
    }

    return 0;
}