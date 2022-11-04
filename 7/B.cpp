#include <bits/stdc++.h>

using namespace std;

int t[10][10];
bool col[10], diag1[10], diag2[10];
vector<vector<int>> boards;

void createBoards(vector<int> board) {
    int j = board.size()+1;
    if (board.size() == 8) {
        boards.push_back(board);
        return;
    }

    for (int i=1;i<=8;i++) {
        if (col[i] || diag1[i+j] || diag2[i-j+8-1]) continue;
        col[i] = diag1[i+j] = diag2[i-j+8-1] = 1;
        board.push_back(i);
        createBoards(board);
        board.pop_back();
        col[i] = diag1[i+j] = diag2[i-j+8-1] = 0;
    }
}

int main() {
    int p[10];
    vector<int> v;
    createBoards(v);
    int cs = 1;
    while (cin >> p[0]) {
        for (int i=2;i<=8;i++) cin >> p[i-1];

        int ans = 8;
        for (auto board : boards) {
            int r = 0;
            for (int i=0;i<board.size();i++) r += p[i] != board[i];
            ans = min(ans, r);
        }
        printf("Case %d: %d\n", cs++, ans);
    }
}