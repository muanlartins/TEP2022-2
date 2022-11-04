#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int>> pieces;
pair<int, int> l, r;
bool possible;
vector<bool> used;
vector<bool> flip;

void bt(vector<pair<int, int>> seq) {
    if (seq.size() == n) {
        if (seq[n-1].second == r.first) possible = true;
        return;
    }

    for (int i=0;i<pieces.size();i++) {
        if (used[i]) continue;
        if (seq[seq.size()-1].second == pieces[i].first || seq[seq.size()-1].second == pieces[i].second) {
            seq[seq.size()-1].second == pieces[i].first ? 
            seq.push_back(pieces[i]) : 
            seq.push_back({pieces[i].second, pieces[i].first});
            used[i] = true;
            bt(seq);
            used[i] = false;
            seq.pop_back();
        }
    }
}

int main() {
    while (true) {
        possible = false;
        cin >> n;
        if (!n) return 0; 
        cin >> m;
        cin >> l.first >> l.second >> r.first >> r.second;
        pieces.resize(m);
        used.resize(m);
        flip.resize(m);
        for (int i=0;i<m;i++) cin >> pieces[i].first >> pieces[i].second;

        vector<pair<int, int>> seq;
        for (int i=0;i<pieces.size();i++) {
            if (pieces[i].first == l.second || pieces[i].second == l.second) {
                pieces[i].first == l.second ? 
                seq.push_back(pieces[i]) : 
                seq.push_back({pieces[i].second, pieces[i].first});
                used[i] = true;
                bt(seq);
                used[i] = false;
                seq.pop_back();
            }
        }

        cout << (possible ? "YES\n" : "NO\n");
    }
}
