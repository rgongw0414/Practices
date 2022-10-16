#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define eb emplace_back
#define ef emplace_front
#define endl '\n'
using namespace std;

void solve() {
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, m;
	int x = 0;  // x: round counter, y: input length sum 
	string input, output, answer;
	bool ac, pe;

    while (cin >> n && n) {
        cin.ignore();  // ignore the '\n' after integer
		++x;
		int y = 0;
		output = "";
		answer = "";
		// read in first inputs
		for(int i = 0; i < n; ++i){
			getline(cin, input);
			y += input.length();
			if(i){
				output += '\n';
				output += input;
			}else{
				output = input;
			}
		}
		
		cin >> m;
		cin.ignore();
		for(int i = 0; i < m; ++i){
			getline(cin,input);
			if(i){
				answer += '\n';
				answer += input;
			}else{
				answer = input;
			}
		}
		
		// assume ac first
		ac = true;
		if(output != answer) ac = false;
		if(ac){
			cout << "Run #" << x << ": Accepted " << y << endl;  // cpe format
			continue;
		}
		
		// then assume pe
		pe = true;
		for(int i=0 ; i < output.length() ; ++i){
			if(output[i] == ' ' || output[i] == '\n'){  // erase ' ' & '\n'
				output.erase(i,1);
				--i;
			}
		}
		for(int i=0 ; i < answer.length() ; ++i){
			if(answer[i] == ' ' || answer[i] == '\n'){  // erase ' ' & '\n'
				answer.erase(i,1);
				--i;
			}
		}
		if(output != answer) pe = false;
		if(pe){
			cout << "Run #" << x << ": Presentation Error " << y << endl; // cpe format
			continue;
		}
		
		cout << "Run #" << x << ": Wrong Answer " << y << endl;  // cpe format
    }
}