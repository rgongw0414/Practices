class Solution {
public:
    // Approach using priority queue
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // max heap, TC: O(n*logk), SC: O(n)
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        vector<int> res;
        
        // Iterate through the first window and insert elements into the priority queue
        for(int i = 0; i < k; i++)
            pq.push(make_pair(nums[i], i));
        
        // Sliding the window and finding maximum element using priority queue
        int i = 0, j = k;
        while(j <= n) {
            // Remove elements out of the current window's range
            while(pq.top().second < i)
                pq.pop();
            // Append maximum element of current window to result vector
            res.push_back(pq.top().first);
            // If there are more elements in nums, insert them into the priority queue
            if(j < n)
                pq.push(make_pair(nums[j], j));
            // Move the window forward
            i++;
            j++;
        }
        
        return res;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // doubly-ended queue, TC & SC: O(n)
        int numsLen = nums.size();
        vector<int> ans;
        deque<int> q; // double-ended-queue
        int l = 0; // pointers for current window
        for (int r = 0; r < numsLen; r++) {
            // just for memo: when q is empty, if called q.back() here, would cause "runtime error: reference binding to misaligned address"
            while (!q.empty() and nums[q.back()] < nums[r]) {
                // nums[r]: new num being added to current window
                // pop_back the num smaller than new num in current window (nums[l...r-1]), 
                // so the max num in current window (and prev window) will be at the front (and next to front) of q.
                q.pop_back();
            }
            q.push_back(r);
            if (r+1 >= k) { // current q is more than k nums, i.e. bigger than the demanding window size
                if (q.front() < l) {
                    // remove the idx from last iter's window
                    q.pop_front();
                }
                // once r+1 >= k, we can know the max num in the window of each iter 
                int maxNumInCurrWindow = nums[q.front()];
                ans.push_back(maxNumInCurrWindow);
                l++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // brute-force, TC: O(n*k)
        int winsowNum = nums.size() - k + 1;
        int windowMax = INT_MIN;
        vector<int> ans;
        for (int i = 0; i <= nums.size() - k; i++) {
            for (int j = 0; j < k; j++) {
                if (nums[i+j] > windowMax) windowMax = nums[i+j];
            }
            ans.push_back(windowMax);
            windowMax = INT_MIN;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // O(k*logk*(n-k+1)) = O(k*logk*n)
        vector<int> ans;
        int n = nums.size();
        ans.reserve(n-k+1);
    
        // Iterate through nums in steps of k
        for (int i = 0; i <= n - k; i++) {
            // Create a window of size k
            vector<int> window(nums.begin() + i, nums.begin() + i + k);
            
            // Sort the window
            sort(window.begin(), window.end());
            
            ans.emplace_back(window.back());
        }
        return ans;
    }
};