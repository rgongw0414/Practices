class Solution {
public: 
    bool isHappy(int n) {
        // hash-set, TC=SC=O(logN)
        // why O(logN)? because the number of digits in n is logN:
        // The number of digits in a positive integer n in base 10 is approximately ⌊log10(n) + 1⌋. For example: log10(1234) + 1 = 4
        // whether the number is happy number or not, there will be a cycle
        string n_str = to_string(n);
        unordered_set<int> n_set;
        while (true) {
            long summation = 0;
            for (int i = 0; i < n_str.size(); i++) {
                summation += (n_str[i] - '0')*(n_str[i] - '0');
            }
            if (summation == 1) return true;
            if (n_set.count(summation)) return false;
            n_set.insert(summation);
            n_str = to_string(summation);
        }
        return true;
    }
};