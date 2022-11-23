#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const long long INF64 = 1e18;

int n;
vector<int> a;

int main() {
	int t; cin >> t;
	while(t--) {
		cin >> n;
        a.resize(n);
        for (int i=0;i<n;i++) cin >> a[i];
		vector<int> h(n, INF);
        h[0] = 0;
        int lst = 0;
        for (int i=1;i<n;i++) {
            if (i - 1 > 0 && a[i - 1] > a[i])
                lst++;
            h[i] = h[lst] + 1;
        }
        cout << h[n - 1] << endl;
	}

	return 0;
}