class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<string> line; // Words in a line
        int word_len = 0, i = 0;
        
        while (i < words.size()) {
            if (word_len + line.size() + words[i].size() > maxWidth) {
                // Can't fit the next word in the current line, so add spaces to justify the current line
                int extra_space = maxWidth - word_len;
                int spacing_num = max(1, (int)line.size() - 1); // line.size() - 1: Why minus 1? Because there are no spaces after the last word
                // if there's only one word in the line, spacing_num will be 1, this is to avoid division by 0, and also to make sure that spaces are added to the right of the word
                int spaces = extra_space / spacing_num;  // Number of spaces between words
                int remainder = extra_space % spacing_num; // Extra spaces are added from left to right
                
                for (int j = 0; j < spacing_num; ++j) {
                    line[j] += string(spaces, ' '); // Add spaces between words
                    if (remainder > 0) {
                        line[j] += " ";
                        --remainder;
                    }
                }
                
                string justified_line;
                for (const auto& word : line) {
                    justified_line += word;
                }
                res.push_back(justified_line);
                
                line.clear();
                word_len = 0;
            }
            
            line.push_back(words[i]);
            word_len += words[i].size();
            ++i;
        }
        
        // Handling last line
        string last_line = line[0];
        for (int j = 1; j < line.size(); ++j) {
            last_line += " " + line[j];
        }
        last_line += string(maxWidth - last_line.size(), ' '); // Add spaces to the right of the last word
        res.push_back(last_line);
        
        return res;
    }
};