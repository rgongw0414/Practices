#include <bits/stdc++.h>
using namespace std;
int main() {
	int t, c = 1;
	cin >> t;
	cin.get(); // catch '\0' from the first line
	cin.get(); // catch second line, i.e. "\0"
	while(t--) {
		string s, ans;
		stringstream ss;
		printf("Case #%d:\n", c++);
		while(getline(cin, s) && s != "") {
			ss.str("");
			ss.clear();
			int n = 0;
			ss << s;
			while(ss >> ans) {
				if(ans.size() > n) {
					cout << ans[n];
					n++;
				}
			}
			cout << endl;
		}
		if (t != 0) cout << endl;
	}
	return 0;
}

/*
*/