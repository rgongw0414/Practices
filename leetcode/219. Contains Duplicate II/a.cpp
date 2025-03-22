class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Optimized TC:O(n), SC:O(n)
        unordered_map<int, int> idx_map; // map each num to its latest idx
        int i = 0;
        while (i < nums.size()) {
            // i - idx_map[nums[i]] == abs(i - idx_map[nums[i]]), because i > idx_map[nums[i]]
            if (idx_map.count(nums[i]) && i - idx_map[nums[i]] <= k) {
                return true;
            }
            idx_map[nums[i]] = i;
            i++;
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // TC:O(n), SC:O(n)
        unordered_map<int, vector<int>> idx_map; // map each num to its vector of idx
        for (int i = 0; i < nums.size(); i++) {
            idx_map[nums[i]].push_back(i);
        }
        auto iter = idx_map.begin();
        while (iter != idx_map.end()) {
            auto vec = iter->second; 
            int l = 0, r = 1;
            while (r < vec.size()) {
                if (abs(vec[l] - vec[r]) <= k) {
                    return true;
                }
                else { // abs(vec[l] - vec[r]) > k
                    l = r;
                    r = l + 1;
                }
            }
            iter++;
        }
        return false;
    }
};
/*
nums = [1,0,1,1], k = 1
                    l r
-> idx_map[1] = {0,2,3}  -> abs(l-r) = 2 > k = 1
                    l r
-> idx_map[1] = {0,2,3}  -> abs(l-r) = 1 <= k = 1
*/