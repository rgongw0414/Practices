#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define endl '\n'
using namespace std;
//test
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll n, m;
    vector<int> rec, indices;
    while (cin >> n){
        if (n == 0) break;
        int e;
        rec.reserve(n*n);
        indices.reserve(n*n);
        while (m--) {
            cin >> e;
            rec.pb(e);
        }

        ll sum = 0, max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (sum + rec[i*n + j] > sum){
                    sum = sum + rec[i*n + j];

                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << rec[i*n + j] << " ";
            }
            cout << endl;
        }

        // int rst = 0;
        // for (auto &i: rec){
        //     if (rst == n) {
        //         cout << endl;
        //         rst = 0;
        //     }
        //     cout << i << " ";
        //     rst++;
        // }
        cout << endl;
        rec.clear();
    }
}