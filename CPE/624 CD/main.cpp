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
    
    int n, t;
    while (cin >> n) {
        cin >> t;
        vector<int> duration; duration.reserve(t);
        int tmp = t;
        while (t--) {
            int d;
            cin >> d;
            duration.eb(d);
        }
        t = tmp;
        vector<int> c(n+1, 0);
        vector<vector<bool>> bag(t, vector<bool>(n+1, false));
        for (int i = 0; i < t; i++) {
            for (int j = n; j - duration[i] >= 0; j--) {
                if (c[j-duration[i]] + duration[i] > c[j]) {
                    c[j] = c[j-duration[i]] + duration[i];
                    bag[i][j] = true;
                }
            }
        }

        int sum = 0;
        for (int i = t-1, j = n; i >= 0; i--) {
            if (bag[i][j]) {
                cout << duration[i] << " ";
                sum += duration[i];
                j -= duration[i];
            }
        }
        cout << "sum:" << sum << endl;
    }
}