/*
Worst case: Complete graph, where |E| = |V|*(|V| - 1) / 2, where |E|= number of edges, |V| = number of vertices
    |E| = O(N^2), where N = wordList.size()
    |V| = O(N)
    TC = O(M * N^2), where M = wordList[i].size() */
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // BFS
        // The neighbor of a word is created when traversing the word by changing one letter at a time.
        // TC: O(M * N^2)
        //     N: wordList.size(),
        //     M: wordList[i].size()
        //     4: number of possible mutations (A, C, G, T)
        // SC: O(N)
        unordered_set<string> bank_set(bank.begin(), bank.end());
        if (startGene == endGene) return 0; // no mutation needed
        if (!bank_set.count(endGene)) return -1; // end gene not in bank
        queue<string> q;
        q.push(startGene);
        unordered_set<string> visited;
        const char ch_arr[4] = {'A', 'C', 'G', 'T'};
        int mut_num = 0;
        while (!q.empty()) { 
            int level_size = q.size();
            auto gene = q.front();
            while (level_size--) {
                q.pop();
                for (int i = 0; i < gene.size(); i++) { // O(M)
                    for (const auto& ch : ch_arr) { // O(4)
                        if (ch == gene[i]) continue; // skip if the mutation character is the same as the original
                        string mutation = gene;
                        mutation[i] = ch;
                        if (visited.count(mutation) || !bank_set.count(mutation)) continue; 
                        if (mutation == endGene) return mut_num + 1; 
                        q.push(mutation);
                        visited.insert(mutation);
                    }
                }
            }
            mut_num++;
        }
        return -1;
    }
};