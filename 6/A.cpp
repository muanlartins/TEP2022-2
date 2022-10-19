#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n; 

    while (cin >> n && n != 0) {
        if (n < 0) n *= -1;
        long long aux = n;
        long long lpd = 0;
        map<long long, int> f;

        for (long long i=2;i*i<=n;i++) {
            while (!(aux%i)) {
                aux /= i;
                lpd = max(lpd, i);
                f[i]++;
            }
        }

        if (aux > 1) { lpd = max(lpd, aux); f[aux]++; }

        cout << (f.size() > 1 ? lpd : -1) << '\n';
    }

    return 0;
}