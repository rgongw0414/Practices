#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define endl '\n'
using namespace std;

int max1d(vector<int> &rec){
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cout << INT_MIN << endl;
    while (cin >> n) {
        if (n == 0) break;
        int max = INT_MIN;
        vector<vector<int>> rec(n, vector<int>(n, 0));
        for (auto& row: rec){
            for(auto& elem: row){
                cin >> elem;
            }
        }

        for (int i = 0; i < n; i++) {
            vector<int> sum(n, 0);
            for (int j = i; j < n; j++) {
                // cout << rec[i][j] << " ";
                for (int k = 0; k < n; k++){

                }
            }
            cout << endl;
        }
    }
}