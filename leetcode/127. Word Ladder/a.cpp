class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        int seq_len = 1;
        while (!q.empty()) {
            int level_size = q.size();
            while (level_size--) {
                string curr_word = q.front();
                q.pop();
                for (int i = 0; i < curr_word.size(); i++) {
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (curr_word[i] == ch) continue;
                        string next_word = curr_word;
                        next_word[i] = ch;
                        if (!words.count(next_word)) continue;
                        if (visited.count(next_word)) continue;
                        if (next_word == endWord) return seq_len + 1;
                        q.push(next_word);
                        visited.insert(next_word);
                    }
                }
            }
            seq_len++;
        }
        return 0;
    }
};