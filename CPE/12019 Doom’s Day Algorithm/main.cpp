#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define eb emplace_back
#define ef emplace_front
#define endl '\n'
using namespace std;

void solve() {
    int m, d;
    cin >> m >> d;
    string day;
    map<int, string> M;
    if (m == 1 || m == 10) {
        M[3] = "Monday";
        M[4] = "Tuesday";
        M[5] = "Wednesday";
        M[6] = "Thursday";
        M[0] = "Friday";
        M[1] = "Saturday";
        M[2] = "Sunday";
    }
    else if (m == 2 || m == 3 || m == 11) {
        M[0] = "Monday";
        M[1] = "Tuesday";
        M[2] = "Wednesday";
        M[3] = "Thursday";
        M[4] = "Friday";
        M[5] = "Saturday";
        M[6] = "Sunday";
    }
    else if (m == 4 || m == 7) {
        M[4] = "Monday";
        M[5] = "Tuesday";
        M[6] = "Wednesday";
        M[0] = "Thursday";
        M[1] = "Friday";
        M[2] = "Saturday";
        M[3] = "Sunday";
    }
    else if (m == 5) {
        M[2] = "Monday";
        M[3] = "Tuesday";
        M[4] = "Wednesday";
        M[5] = "Thursday";
        M[6] = "Friday";
        M[0] = "Saturday";
        M[1] = "Sunday";
    }
    else if (m == 6) {
        M[6] = "Monday";
        M[0] = "Tuesday";
        M[1] = "Wednesday";
        M[2] = "Thursday";
        M[3] = "Friday";
        M[4] = "Saturday";
        M[5] = "Sunday";
    }
    else if (m == 8) {
        M[1] = "Monday";
        M[2] = "Tuesday";
        M[3] = "Wednesday";
        M[4] = "Thursday";
        M[5] = "Friday";
        M[6] = "Saturday";
        M[0] = "Sunday";
    }
    else if (m == 9 || m == 12) {
        M[5] = "Monday";
        M[6] = "Tuesday";
        M[0] = "Wednesday";
        M[1] = "Thursday";
        M[2] = "Friday";
        M[3] = "Saturday";
        M[4] = "Sunday";
    }
    else if (m == 10) {
        M[3] = "Monday";
        M[4] = "Tuesday";
        M[5] = "Wednesday";
        M[6] = "Thursday";
        M[0] = "Friday";
        M[1] = "Saturday";
        M[2] = "Sunday";
    }
    cout << M[d%7] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    /*
    1/10 3
    2/21 0
    4/4  4
    5/9  2
    6/6  6
    7/11 4
    8/8  1
    9/5  5
    10/10 3
    11/7  0
    12/12 5
    */
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}