class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> table;
        for (auto const &n: nums) {            
            table[n]++;
            if(table[n] == 2) return true;
            // if (table[n] == 0) {
            //     table[n] = 0;
            // }
            // else table[n]++;
        }
        return false;
    }
};