class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // nth_element with TC: O(N), SC: O(1)
        // The element pointed at by nth is the element that would be in that position if [first, last) were sorted.
        /*
        template< class RandomIt >
        void nth_element( RandomIt first, RandomIt nth, RandomIt last );
        */
        auto m = nums.begin() + nums.size() / 2;
        nth_element(nums.begin(), m, nums.end());
        return nums[nums.size() / 2];
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Rearranges elements such that the range [first, middle) contains the sorted (middle − first) smallest elements in the range [first, last).
        //                first              middle                      last
        partial_sort(nums.begin(), nums.begin() + nums.size() / 2 + 1, nums.end());
        return nums[nums.size() / 2];
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> numCount;
        int ans;
        for (auto& num: nums) {
            numCount[num]++;
            if (numCount[num] > nums.size() / 2) {
                ans = num;
                break;
            }
        }
        return ans;
    }
};