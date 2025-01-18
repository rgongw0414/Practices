class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        /*
        TC: O(N)
        SC: O(N)
        logic: if n = 2, and we take nums = ["00","01"], set str to "00", and keep changing one element from str at a time.
        1."00"-> 2."1O" -> 3."11" we generated 3 elements (n = 2) so atleast one element will be unique!!

        ***  Only works when nums.size() == n ***

        */
        unordered_set<string> str_set(nums.begin(), nums.end());
        const int n = nums.size();
        string str(n, '0');
        for (int i = 0; i < n; i++) {
            if (str_set.find(str) == str_set.end()) {
                return str;
            }
            str[i] = '1';
        }
        return str;
    }
};

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // Backtracking: TC: O(2^n), SC: O(2^n)
        unordered_set<string> str_set(nums.begin(), nums.end());
        const int n = nums.size();
        string str;
        str.reserve(n);
        string ans;
        ans.reserve(n);
        dfs(str, ans, str_set);
        return ans;
    }

    void dfs(string &str, string &ans, unordered_set<string> &str_set) {
        if (str.size() == str_set.size()) {
            if (str_set.find(str) == str_set.end()) ans = str;
            return;
        }
        if (!ans.empty()) return; // stop the recursion if we found the answer
        str.push_back('0');
        dfs(str, ans, str_set);
        str.pop_back();
        if (!ans.empty()) return; // stop the recursion if we found the answer
        str.push_back('1');
        dfs(str, ans, str_set);
        str.pop_back();
    }
};

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> num_set;
        const int n = nums[0].size();
        for (auto &num: nums) {
            // TC: O(n*(2^n))
            num_set.insert(bitset<16>(num).to_ulong());
        }
        for (int i = 0; i < 2<<n; i++) {
            // O(2^n)
            if (num_set.count(i) == 0) {
                return bitset<16>(i).to_string().substr(16 - n);
            }
        }
        return "";
    }
};