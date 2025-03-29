class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // BFS
        // TC: O(N * M * 4): Not quite sure about the TC/SC though
        //     N: bank.size(), 
        //     M: gene.size() == 8,
        //     4: number of possible mutations (A, C, G, T)
        // SC: O(8*N) = O(N)
        if (startGene == endGene) return 0; // no mutation needed
        if (find(bank.begin(), bank.end(), endGene) == bank.end()) return -1; // end gene not in bank
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        unordered_set<string> visited;
        const char ch_arr[4] = {'A', 'C', 'G', 'T'};
        while (!q.empty()) { 
            auto [gene, mut_num] = q.front();
            q.pop();
            for (int i = 0; i < gene.size(); i++) { // O(M)
                for (const auto& ch : ch_arr) { // O(4)
                    if (ch == gene[i]) continue; // skip if the mutation character is the same as the original
                    string mutation = gene;
                    mutation[i] = ch;
                    if (visited.count(mutation) || find(bank.begin(), bank.end(), mutation) == bank.end()) continue; // each find() is O(8*N)
                    
                    /* Note that we don't need to check if mut_num + 1 is minimum
                     * because we are using BFS, which guarantees that the first time we reach
                     * the end gene, it is the minimum number of mutations needed. */
                    if (mutation == endGene) return mut_num + 1; // found the end gene
                    q.push({mutation, mut_num + 1});
                    visited.insert(mutation);
                }
            }
        }
        return -1;
    }
};