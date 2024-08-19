class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // recursive DFS, TC=O(n^2), SC=O(n)
        unordered_map<int, vector<int>> adj_list;
        unordered_set<int> visited;
        for (int i = 0; i < edges.size(); i++) {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
            if (is_cyclic(-1, edges[i][0], adj_list, visited)) {
                return {edges[i][0], edges[i][1]};
            }
        }
        return {};
    }

    bool is_cyclic(int parent, int node_i, unordered_map<int, vector<int>> &adj_list, unordered_set<int> &visited) {
        if (visited.count(node_i)) return true;
        visited.insert(node_i);
        for (int &adj_node: adj_list[node_i]) {
            if (adj_node == parent) continue;
            if (is_cyclic(node_i, adj_node, adj_list, visited)) return true;
        }
        visited.erase(node_i);
        return false;
    }
};