#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define eb emplace_back
#define ef emplace_front
#define endl '\n'
using namespace std;

void solve() {
    int m, n;
    cin >> m >> n;
    vector<string> dnas;
    dnas.reserve(m);
    while (m--) {
        string dna;
        cin >> dna;
        dnas.eb(dna);
    }

    vector<string> pats;
    pats.reserve(pow(4, n));
    string pat;
    pat.reserve(n);
    for (int a = 0; a <= n; a++) {
        for (int t = 0; t <= n-a; t++) {
            for (int g = 0; g <= n-a-t; g++) {
                for (int c = 0; c <= n-a-t-g; c++) {
                    if (a+t+g+c == n) {
                        pat = "";
                        int aa = a, tt = t, gg = g, cc = c;
                        while (aa--) pat += "A";
                        while (cc--) pat += "C";
                        while (gg--) pat += "G";
                        while (tt--) pat += "T";
                        pats.eb(pat);
                    }
                }
            }
        }
    }

    int min = INT_MAX;
    map<int, vector<string>> ans;
    for (auto &PAT: pats) {
        string pat = PAT;
        do {
            int error = 0;
            for (auto &dna: dnas) {
                for (int i = 0; i < n; i++) {
                    if (pat[i] != dna[i]) error++;
                }
            }
            if (error < min) {
                min = error;
                ans[min].eb(pat);
            }
        } while (next_permutation(pat.begin(), pat.end()));
    }
    auto tmp = ans[min];
    sort(tmp.begin(), tmp.end());
    for (auto &s: tmp)
        cout << s << endl;
    cout << min << endl;
}

void solve2() {
    int m, n, err;
    int a[4][1001], temp;
    string s, s1 = {'A', 'C', 'G', 'T'};

    scanf("%d %d", &m, &n);
    getchar();
    memset(a, 0, sizeof(a));
    for (int i = 0; i<m; i++) {
        cin >> s;
        for (int j = 0; j<n; j++) {
            for (int k = 0; k<4; k++) {
                if (s[j] == s1[k]) {
                    a[k][j]++;
                    break;
                }
            }
        }
    }
    err = 0;
    for (int i = 0; i<n; i++) {
        temp = max(max(max(a[0][i], a[1][i]), a[2][i]), a[3][i]);
        err+= (m-temp);
        for (int j = 0; j<4; j++) {
            if (temp == a[j][i]) {
                cout << s1[j];
                break;
            }
        }
    }
    printf("\n%d\n", err);
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        // solve();
        solve2();
    }
}