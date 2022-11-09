#include <bits/stdc++.h>
#define endl '\n'
#define eb emplace_back
using namespace std;

// return all minterms in the specific column
vector<int> getMinterms(vector<vector<int>> &mat, int j) {
    vector<int> mints;
    for (int i = 0; i < mat.size(); i++) {
        if (mat[i][j]) mints.eb(i);
    }
    return mints;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int x, y; // x: num of minterm; y: num of prime.
    cin >> x >> y;
    vector<vector<int>> mat(x, vector<int>(y, 0));
    vector<pair<int, int>> weights; // (no. of prime, weight of it)
    int tmp = y, n = 1;
    while (tmp--) {
        int w;
        cin >> w;
        weights.eb(make_pair(n++, w));
    }
    int X, Y;
    while (cin >> X >> Y) {
        mat[X-1][Y-1] = 1;
    }

    // delete the dominating minterms
    vector<int> mint_del;
    for (int i = 0; i < x; i++) {
        set<int> dominating;
        for (int j = 0; j < y; j++) if (mat[i][j]) dominating.insert(j);
        for (int ii = 0; ii < x; ii++) {
            if (ii == i) continue;
            bool dominated = true;
            for (int j = 0; j < y; j++) {
                if (mat[ii][j] && !dominating.count(j)) dominated = false;
            }
            if (dominated) { // mat[ii] is dominated by mat[i]
                mint_del.eb(i);
                break;
            }
        }
    }

    // delete the dominated primes
    vector<int> prime_del;
    for (int i = 0; i < y; i++) {
        set<int> dominated;
        for (int j = 0; j < x; j++) if (mat[j][i]) dominated.insert(j);
        int count = dominated.size();
        for (int ii = 0; ii < y; ii++) {
            if (ii == i) continue;
            int count2 = 0;
            for (int j = 0; j < x; j++) {
                if (mat[j][ii] && dominated.count(j)) count2++;
            }
            if (count2 >= count) { // mat[][ii] is dominating mat[][i]
                prime_del.eb(i);
                break;
            }
        }
    }

    // matrix2: the matrix being pruned
    vector<vector<int>> mat2;
    mat2.assign(mat.begin(), mat.end());

    tmp = 0;
    for (auto &del: mint_del) {
        mat2.erase(mat2.begin() + del - tmp++);
    }
    tmp = 0;
    for (auto &del: prime_del) {
        weights.erase(weights.begin() + del - tmp);
        for (auto &row: mat2) {
            row.erase(row.begin() + del - tmp);
        }
        tmp++;
    }

    int x2 = mat2.size();
    int y2 = mat2[0].size();
    set<int> mint;
    set<int> cover;
    for (int i = 0; i < x2; i++) {
        if (accumulate(mat2[i].begin(), mat2[i].end(), 0) == 1) {
            for (int j = 0; j < y2; j++) {
                if (mat2[i][j] == 1) {
                    cover.insert(j);
                    auto mints = getMinterms(mat2, j);
                    for (auto &m: mints) mint.insert(m);
                }
            }
        }
    }

    for (int j = 0; j < y2; j++) {
        if (mint.size() == x2) break;
        if (cover.count(j)) continue;
        auto mints = getMinterms(mat2, j);
        if (mints.size() == 0) continue;
        cover.insert(j);
        for (auto &m: mints) mint.insert(m);
    }

    // for (auto &m: mint) cout << m << " ";
    // cout << endl;
    // for (auto &c: cover) cout << c << " ";
    // cout << endl;
    
    int sum = 0;
    for (auto &c: cover) {
        cout << weights[c].first << "\t";
        sum += weights[c].second;
    }
    cout << endl;
    cout << "(" << cover.size() << ", " << sum << ")\n";

    // for (auto &w: weights) cout << "y" << w.first << "_w: " << w.second << endl;
    // for (auto &m: mint_del) cout << m << " ";
    // cout << endl;
    // for (auto &m: prime_del) cout << m << " ";
    // cout << endl;
    // for (auto &r: mat) {
    //     for (auto &e: r) {
    //         cout << e << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (auto &r: mat2) {
    //     for (auto &e: r) {
    //         cout << e << ' ';
    //     }
    //     cout << endl;
    // }
}