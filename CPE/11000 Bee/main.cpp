#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll n, m = 0, t = 1;
    while (1){
        cin >> n;
        if (n == -1) break;
        else{
            int i = 0;
            while (i != n) {
                if (i == 0){
                    m = m + 1;
                    t = t + m;
                }
                else{
                    ll mm = m;
                    ll tt = t;
                    m = mm + tt - mm;
                    t = mm + tt + 1;
                }
                i++;
            }
            cout << m << " " << t << endl;
        }
        t = 1;
        m = 0;
    }
}