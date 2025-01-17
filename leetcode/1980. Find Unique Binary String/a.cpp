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