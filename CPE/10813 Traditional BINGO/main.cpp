#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define eb emplace_back
#define ef emplace_front
#define endl '\n'
using namespace std;

bool mat[5][5] = {false};

bool check(int first, int second) {
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        if (mat[4-i][i]) cnt++;
    }
    if (cnt == 5) return true;

    cnt = 0;
    for (int i = 0; i < 5; i++) {
        if (mat[i][i]) cnt++;
    }
    if (cnt == 5) return true;

    cnt = 0;
    for (int i = 0; i < 5; i++) {
        if (mat[first][i]) cnt++;
    }
    if (cnt == 5) return true;

    cnt = 0;
    for (int i = 0; i < 5; i++) {
        if (mat[i][second]) cnt++;
    }
    if (cnt == 5) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int g;
    cin >> g;
    while (g--) {
        mat[2][2] = true;
        map<int, pair<int, int>> dict;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == j && j == 2) continue;
                int tmp;
                cin >> tmp;
                dict[tmp] = make_pair(i, j);
            }
        }
        int tmp = 75;
        bool win = false;
        int cnt = 0;
        while (tmp--) {
            int n;
            cin >> n;
            if (win) continue;
            pair<int, int> coor;
            if (dict.find(n) != dict.end()) {
                coor = dict[n];
                mat[coor.first][coor.second] = true;
                win = check(coor.first, coor.second);
            }
            cnt++;
        }
        cout << "BINGO after " << cnt << " numbers announced\n";
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                mat[i][j] = 0;
            }
        }
        mat[2][2] = 1;
    }
}