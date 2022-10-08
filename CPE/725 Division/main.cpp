#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl '\n'
#define eb emplace_back
#define ef emplace_front
using namespace std;

set<int> nums;

void solve(int i) {
    set<int> digs;
    if (i < 10000) digs.insert(0);
    int j = i;
    while (j != 0) {
        if (digs.count(j % 10)) return;
        else digs.insert(j % 10);
        j /= 10;
    }
    nums.insert(i);
}
 
int check(set<int> &digs, int n) {
    if (n < 10000 && digs.count(0) == 0) digs.insert(0);
    while (n != 0) {
        if (digs.count(n % 10)) return 1;
        else digs.insert(n % 10);
        n /= 10;
    }
    return 0;
}

void solve2(int n) {
    int flag = 0, c = -1;
    for (auto& num: nums) {
        if (num * n > 98765) {
            if (flag == 1 && c == 0) return;
        }
        if (nums.count(num*n)) {
            set<int> digs;
            c = check(digs, num);
            c = check(digs, num*n);
            if (c == 0) {
                flag = 1;
                if (n < 10000 && num*n < 10000) continue;
                cout << setw(5) << setfill('0') << num*n << " / ";
                cout << setw(5) << setfill('0') << num << " = " << n << endl;
            }
        }
    }
    if(flag == 0) cout << "There are no solutions for " << n << ".\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    for (int i = 1234; i <= 98765; i++) {
        solve(i);
    }
    // for (auto &n: nums) cout << n << endl;

    int n;
    bool start = false;
    while (cin >> n) { // 2 <= n <= 79
        if (n == 0) break;
        if (start) cout << endl;
        start = true;
        solve2(n);
        // 01234 ~ 98765
        // n1 / n2 = n, find all (n1, n2) pairs.
    }
}