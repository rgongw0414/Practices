#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl '\n'
#define eb emplace_back
#define ef emplace_front
using namespace std;

// bool solve(string &a, string &b) {
//     for (int i = 0; i <= 25; i++) {
//         string tmp = b;
//         for (auto& c: tmp) {
//             c = 'A' + (c + i + 13) % 26;
//         }
//         sort(tmp.begin(), tmp.end());
//         do {
//             if (tmp == a) {
//                 return true;
//             }
//         } while (next_permutation(tmp.begin(), tmp.end()));
//     }
//     return false;
// }

bool solve2(string &a, string &b) {
    vector<int> A(26, 0);
    vector<int> B(26, 0);
    for (int i = 0; i < a.size(); i++) {
        A[a[i]-'A']++;
        B[b[i]-'A']++;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for (int i = 0; i < 26; i++) {
        if (A[i] != B[i]) return false;
    }
    return true;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    string a, b;
    while (cin >> a >> b) {
        // bool yes = solve(a, b);
        bool yes = solve2(a, b);
        if (yes) cout << "YES\n";
        else cout << "NO\n";
        a.clear();
        b.clear();
    }
}