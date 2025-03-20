class Solution {
public:
    int strStr(string haystack, string needle) {
        // TC: O(m * n), SC: O(1)
        // Method: Brute force with substring comparison
        if (haystack.length() < needle.length()) {
            return -1;
        }
        
        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        return -1;        
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
    // Use the find function to search for the substring
    // TC: O(m * n), SC: O(1)
    // Method: Using the find function
    size_t pos = haystack.find(needle); // Find the first occurrence of the substring in the string
    
    // Check if the substring was found
    if (pos != string::npos) {
        return pos; // Return the starting index of the first occurrence
    }
    
    return -1; // Return -1 if the substring is not found
}
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        // TC: O(m * n), SC: O(1)
        // Method: Brute force
        int m = haystack.size(), n = needle.size();
        // m - n: the last possible start index of the needle
        for (int i = 0; i <= m - n; i++) {            
            for (int j = 0; j < n; j++) {
                if (haystack[i + j] != needle[j]) break;
                if (j == n - 1) return i;
            }
        }
        return -1;
    }
};
/*
haystack = "sadbutsad", needle = "sad"  
    i: m - n = 6 
    <   i  >
    "sadbutsad" 
    "sad"
*/