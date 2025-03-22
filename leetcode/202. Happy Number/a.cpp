class Solution {
private:
/* SC=(logN): N takes approximately logN digits in base 10
    int next_num(int n) {
        string n_str = to_string(n);
        int summation = 0;
        for (int i = 0; i < n_str.size(); i++) {
            summation += (n_str[i] - '0')*(n_str[i] - '0');
        }
        return summation;
    }
*/
    int next_num(int n) {
        // SC=O(1)
        int summation = 0;
        while (n != 0) {
            int remainder = n % 10;
            summation += remainder*remainder;
            n /= 10;
        }
        return summation;
    }
public: 
    bool isHappy(int n) {
        // Floyd's Cycle_finding Algorithm, TC=O(logN), SC=O(1)
        // * Related: 142. Linked List Cycle II, 287. Find the Duplicate Number, 457. Circular Array Loop
        // why O(logN)? because the number of digits in n is logN:
        // The number of digits in a positive integer n in base 10 is approximately ⌊log10(n) + 1⌋. For example: log10(1234) + 1 = 4
        // whether the number is happy number or not, there will be a cycle
        int slow = n;
        int fast = next_num(n);
        while (true) {
            if (slow == 1 || fast == 1) return true;
            if (slow == fast) return false;
            slow = next_num(slow);
            fast = next_num(next_num(fast));
        }
        return true;
    }
};

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