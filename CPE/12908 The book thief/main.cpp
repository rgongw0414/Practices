#include <bits/stdc++.h>
#define ll int
#define em emplace_back
#define endl '\n'
using namespace std;

// void solve(ll &s){
//     int tmp = 0;
//     for (ll i = 1; i < INT_MAX; i++) {
//         tmp = i*(i+1)/2;
//         for (ll j = i; j > 0; j--) {
//             if (tmp - j == s) {
//                 cout << j << " " << i << endl;
//                 return;
//             }
//         }
//     }
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    // int input = 0;
    // vector<int> table;

    // for (int i = 0; i <= 20000; i++) {
    //     table.push_back((i * (i + 1)) / 2);
    // }
    // while (cin >> input && input) {
    //     vector<int>::iterator itTable = upper_bound(table.begin(), table.end(), input);
    //     cout << *itTable - input << " " << itTable - table.begin() << endl;
    // }

    // return 0;

    int num = 0; /* 題目給的頁數*/
 
    while(1){
        int sum = 0;
        int page = 0;
        scanf("%d", &num);
        if(num == 0) break;
        for(int i = 1; i <= num + 1, sum <= num; i++){
            sum += i;
            if(sum > num){
                page = sum - num;
                printf("%d %d\n",page,i);
            }
        }
    }

    //// *** too slow *** ////
    // ll s; // result sum, 1 <= s <= 1e8
    // while (cin >> s){
    //     if (s <= 0 || s > 1e8) break;
    //     else {
    //         solve(s);
    //     }
    // }
}