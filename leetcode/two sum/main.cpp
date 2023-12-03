#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define eb emplace_back
#define ef emplace_front
using namespace std;

void solve() {
    
}

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    ans.reserve(2);
    int x = 0;
    int a, b;
    // if nums[a] + nums[b] == target
    // ans.pb(a); ans.pb(b);
    for (int i = 0; i < nums.size(); i++) {            
        for (int j = i+1; j < nums.size(); j++) {
            a = i;
            x += nums[i];
            b = j;
            x += nums[j];                
            cout << i << j << x;
            if (x == target) {
                cout << "test";
                ans.push_back(a);
                ans.push_back(b);
                goto ttt;
            }
            x = 0;
        }            
    }
    ttt: return (ans);
}

vector<int> twoSum_hash(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        if (numMap.count(complement)) {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }

    return {}; // No solution found
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    vector<string> strs = {"abcd", "abcdefg", "abcccccd"};
    string prefix = strs[1];
    cout << prefix.substr(0, 0) << endl;
    for (string s : strs) {
        cout << s.find("") << endl;
        break;
        while (s.find(prefix) != 0)
            prefix = prefix.substr(0, prefix.length() - 1);

    }
}

