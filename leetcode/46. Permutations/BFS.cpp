class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // Iterative BFS method, 
        /* idea: in each level, enumerate all permutations of vectors which with length current level as the vector length 
        * To enumerate all permutations, once stepping into next level, push a num which is not in current permutation.
        * level-1: each num of nums, e.g. queue: [[1], [2], [3]]
        * level-2: for each num, push a number not in currrent permutaion into currPerm, and push currPerm to queue,
        *          pop front ([1]), now queue: [[2], [3], [1,2], [1,3]], then: [[3], [1,2], [1,3], [2,1], [2,3]], ...
        */
        vector<vector<int>> ans;
        queue<vector<int>> q;
        for (auto &num: nums) {
            // first level: each number
            q.push(vector<int>({num}));
        }
        int permLen = nums.size(); // length of a permutation
        while (!q.empty()) {
            // Total nodes in the tree: N + N*(N-1) + N*(N-1)*(N-2) + ... + N! = O(N!), because N! is the dominant term
            // overall TC: O(N! * N^2)
            int currQueueSize = q.size();
            while (currQueueSize--) {
                vector<int> currPerm = q.front();
                q.pop();

                if (currPerm.size() == permLen) {
                    ans.push_back(currPerm);
                    continue;
                }

                for (auto &num: nums) {
                    // this loop: O(N^2), resulted from std::find
                    // maybe can be optimized
                    auto iter = find(currPerm.begin(), currPerm.end(), num);
                    if (iter == currPerm.end()) {
                        // num is not in currPerm
                        currPerm.push_back(num);
                        q.push(currPerm);
                        currPerm.pop_back();
                    }
                }
            }
        }
        return ans;
    }
};