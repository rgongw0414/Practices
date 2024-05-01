class Solution {
public:
    vector<vector<int> > subsets(vector<int> &nums) {
        // Considers each num as a bit, TC and SC: O(N * N!)
        sort(nums.begin(), nums.end());
        int subset_num = pow(2, nums.size());
        vector<vector<int> > subset_set(subset_num, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < subset_num; j++) {
                bitset<10> bits(j);  // note: bitset must initialized with const value, so set the length to 10 wrt the longest test case
                if (bits[i]) subset_set[j].push_back(nums[i]);
                
                // if ((j >> i) & 1)  {
                //     // check each bit with shifts
                //     subset_set[j].push_back (nums[i]);
                // }
            }
        }
        return subset_set;
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // (vector manner) decision tree with TC and SC of O(2^(N+1) - 1) = O(2^N) (excluding the result vector, otherwise SC: O(N * 2^N))
        // For each subset, the average length is approximately N/2, leading to a total space complexity of O(2^N * N) for storing all subsets.
        vector<vector<int>> powerSet;
        vector<int> subset;
        DFS(powerSet, subset, nums, 0);
        return powerSet;
    }

    void DFS(vector<vector<int>> &powerSet, vector<int> &subset, vector<int> &nums, size_t i) {
        if (i >= nums.size()) {
            powerSet.push_back(subset);
            return;
        }
        // choose current num
        subset.push_back(nums[i]);
        DFS(powerSet, subset, nums, i + 1);

        // skip this num, so pop it
        subset.pop_back();
        DFS(powerSet, subset, nums, i + 1);
    }
};

class Solution {
private:
    struct Node {
        Node* left;
        Node* right;
        bool pick = false; // left child: skip, right child: pick
        Node(): left(nullptr), right(nullptr), pick(false) {}
    };
    Node* root;

public:
    void buildDecisionTree(Node* curr, vector<int>& nums, int level) {
        if (level >= nums.size()) return;
        curr->left = new Node();
        buildDecisionTree(curr->left, nums, level + 1);
        curr->right = new Node();
        curr->right->pick = true;
        buildDecisionTree(curr->right, nums, level + 1);
    }

    void traverse(vector<int>& nums, vector<vector<int>> &powerSet, vector<int> &subset, Node* curr, int level) {
        if (level > 0) {
            if (curr->pick) subset.push_back(nums[level - 1]);
            else subset.pop_back();
        }
        if (level == nums.size()) {
            powerSet.push_back(subset);
            return;
        }
        traverse(nums, powerSet, subset, curr->right, level + 1);
        traverse(nums, powerSet, subset, curr->left, level + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        // actually build a decision tree with TC and SC of O(2^(N+1) - 1) = O(2^N)
        root = new Node();
        buildDecisionTree(root, nums, 0);
        vector<vector<int>> powerSet;
        vector<int> subset;
        traverse(nums, powerSet, subset, root, 0);
        return powerSet;
    }
};