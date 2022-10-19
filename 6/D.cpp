#include <bits/stdc++.h>

using namespace std;

#define N 65000

bool p[N+1];

void sieve() {
	int i, j;
	for(i = 2; i < 65000; i++) 
		if(!p[i])
			for(j = 2; i*j < 65000; j++) 
				p[i*j] = 1;
}

long long mod(long long x, long long n, long long m) {
	if (!n) return 1%m;
	long long u = mod(x, n/2, m);
	u = (u*u)%m;
	if (n%2) u = (u*x)%m;
	return u;
}

int check(int n) {
	for(int i = 2; i <= n-1; i++) if(mod(i, n, n) != i) return 0;
	return 1;
}

int main() {
	sieve();
	int n;
	while(cin >> n && n) 
		(p[n] && check(n)) ? 
		cout << "The number " << n << " is a Carmichael number.\n" : 
		cout << n << " is normal.\n";

    return 0;
}