#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define eb emplace_back
#define ef emplace_front
#define endl '\n'
using namespace std;

#define MIN 0
#define MAX 9999999

vector<bool> primeT(MAX+1, true); // 0 ~ 9999999
vector<int> prime; // 0 ~ 9999999

// void solve(int &i) { // this is freaking SLOW!
//     int sMAX = sqrt(9999999);
//     for (auto &n: prime) {
//         if (n > sMAX) continue;
//         if (i % n == 0) return;
//     }
//     prime.eb(i);
//     primeT[i] = true;
//     return;
// }

void solve2() {
    set<int> ans;
    string digs;
    cin >> digs;
    sort(digs.begin(), digs.end());
    for (int i = 0; i < (1 << digs.size()); i++) {
        string permS = "";
        for (int j = 0; j < digs.size(); j++) {
            if (i & (1 << j)) permS += digs[j];
        }
        do {
            int num = atoi(permS.c_str());
            if (!primeT[num]) continue;
            if (ans.count(num)) continue;
            ans.insert(num);
        } while (next_permutation(permS.begin(), permS.end()));
    }
    cout << ans.size() << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    primeT[0] = false;
    primeT[1] = false;

	for (int i = 2; i*i < MAX+1; ++i) { // this is much more faster!
		for (int j = 2; j*i < MAX+1; ++j) {
			primeT[i*j] = false;
		}
	}
    
    // for (int i = 3; i <= MAX; i++) {
    //     solve(i);
    // }

    int t;
    cin >> t;
    while (t--) {
        solve2();
    }
}