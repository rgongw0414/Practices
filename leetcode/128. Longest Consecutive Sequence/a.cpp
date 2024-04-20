class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        priority_queue<int> heap;
        for (auto const& n: nums) {
            heap.emplace(n);
        }
        int cnt = 1;
        int max = cnt;
        int top = heap.top();
        heap.pop();
        while (true) {
            if (heap.empty()) break;
            if (heap.top() != top-1) {
                if (heap.top() == top) {
                    cnt = cnt;
                }
                else cnt = 1;
            }            
            else {
                cnt++;
                if (cnt > max) max = cnt;
            }
            top = heap.top();
            heap.pop();
        }
        return max;
    }
};


class Solution {
public:
/*

    Time Complexity : O(N), Although the time complexity appears to be quadratic due to the while loop nested
    within the for loop, closer inspection reveals it to be linear. Because the while loop is reached only when
    marks the beginning of a sequence (i.e. currentNumber-1 is not present in nums), the while loop can only run
    for N iterations throughout the entire runtime of the algorithm. This means that despite looking like O(N^2)
    complexity, the nested loops actually run in O(N+N)=O(N) time. All other computations occur in constant
    time, so the overall runtime is linear. Where N is the size of the Array(nums).

    Space Complexity : O(N), Unordered set space.

    Solved using Array + Hash Table(Unordered set). Optimise Approach.

*/
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> set(nums.begin(), nums.end());
        int max_len = 1;
        for (auto const& n: set) {
            if (set.count(n-1) == 1) continue; // n is not the first element in a consecutive nums 
            else {
                int len = 1;
                int next = n+1;
                while (set.count(next) != 0) {
                    // each element at most being searched for "two times"! so the time complexity is O(n*2) = O(n)
                    len++;
                    next++;
                }
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};