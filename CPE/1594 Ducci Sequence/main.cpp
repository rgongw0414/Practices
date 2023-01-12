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
    
    int t;
    cin >> t;
    while (t--) {
        int s;
        cin >> s;
        int tmp = s;
        vector<int> input(s, 0);
        int i = 0;
        while (tmp--) cin >> input[i++];
        vector<vector<int>> list(1000+1, vector<int>(s, 0));
        list[0] = input;
        i = 1;
        tmp = 1000;
        vector<int> zero(s, 0);
        bool done = false;
        while (tmp--) {
            for (int j = 0; j < s; j++) {
                list[i][j] = abs(list[i-1][j%s] - list[i-1][(j+1)%s]);
            }
            if (list[i] == zero) {
                cout << "ZERO\n";
                done = true;
                break;
            }
            i++;
        }
        if (done) continue;
        for (int i = 0; i <= 1000; i++) {
            if (done) break;
            for (int j = 0; j <= 1000; j++) {
                if (i == j) continue;
                if (done) break;
                if (list[i] == list[j]) {
                    cout << "LOOP\n";
                    done = true;
                }
            }
        }
    }
}