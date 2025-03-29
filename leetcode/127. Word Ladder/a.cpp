/*
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
     front
    q: hit
        ait (skipped) bit (skipped) ... zit (skipped)
        hat (skipped) hbt (skipped) ... hot (added), hpt (skipped) ... 
    q: hot
        dot (added) lot (added) 
    q: dot lot
        dog (added) log (added)
    q: lot dog log
    ...
    q: log
        cog (endWord found)

       hit
        |
       hot
       / \
     dot lot
    /...|...\
       dog  log
              \
              cog

Worst case: Complete graph, where |E| = |V|*(|V| - 1) / 2, where |E|= number of edges, |V| = number of vertices
    |E| = O(N^2), where N = wordList.size()
    |V| = O(N)
    TC = O(M * N^2), where M = wordList[i].size()
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // BFS
        // The neighbor of a word is created when traversing the word by changing one letter at a time.
        // TC: O(M * N^2)
        //     N: wordList.size(),
        //     M: wordList[i].size()
        //     26: number of possible mutations (a-z)
        // SC: O(N)
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