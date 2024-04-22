class Solution {
public:
    bool isPalindrome(int x) {
        // no iterator
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }

        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        return (x == reversed) || (x == reversed / 10);
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        // use iterator in for loop
        if (x < 0) return false;
        string str = to_string(x);
        auto rit = str.rbegin();
        int cnt = 0;
        int end = str.size()/2;
        for (auto it = str.begin(); it != str.end(); ++it, rit++) {
            if (cnt++ == end) break;
            if (*it != *rit) return false;
        }
        return true;
    }
};