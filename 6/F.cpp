#include <bits/stdc++.h>

using namespace std;

#define N 10000000
bool sieve[10000001];

void fulfillSieve(){
	for (int i = 2; i <= 10000; i++) 
        if (!sieve[i]) 
            for (int k = (N - 1) / i, j = i*k; k >= i; k--, j -= i) 
                sieve[j] = true;
}
int main(){
	fulfillSieve();
	int n;
	while (scanf("%d", &n) == 1){
		if (n < 8) cout << "Impossible.\n";
		else{
			if (n % 2 == 0)
				printf("%d %d ", 2, 2), n -= 4;
			else
				printf("%d %d ", 2, 3), n -= 5;
			for (int i = 2; ; i++)
                if (!sieve[i] && !sieve[n - i]){
                    cout << i << ' ' << n-i << '\n';
                    break;
                }
		}
	}
	return 0;
}