class Solution {
public:    
    void solve(vector<string>& ans, string& s, int open, int close, int n) {
        // backtracking; todo: dp

        // open/close: num of open/close parentheses
        if (open == n and close == n) {
            ans.emplace_back(s);
            return;
        }        
        string s_tmp_o = s+"(";
        if (open < n) {            
            solve(ans, s_tmp_o, open+1, close, n);
        }
        string s_tmp_c = s+")";
        if (close < open) {
            solve(ans, s_tmp_c, open, close+1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        // time: , space: 
        vector<string> ans;        
        string s = "";
        solve(ans, s, 0, 0, n);
        return ans;
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        int tmp = n;
        while (tmp--) {
            s += "(";
        }
        tmp = n;
        while (tmp--) {
            s += ")";
        }
        vector<string> ans;
        int cnt = 0;
        do {
            stack<int> stk;
            bool valid = true;
            for (auto const& c: s) {
                if (c == ')') {
                    if (stk.empty() or stk.top() != '(') {
                        valid = false;
                        break;
                    }
                    else stk.pop();
                }
                else {
                    stk.emplace(c);
                }
            }
            if (valid) ans.emplace_back(s);
        } while (next_permutation(s.begin(), s.end()));
        return ans;
    }
};