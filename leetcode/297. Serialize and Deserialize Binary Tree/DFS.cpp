/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // cleaner code using stringstream
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss; // note: oss only supports write operations
        // note that stringstream ss also works, and supports read/write opreations
        DFS_Encode(root, oss);
        return oss.str(); // note: str ends with ','
        // return substr(str.begin() + 1, str.size() - 1);
    }
    void DFS_Encode(TreeNode* curr, ostringstream &oss) {
        if (!curr) {
            oss << "N,";
            return;
        }
        oss << to_string(curr->val) << ",";
        DFS_Encode(curr->left, oss);
        DFS_Encode(curr->right, oss);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data); // iss only supports read operations
        // stringstream ss(data); // also works
        return DFS_Decode(data, iss);
    }
    TreeNode* DFS_Decode(string &data, istringstream &iss) {
        string valStr;
        getline(iss, valStr, ',');
        if (valStr == "N") {
            // all leaf nodes end with nullptr, so no need to worry about out-of-bound error
            return nullptr;
        }
        int val = stoi(valStr);
        TreeNode* curr = new TreeNode(val);
        curr->left = DFS_Decode(data, iss);
        curr->right = DFS_Decode(data, iss);
        return curr;
    }
};


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // recursive DFS (preorder), TC & SC: O(N)
        string str = "";
        DFS_Encode(root, str);
        return str; // note: str ends with ','
        // return substr(str.begin() + 1, str.size() - 1);
    }
    void DFS_Encode(TreeNode* curr, string &str) {
        if (!curr) {
            str += "N,";
            return;
        }
        str += to_string(curr->val) + ",";
        DFS_Encode(curr->left, str);
        DFS_Encode(curr->right, str);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int currIdx = 0;
        return DFS_Decode(data, currIdx);
    }
    TreeNode* DFS_Decode(string &data, int &currIdx) {
        string valStr = "";
        while (data[currIdx] != ',') {
            valStr += data[currIdx];
            currIdx++;
        }
        currIdx++; // now idx points to ',', move idx to next integer
        if (valStr == "N") {
            // all leaf nodes end with nullptr, so no need to worry about out-of-bound error
            return nullptr;
        }
        int val = stoi(valStr);
        TreeNode* curr = new TreeNode(val);
        curr->left = DFS_Decode(data, currIdx);
        curr->right = DFS_Decode(data, currIdx);
        return curr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));