#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define endl '\n'
using namespace std;

int max1d(vector<int> &rec){
    int maxSum = INT_MIN, sum = 0;
    for (int i = 0; i < rec.size(); i++){
        if (sum >= 0) {
            sum = sum + rec[i];
        }
        else {
            sum = 0;
        }
        if (sum > maxSum) maxSum = sum;
    }
    return maxSum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    while (cin >> n) {
        if (n == 0) break;
        int maxSum = INT_MIN;
        vector<vector<int>> rec(n, vector<int>(n, 0));
        for (auto& row: rec){
            for(auto& elem: row){
                cin >> elem;
            }
        }

        for (int i = 0; i < n; i++) {
            vector<int> sum(n, 0);
            for (int j = i; j < n; j++) {
                for (int k = 0; k < n; k++){
                    sum[k] = sum[k] + rec[j][k];
                }
                maxSum = max(maxSum, max1d(sum));
            }
        }
        cout << maxSum << endl;
    }
}