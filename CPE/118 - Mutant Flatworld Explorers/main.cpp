#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define eb emplace_back
using namespace std;

    /*
        E -L-> N 
        E -R-> S
        W -L-> S
        W -R-> N
        S -L-> E
        S -R-> W
        N -L-> W
        N -R-> E
    */
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int X, Y; // cord: (0, 0) ~ (X, Y)
    cin >> X >> Y;
    int x, y;
    char o;
    string insts;
    while (cin >> x >> y >> o) {
        cin >> insts;
        bool lost = false;
        for (auto& inst: insts) {
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
                // lost = false;
                if (o == 'E') {
                    x++;  
                    if (x > X) {
                        x--;
                        lost = true;
                    }
                } 
                else if (o == 'W') {
                    x--;
                    if (x < 0) {
                        x++;
                        lost = true;
                    }
                }
                else if (o == 'S') {
                    y--;
                    if (y < 0) {
                        y++;
                        lost = true;
                    }
                }
                else if (o == 'N') {
                    y++;
                    if (y > Y) {
                        y--;
                        lost = true;
                    }
                }
            }
        }
        cout << x << " " << y << " " << o;
        if (lost) cout << " LOST";
        cout << endl;
    }
}

/*
5 3
0 3 W
LL E
FFF 3 3 E
L 3 3 N
F 3 3 LOST 
L W
F 2 3
L 2 3 S

3 2 N
F 3 3 N
RR 3 3 S
F 3 2 S
LL 3 2 N
FF 3 3 N LOST
RR 3 3 S
F 3 2 S
LL 3 2 N
*/

/*
0, 3 ... 5, 3

0, 0 ... 5, 0
*/