#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define eb emplace_back
#define ef emplace_front
#define endl '\n'
using namespace std;

vector<int> TIME(8784+1, 0);
struct node {
    int extension;
    vector<int> time=TIME;
};

map<int, node> m;

void solve(int time, int target) {
    printf("AT %04d CALL TO %04d ", time, target);
    int source = target;
    while (true) {
        if (!m[target].time[time]) break; // at "time" is free
        if (m[target].time[time] == source) {
            // forward = m[target].time[time]
            target = 9999;
            break;
        }
        else target = m[target].time[time];
    }
    printf("RINGS %04d\n", target);
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(NULL);
    
    int n, c = 1;
    cin >> n;
    cout << "CALL FORWARDING OUTPUT\n";
    while (n--) {
        cout << "SYSTEM " << c++ << endl;
        int source, time, duration, target;
        // source, target: 0001 ~ 9998
        // TIME: 0000 ~ 8784
        while (true) {
            cin >> source; if (source == 0) break;
            cin >> time >> duration >> target;
            if (m.count(source)) {
                // m[source].extension = source;
                for (int i = time; i <= time+duration; i++) m[source].time[i] = target;
            }
            else {
                node newNode;
                newNode.extension = source;
                for (int i = time; i <= time+duration; i++) newNode.time[i] = target;
                m[source] = newNode;
            }

            if (!m.count(target)) {
                node newNodeT;
                newNodeT.extension = target;
                m[target] = newNodeT;
            }
        }
        while (true) {
            cin >> time; if (time == 9000) break;
            cin >> target;
            solve(time, target);
        }
        for (auto& v: m) {
            v.second.time.clear();
        }
        m.clear();
    }
    cout << "END OF OUTPUT\n";
}