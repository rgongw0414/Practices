class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 1) {
            return stoi(tokens[0]);
        }
        stack<int> stk;
        for (auto const& s: tokens) {
            if (s == "+" or s == "-" or s == "*" or s == "/") {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                if (s == "+") stk.emplace(a+b);
                if (s == "-") stk.emplace(a-b);
                if (s == "*") stk.emplace(a*b);
                if (s == "/") stk.emplace(a/b);
            }
            else {
                int n = stoi(s);
                stk.emplace(n);
            }
        }
        return stk.top();
    }
};