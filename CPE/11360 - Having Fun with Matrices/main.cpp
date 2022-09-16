#include <bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define endl '\n'
using namespace std;

int Case = 1;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int j = 0;
        for (auto& num: s) {
            mat[i][j++] = ((int)(num) - 48)%10;
        }
    }
    int operN = 0;
    cin >> operN;
    while (operN--) {  
        string temp;
        cin >> temp;
        if (temp == "row") {
            int a, b;
            cin >> a >> b;
            swap(mat[a-1], mat[b-1]);
        }
        else if (temp == "col") {
            int a, b;
            cin >> a >> b;
            for (int i = 0; i < n; i++) {
                int tmp = mat[i][a-1];
                mat[i][a-1] = mat[i][b-1];
                mat[i][b-1] = tmp;
            }
        }
        else if (temp == "inc") {
            for (auto &row: mat) {
                for (auto &elem row) {
                    elem = (elem+1) % 10;
                }
            }
        }
        else if (temp == "dec") {
            for (auto &row: mat) {
                for (auto &elem row) {
                    if (elem == 0) elem = 9;
                    else elem = elem - 1;
                }
            }
        }
        else if (temp == "transpose") {
            vector<vector<int>> mat2(mat);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    mat[i][j] = mat2[j][i];
                }
            }
        }
    }
    cout << "Case #" << Case << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j];
        }
        cout << endl;
    }
    cout << endl;
    Case++;
    mat.clear();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}