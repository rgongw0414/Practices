/*
        j i ->   dp[1] = 2
nums = [2,5,3,7]
        j   i    dp[2] = max(dp[2], dp[0] + 1) = 2
            j i  dp[3] = 2
nums = [2,5,3,7]
        j     i
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 1-d dp, TC = O(n^2), SC = O(n)
        int n = nums.size();
        vector<int> dp(n, 1); // dp[i]: The len of the LIS ends at i
        for (int i = 0 ; i < n; i++) {
            for (int j = i - 1 ; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1); // dp[j] + 1: New subseq by concatenating the subseq dp[j] with nums[i]
                }
            }
        }
        return (int)*max_element(dp.begin(), dp.end());
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // DFS to enumerate all subsequence, where each seq consists of num chosen from nums
        // num is either chosen or not chosen, hence, TC = O(2^n)
        int max_len = 0;
        vector<int> sub_seq;
        sub_seq.reserve(nums.size());
        DFS(nums, 0, max_len, sub_seq);
        return max_len;
    }

    void DFS(vector<int> &nums, int added_idx, int &max_len, vector<int> &sub_seq) {
        // added_idx: current chosen num, i.e. now nums[added_idx] is chosen in sub-seq
        if (isIncreasing(sub_seq)){
            max_len = max(max_len, (int)sub_seq.size());
        }
        if (added_idx >= nums.size()) return;

        // sub_seq.emplace_back(nums[added_idx]);  // consider nums[i] in our sub-seq so far
        // DFS(nums, added_idx + 1, max_len, sub_seq);

        // sub_seq.pop_back();  // remove nums[i] from sub-seq
        // DFS(nums, added_idx + 1, max_len, sub_seq);

        for (int i = added_idx; i < (int)nums.size(); i++) {
            sub_seq.emplace_back(nums[i]);  // consider nums[i] in our sub-seq so far
            DFS(nums, i + 1, max_len, sub_seq);
            sub_seq.pop_back();  // remove nums[i] from sub-seq
        }
    }

    bool isIncreasing(vector<int>& sequence) {
        for (int i = 1; i < sequence.size(); ++i) {
            if (sequence[i] <= sequence[i - 1]) {
                return false;
            }
        }
        return true;
    }
};