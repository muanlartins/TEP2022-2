#include <bits/stdc++.h>

using namespace std;

double calc(int a, int b) {
  return sqrt((double) (a*a + b*b));
}

int main() {
  int t; cin >> t;

  while (t--) {
    double dist = 0;
    int a, b, c, d; 
    cin >> a >> b;

    string s; getline(cin, s);

    while (getline(cin, s)) {
      if (s.empty()) break;

      stringstream ss(s);

      ss >> a >> b >> c >> d;

      dist += calc(a-c, b-d);
    }

    double f, i;

    f = modf(dist/10000.0, &i);
    f = round(f*60);

    if (f >= 60.0) { f=0; i++; }

    printf("%.0lf:%02.0lf\n", i, f);

    if (t) cout << '\n';
  }
}