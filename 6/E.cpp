#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, x;
    
    while(cin >> n && n){
        x = sqrt(n);
        cout << (n == x*x ? "yes\n" : "no\n");
    }
    
    return 0;
}