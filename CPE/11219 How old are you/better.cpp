#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define eb emplace_back
#define ef emplace_front
#define endl '\n'
using namespace std;

int str2int(string &str, int index1, int index2) {
    int n = 0;
    for (int i = index1; i <= index2; i++) {
        n *= 10;
        n += str[i] - '0';
    }
    return n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    int cnt = 1;
    while (t--) {
        cout << "Case #" << cnt++ << ": ";
        string date1, date2;
        cin >> date1 >> date2;
        int d1 = 0, d2 = 0;
        // say 31 day/month, 400 day/year
        // date format: dd/mm/yyyy
        d1 += str2int(date1, 0, 1) + str2int(date1, 3, 4)*31 + str2int(date1, 6, 9)*400;
        d2 += str2int(date2, 0, 1) + str2int(date2, 3, 4)*31 + str2int(date2, 6, 9)*400;

        string ans;
        if (d1 < d2) ans = "Invalid birth date";
        else if ((d1-d2)/400 > 130) ans = "Check birth date";
        else ans = to_string((d1-d2)/400);
        cout << ans << endl;
    }
}