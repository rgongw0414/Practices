#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll n, q;
    cin >> n;
    map<string, string> slogan;
    cin.ignore();
    while (n--){
        string first, second;
        getline(cin, first);
        getline(cin, second);
        slogan[first] = second;
    }
    
    cin >> q;
    cin.ignore();
    while (q--){
        string first;
        getline(cin, first);
        cout << slogan[first] << endl;
    }
}