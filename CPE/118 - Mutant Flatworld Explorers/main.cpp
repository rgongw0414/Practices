#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define eb emplace_back
using namespace std;

static int X, Y; // cord: (0, 0) ~ (X, Y)
static int x, y;
static char o;
static vector<vector<bool>> scent;

void solve() {
    bool lost = false;
    string insts;
    cin >> insts;
    for (auto& inst: insts) {
        if (lost) break;
        if (inst == 'R') {
            if (o == 'E') o = 'S';
            else if (o == 'W') o = 'N';
            else if (o == 'S') o = 'W';
            else if (o == 'N') o = 'E';
        }
        else if (inst == 'L') {
            if (o == 'E') o = 'N';
            else if (o == 'W') o = 'S';
            else if (o == 'S') o = 'E';
            else if (o == 'N') o = 'W';
        }
        else if (inst == 'F') {
            if (o == 'E') {
                if (x + 1 > X) {
                    if (!scent[x][y]) {
                        scent[x][y] = true;
                        lost = true;
                    }
                }
                else x++;  
            } 
            else if (o == 'W') {
                if (x - 1 < 0) {
                    if (!scent[x][y]) {
                        scent[x][y] = true;
                        lost = true;
                    }
                }
                else x--;  
            }
            else if (o == 'S') {
                if (y - 1 < 0) {
                    if (!scent[x][y]) {
                        scent[x][y] = true;
                        lost = true;
                    }
                }
                else y--;  
            }
            else if (o == 'N') {
                if (y + 1 > Y) {
                    if (!scent[x][y]) {
                        scent[x][y] = true;
                        lost = true;
                    }
                }
                else y++;  
            }
        }
    }
    cout << x << " " << y << " " << o;
    if (lost) cout << " LOST";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> X >> Y;
    scent.assign(X+1, vector<bool>(Y+1, false));
    while (cin >> x >> y >> o) {
        solve();
    }
}