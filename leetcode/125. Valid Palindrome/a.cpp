/*
    Given a string s, return true if it's a palindrome
    Ex. s = "A man, a plan, a canal: Panama" -> true

    2 pointers, outside in, skip non-letters & compare

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = 0;
        for (auto& c: s) {
            if (isalnum(s[i])) {
                s[j] = tolower(s[i]);
                j++;
            }
            i++;
        }
        int len = j;
        i = 0;
        j = len - 1;
        while (i < len/2) {
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }        
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (auto const& c: s) {
            if ((c >= 'a'&& c <= 'z') || (c >= '0' && c <= '9')) str += c;
            else if (c >= 'A'&& c <= 'Z') str += 'a' + c-'A';          
        }
        // auto str_r = str;
        // reverse(str_r.begin(), str_r.end());
        // if (str_r != str) return false;
        // else return true;
        // if (str.size() == 1) return true;
        auto it1 = str.begin();
        auto it2 = str.rbegin();
        int end = str.size() / 2, cnt = 0;
        while (cnt != str.size()/2) {
            if (*it1 != *it2) return false;
            it1++;
            it2++;
            cnt++;
        }
        return true;
    }
};