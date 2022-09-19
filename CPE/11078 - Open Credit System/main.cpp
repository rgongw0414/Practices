#include <bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define endl '\n'
using namespace std;

bool comp_score(const pair<int, int> a, const pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    int n;
    pair<int, int> pinit(0, 0);
    while (t--) {
        cin >> n; // the num of students, 2 <= n <= 1e5
        vector<pair<int, int>> score(n, pinit);
        // list<pair<int, int>> score(n, pinit);
        int index = 0;
        int s;
        for (auto &p: score) {
            cin >> s;
            p.first += index; p.second += s;
            index++;
        }
        
        sort(score.begin(), score.end(), comp_score); // sort the score in ascending order
        int max = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = n-1; j >= 0; j--) {
                if (score[i].first != score[j].first) {
                    if (score[i].first < score[j].first) {
                        if (score[i].second - score[j].second > max) max = score[i].second - score[j].second;
                    }
                }
            }
        }
        cout << max << endl;
    }
}