class Solution {
public:
    string reverseWords(string s) {
        // TC: O(N), SC: O(1), in-place
        // Reverse the entire string first
        reverse(s.begin(), s.end());
        
        int n = s.size();       // Get the size of the string
        int left = 0;           // Start of a word
        int right = 0;          // End of a word
        int i = 0;              // Iterator to traverse the string
        
        // Process each word in the reversed string
        while (i < n) {
            // Skip spaces
            while (i < n && s[i] == ' ') i++;
            
            // Break if we reach the end of the string
            if (i == n) break;
            
            // Copy the characters of the current word to their new position
            while (i < n && s[i] != ' ') s[right++] = s[i++];
            
            // Reverse the current word to make it readable in the final result
            reverse(s.begin() + left, s.begin() + right);
            
            // Add a space after the current word
            s[right] = ' ';
            right++;
            
            // Update the left pointer for the next word
            left = right;
            
            // Move to the next character
            i++;
        }
        
        // Resize the string to remove the extra space added at the end
        s.resize(right - 1);
        
        // Return the final result
        return s;
    }
};
    
class Solution {
public:
    string reverseWords(string s) {
        // TC: O(N), SC: O(word)
        int n = s.size();
        int i = 0;
        string ans = "";
        while (i < n) {
            // Skip leading spaces
            while (i < n && s[i] == ' ') i++;
            string str = "";
            while (i < n && s[i] != ' ') {
                str += s[i];
                i++;
            }
            if (!str.empty()) {
                ans = str + (ans.empty() ? "" : " ") + ans; // Append to the beginning
            }
        }
        return ans;
    }
};
