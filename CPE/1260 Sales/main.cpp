#include <bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define endl '\n'
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int as;
        cin >> as;
        vector<int> a(as, 0);
        for (auto& i: a) {
            int A;
            cin >> A;
            i += A;
        }
        int sum = 0;
        for (int i = 0; i < as; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (a[j] <= a[i]) sum++;
            }
        }
        cout << sum << endl;
    }
}