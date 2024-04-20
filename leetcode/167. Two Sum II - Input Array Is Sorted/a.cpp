class Solution {
public:
    int binary_search(int i, int left, int right, vector<int>& nums, int n) {
        int ret = -1;       // 未搜索到数据返回-1下标    
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2; //直接平均可能會溢位，所以用此算法
            if (nums[mid] < n)
                left = mid + 1;
            else if (nums[mid] > n)
                right = mid - 1;
            else {            // 最後檢測相等是因為多數搜尋狀況不是大於要不就小於
                if (i == mid) {
                    if (nums[mid] == nums[mid+1])
                        ret = mid+1;
                    else
                        ret = -1;
                }
                else {
                    ret = mid;
                }
                break;
            }
        }
        return ret;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int left = 0, right = numbers.size()-1;
        for (int i = 0; i < numbers.size(); i++) {
            int idx = binary_search(i, left, right, numbers, target-numbers[i]);
            if (idx != -1) {
                ans[0] = i+1;
                ans[1] = idx+1;
                break;
            }
        }
        return ans;
    }
};

class Solution {
public:
/*
The solution itself is quite intuitive, the nontrivial part of this question is explaining why it always works (which I'm pretty sure the interviewer will ask).
*** 反證法 ***
More specifically, at each step we only consider moving the lower pointer up or the upper pointer down (in order to increase or decrease the sum resp), why do we not need to consider moving both pointers up or down at the same time (which might change the sum)?
Proof: Suppose exists a sorted array of n such that exists 2 indexes a,b that give the required sum, WLOG a<b, but somehow after running the algorithm we do not get any solution. 
Now consider that at each step we only move the upper pointer down 1 index, or lower pointer up 1 index. Which means at some point before the alogrithm terminates, one of the pointers must be at a or b. Since we only moved the pointer by 1 each time it is either the lower pointer at a or upper pointer at b. 
If the lower pointer at a, then the upper pointer must be larger than b since it is the first time either pointer hits {a,b}. Then sorted array implies that the current sum must be larger than required sum, so we will keep moving the upper pointer down by 1 until it eventually hits b.
Vice versa if upper pointer at b.*/
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int i = 0, j = numbers.size()-1;
        while (true) {            
            if (numbers[i] + numbers[j] == target) {
                break;
            }
            else if (numbers[i] + numbers[j] < target) i++;
            else j--;
        }
        ans[0] = i+1;
        ans[1] = j+1;
        return ans;
    }
};