#include <bits/stdc++.h>

using namespace std;

int main(){
    int pancakes[30];
    string s;
    
    while(getline(cin,s)) {
        istringstream is(s);
        
        cout << s << endl;

        int x, n = 0;
        
        while(is >> x) pancakes[n++] = x;
        
        for(int i=n-1;i>=0;i--){
            
            int max = -1, ind;
            
            for (int j=0;j<=i;j++)
                if(max <= pancakes[j]) {
                    max = pancakes[j];
                    ind = j;
                }
            
            if (ind != i) {
                if(ind != 0) {
                    cout << n - ind << " ";
                    
                    for(int j=0;j<=ind/2;j++) swap(pancakes[j],pancakes[ind-j]);
                }
                
                cout<< n - i << " ";
                
                for(int j=0;j<=i/2;j++) swap(pancakes[j],pancakes[i-j]);
            }
        }
        
        cout << 0 << '\n';
    }
    
    return 0;
}