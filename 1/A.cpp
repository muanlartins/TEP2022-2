#include <bits/stdc++.h>

using namespace std;

int pow(int a, int b) {
    int res = 1;

    while (b--) res *= a;

    return res;
}

int calculateResult(int n) {
    int res = 0;
    for (int i=1;i<=4;i++) res += pow(i, n);
    return res;
}

int main() {
    string s;
    cin >> s;

    string lastTwoDigitsString = s.size() > 2 ? s.substr(s.size()-2) : s;
    int lastTwoDigits = stoi(lastTwoDigitsString);

    int remainder = lastTwoDigits%4;

    int res = calculateResult(remainder);

    cout << res%5 << endl;

    return 0;
}