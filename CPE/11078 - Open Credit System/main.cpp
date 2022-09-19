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
        list<pair<int, int>> score(n, pinit);
        int i = 0;
        int s;
        for (auto &p: score) {
            cin >> s;
            // score.eb(make_pair(i, s));
            p.first += i; p.second += s;
            i++;
        }
        // while (n--) {
        //     int s;
        //     cin >> s;
        //     score.eb(make_pair(i, s));
        //     // score[i] = s;
        //     i++;
        // }
        n = score.size();
        score.sort(comp_score); // sort the score in ascending order
        auto r_score = score;
        reverse(r_score.begin(), r_score.end());
        int max = INT_MIN;
        for (auto a = score.begin(); a != score.end(); a++) {
            for (auto b = r_score.begin(); b != r_score.end(); b++) {
                if ((*a).first != (*b).first) {
                    if ((*a).first < (*b).first) {
                        if ((*a).second - (*b).second > max) max = (*a).second - (*b).second;
                    }
                }
            }
        }
        cout << max << endl;
    }
}