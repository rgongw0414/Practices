class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        // valid: ()[]{}
        // invalid: ([)]
        for (auto const& c: s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.emplace(c);
            }
            else if (c == ')') {
                if (stk.empty()) return false; // ) or ] or } comes before ( or [ or {
                if (stk.top() == '(') stk.pop();
                else return false;
            }
            else if (c == ']') {
                if (stk.empty()) return false;
                if (stk.top() == '[') stk.pop();
                else return false;
            }
            else if (c == '}') {
                if (stk.empty()) return false;
                if (stk.top() == '{') stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};