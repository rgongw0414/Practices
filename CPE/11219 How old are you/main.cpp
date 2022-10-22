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
    
    int c = 1;
    int t;
    cin >> t;
    while (t--) {
        cout << "Case #" << c << ": ";
        c++;
        string age, tmp, date1, date2;
        cin.ignore();
        getline(cin, tmp);
        cin >> date1 >> date2;
        int d1 = -1, m1 = -1, y1 = -1, d2 = -1, m2 = -1, y2 = -1;
        string n = "";
        for (auto &c: date1) {
            if (c != '/') n += c;
            else {
                if (d1 == -1) {
                    d1 = stoi(n);
                    n = "";
                }
                else if (m1 == -1) {
                    m1 = stoi(n);
                    n = "";
                }
            }
        }
        y1 = stoi(n);
        n = "";
        for (auto &c: date2) {
            if (c != '/') n += c;
            else {
                if (d2 == -1) {
                    d2 = stoi(n);
                    n = "";
                }
                else if (m2 == -1) {
                    m2 = stoi(n);
                    n = "";
                }
            }
        }
        y2 = stoi(n);
        
        if (y1 >= y2) {
            if (y1 == y2) {
                if (m1 >= m2) {
                    if (m1 == m2) {
                        if (d1 >= d2) {
                            age = "0";
                        }
                        else {
                            age = "Invalid birth date";
                        }
                    }
                    else {
                        age = "0";
                    }
                }
                else { // m1 < m2
                    age = "Invalid birth date";
                }
            }
            else { // y1 > y2
                if (m1 >= m2) {
                    if (m1 == m2) {
                        if (d1 >= d2) {
                            if ((y1-y2) > 130) age = "Check birth date";
                            else age = to_string(y1-y2);
                        }
                        else { // d1 < d2
                            if ((y1-y2-1) > 130) age = "Check birth date";
                            else age = to_string(y1-y2-1);
                        }
                    }
                    else { // m1 > m2
                        if ((y1-y2) > 130) age = "Check birth date";
                        else age = to_string(y1-y2);
                    }
                }
                else { // m1 < m2
                    if ((y1-y2-1) > 130) age = "Check birth date";
                    else age = to_string(y1-y2-1);
                }
            }
        }
        else { // y1 < y2
            age = "Invalid birth date";
        }
        cout << age << endl;
        date1.clear();
        date2.clear();
    }
}