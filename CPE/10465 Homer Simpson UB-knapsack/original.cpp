#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define eb emplace_back
#define ef emplace_front
#define endl '\n'
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int m, n, t;
    while (cin >> m >> n >> t) {
        vector<vector<int>> c(2+1, vector<int>(t+1, -1));
        for (auto &elem: c[0]) elem = -1;
        c[0][0] = c[1][0] = c[2][0] = 0;
        
        int weights[3] = {-1, m, n};
        for (int i = 1; i <= 2; i++) {
            for (int j = weights[i]; j <= t; j++) {
                if (c[i][j-weights[i]] == -1 && c[i-1][j] == -1) 
                    c[i][j] = -1;
                else
                    c[i][j] = max(c[i-1][j], c[i][j-weights[i]] + 1);
            }
        }

        // TODO: 想辦法找到c中的答案 (剛好用完t，或者沒用完t，但c最大且t-j最小)
        int MAX = INT_MIN;
        int beer = INT_MAX;
        multimap<int, int> ans;
        for (int i = 1; i <= 2; i++) {
            for (int j = t; j >= 0; j--) {
                if (c[i][j] == -1) continue;
                ans.insert(pair<int, int>{c[i][j], t-j});
            }
        }
        auto iter = ans.rbegin();
        cout << (*iter).first << " " << (*iter).second << endl;
        // MAX = (*iter).first;
        // beer = (*iter).second;
        // iter++;
        // for (iter; iter != ans.rend(); iter++) {
        //     cout << (*iter).first << " " << (*iter).second << endl;
        // }
    }
}