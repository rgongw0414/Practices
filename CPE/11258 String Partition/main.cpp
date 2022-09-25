#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define eb emplace_back
#define ef emplace_front
#define endl '\n'
using namespace std;

void solve() {
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    cin.ignore();
    while (N--) {
        string seq;
        getline(cin, seq);
        long long int DP[210] = {0}; // DP[i] represents the maximal sum for 0 ~ i-1
        for (int i = 0; i < seq.size(); ++i) {
            if (seq[i] == '0') {
                DP[i + 1] = max(DP[i + 1], DP[i]);
            } else {
                long long int sum = 0;
                for (int j = i; j < seq.size(); ++j) {
                    sum = sum * 10 + (seq[j] - '0'); // calculate the sum for range i~j
                    if (sum > INT_MAX)
                        break;                               // if sum of the range is larger than 32-bit signed integer, break
                    DP[j + 1] = max(DP[j + 1], DP[i] + sum); // or, update the sum: DP[j+1] = DP[j+1] or the larger one (DP[i] + sum)
                }
            }
        }
        // for (int i = 0; i <= seq.size(); ++i) cout << "DP[" << i << "]: " << DP[i] << endl;
        cout << DP[seq.size()] << endl; // the final answer is stored at position n ( the length of input )
    }

    return 0;
}