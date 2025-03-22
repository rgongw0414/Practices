class Solution {
public:
    string simplifyPath(string path) {
        // TC: O(n), SC: O(n)
        vector<string> stack;
        string cur;
        for (char c : path + "/") {
            // + "/" is for reading the last dir from some cases that don't end with '/'
            if (c == '/') {
                if (cur == "..") {
                    if (!stack.empty()) stack.pop_back();
                } 
                else if (!cur.empty() && cur != ".") { // !cur.empty() filters extra '/'s
                    stack.push_back(cur);
                }
                cur.clear();
            } 
            else {
                cur += c;
            }
        }

        string result = "/";
        for (int i = 0; i < stack.size(); ++i) {
            if (i > 0) result += "/";
            result += stack[i];
        }
        return result;
    }
};