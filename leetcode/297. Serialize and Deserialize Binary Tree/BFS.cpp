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
        if (!root) return "";
        ostringstream oss; // ostringstream is just like cout, which use << to eat substrings left to right
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int numOfNodeThisLv = q.size();
            while (numOfNodeThisLv--) {
                auto curr = q.front();
                q.pop();
                if (!curr) {
                    oss << "N,";
                    continue;
                }
                oss << to_string(curr->val) << ",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return oss.str(); // note: str ends with ','
        // return substr(str.begin() + 1, str.size() - 1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return nullptr;
        istringstream iss(data); // istringstream is just like cin, use >> to spit out substring
        // note: << takes ',', '\t', '\n', and ' ', all of them, as delimeter
        // getline takes '\n' as delimeter defaultly, 
        string valStr;
        getline(iss, valStr, ','); // spit substring out to valStr with ',' as the delimeter
        TreeNode* root = new TreeNode(stoi(valStr));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            // get left child value
            getline(iss, valStr, ','); // spit substring out to valStr with ',' as the delimeter
            if (valStr != "N") {
                int leftVal = stoi(valStr);
                auto leftNode = new TreeNode(leftVal);
                q.push(leftNode);
                curr->left = leftNode;
            }

            // get right child value
            getline(iss, valStr, ','); // spit substring out to valStr with ',' as the delimeter
            if (valStr != "N") {
                int rightVal = stoi(valStr);
                auto rightNode = new TreeNode(rightVal);
                q.push(rightNode);
                curr->right = rightNode;
            }
        }
        return root;
    }
};


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string str = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int numOfNodeThisLv = q.size();
            while (numOfNodeThisLv--) {
                auto curr = q.front();
                q.pop();
                if (!curr) {
                    str+= "N,";
                    continue;
                }
                str += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return str; // note: str ends with ','
        // return substr(str.begin() + 1, str.size() - 1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return nullptr;
        string valStr = "";
        int i = 0;
        while (data[i] != ',') {
            valStr += data[i];
            i++;
        }
        i++; // move from "," to the first digit of next num
        TreeNode* root = new TreeNode(stoi(valStr));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            // get left child value
            valStr = "";
            while (data[i] != ',') {
                valStr += data[i];
                i++;
            }
            i++;
            if (valStr != "N") {
                int leftVal = stoi(valStr);
                auto leftNode = new TreeNode(leftVal);
                q.push(leftNode);
                curr->left = leftNode;
            }

            // get right child value
            valStr = "";
            while (data[i] != ',') {
                valStr += data[i];
                i++;
            }
            i++;
            if (valStr != "N") {
                int rightVal = stoi(valStr);
                auto rightNode = new TreeNode(rightVal);
                q.push(rightNode);
                curr->right = rightNode;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));