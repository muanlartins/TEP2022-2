#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    while (getline(cin, a) && getline(cin, b)) {
        multiset<char> sa, sb;
        for (auto c : a) sa.insert(c);
        for (auto c : b) sb.insert(c);
        
        vector<char> v(min(a.size(), b.size())+1);
        set_intersection(sa.begin(), sa.end(), sb.begin(), sb.end(), v.begin());

        for (auto x : v) cout << x;
        cout << '\n';
    }

    return 0;
}