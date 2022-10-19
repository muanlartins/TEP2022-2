#include <bits/stdc++.h>
using namespace std;

int x, y, d;

void gcd(int a, int b) {
    if (!b) { x = 1; y = 0; d = a; return; }
    gcd(b, a % b);
    int x1 = y; int y1 = x - (a / b) * y;
    x = x1; y = y1;
}

int main() {
    int a, b;
    while(cin >> a >> b) {
        gcd(a,b);
        cout << x << ' ' << y << ' ' << d << '\n';
    }
}