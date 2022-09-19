#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);

    for (auto &x : a) cin >> x;

    int l=0, r=n-1;
    while (l < n-1 && a[l] < a[l+1]) l++;
    while (r >= 1 && a[r] < a[r-1]) r--;
    l++; r = n-r;
    cout << (l%2 || r%2 ? "Alice\n" : "Bob\n");
    }