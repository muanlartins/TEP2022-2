#include <bits/stdc++.h>

using namespace std;

int ans;

int solve(int sum, int partial, char *c) {
	int number;
	while(*c == ' ' || *c == '\n') *c = getchar();
	if(*c == '(') {
        string s = "";

		while(*c = getchar()) {
			if(!((*c >= '0' && *c <= '9') || (*c == '-'))) break;
            s += *c;
		}

        if (s == "") return 0;
        number = stoi(s);
		while(*c == ' ' || *c == '\n') *c = getchar();

		int left = solve(sum+number, partial, c);
		while((*c = getchar()) != '(');
		int right = solve(sum+number, partial, c);
		while((*c = getchar()) != ')');

		if((left == 0 && right == 0) && (sum+number == partial)) ans = 1;

		return 1;
	}
}

int main() {
	int I;
    char c;
	while(cin >> I) {
		ans = false; c = getchar();

		solve(0, I, &c);

		cout << (ans ? "yes\n" : "no\n");
	}
    return 0;
}