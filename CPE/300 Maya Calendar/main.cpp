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
    
    map<string, int> Haab{
        {"pop", 0},  {"no", 1},     {"zip", 2},    {"zotz", 3},    {"tzec", 4},
        {"xul", 5},  {"yoxkin", 6}, {"mol", 7},    {"chen", 8},    {"yax", 9},
        {"zac", 10}, {"ceh", 11},   {"mac", 12},   {"kankin", 13}, {"muan", 14},
        {"pax", 15}, {"koyab", 16}, {"cumhu", 17}, {"uayet", 18}};
    vector<string> t_name{"imix",  "ik",    "akbal", "kan",   "chicchan",
                                "cimi",  "manik", "lamat", "muluk", "ok",
                                "chuen", "eb",    "ben",   "ix",    "mem",
                                "cib",   "caban", "eznab", "canac", "ahau"};
    int t;
    cin >> t;
    cout << t << endl;
    string day, month;
    int d, m, y;
    while (t--) {
        cin >> day >> month >> y;
        day.pop_back();
        d = stoi(day);
        m = Haab[month];

        int sum = 0;
        sum += d + m*20 + y*365;
        cout << sum%13+1 << " " << t_name[sum%20] << " " << sum/(13*20) << endl;
    }
}