#include <bits/stdc++.h>
using namespace std;
/*
equations = [["a","b"],
             ["b","c"]]
equations[0]: ["a","b"]
*/

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // BFS
        // TC: O(V + E), SC: O(V + E)
        // Build the graph
        unordered_map<string, vector<pair<string, double>>> adj_list; // Map a -> list of [b, a/b]
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            adj_list[a].emplace_back(b, values[i]);
            adj_list[b].emplace_back(a, 1.0 / values[i]);
        }

        vector<double> res;
        // For each query, do BFS
        for (const auto& query : queries) { 
            string src = query[0];
            string target = query[1];
            res.push_back(bfs(src, target, adj_list));
        }
        return res;
    }

private:
    double bfs(const string& src, const string& target, unordered_map<string, vector<pair<string, double>>>& adj_list) {
        if (!adj_list.count(src) || !adj_list.count(target)) {
            return -1.0;
        }
        // src->node->...->target
        queue<pair<string, double>> q; // for each node, we store the node and the weight from src to this node
        unordered_set<string> visited;
        q.emplace(src, 1.0);
        visited.insert(src);

        while (!q.empty()) {
            // In the 1st iter: node = src, weight = src / src = 1.0; 
            // in next iter, node is a neighbor of src, weight is the product of all weights from src to node
            auto [node, weight] = q.front(); 
            q.pop();

            if (node == target) {
                return weight;
            }

            for (const auto& [nei, neiWeight] : adj_list[node]) { // push all neighbors of node
                if (!visited.count(nei)) {
                    q.emplace(nei, weight * neiWeight); // weight from src to nei = weight from src to node * weight from node to nei
                    visited.insert(nei);
                }
            }
        }
        return -1.0; // return -1.0 if no path found
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Recursive DFS
        // TC: O(V + E), SC: O(V + E)
        // Build the graph
        unordered_map<string, vector<pair<string, double>>> adj_list; // Map a -> list of [b, a/b]
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            adj_list[a].emplace_back(b, values[i]);
            adj_list[b].emplace_back(a, 1.0 / values[i]);
        }

        vector<double> res;
        // For each query, do DFS
        for (const auto& query : queries) { 
            string src = query[0];
            string target = query[1];
            unordered_set<string> visited;
            res.push_back(dfs(src, target, adj_list, visited));
        }
        return res;
    }

private:
    double dfs(const string& src, const string& target, unordered_map<string, vector<pair<string, double>>>& adj_list, unordered_set<string>& visited) {
        if (!adj_list.count(src) || !adj_list.count(target)) {
            return -1.0;
        }
        if (src == target) {
            return 1.0;
        }
        visited.insert(src);

        for (const auto& [nei, neiWeight] : adj_list[src]) { // push all neighbors of src
            if (!visited.count(nei)) {
                double weight = dfs(nei, target, adj_list, visited); // corrected 'visite' to 'visited'
                if (weight != -1.0) {
                    return weight * neiWeight;
                }
            }
        }
        return -1.0; // return -1.0 if no path found
    }
};