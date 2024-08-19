class Solution {
public:
    // recursive DFS, TC=O(n), SC=O(n)
    // DFS function to detect a cycle in the graph
    bool dfs(vector<int> adj[], int ind, int par, vector<int> &vis, stack<int> &st) {
        vis[ind] = 1; // Mark the current node as visited
        st.push(ind); // Push the current node onto the stack

        for (auto x : adj[ind]) {
            if (vis[x] == 0) {
                // If the neighbor is not visited, recursively call DFS on it
                if (dfs(adj, x, ind, vis, st))
                    return true;
            } else if (par != x) {
                // If the neighbor is visited and it's not the parent, cycle is detected
                st.push(x);
                return true;
            }
        }

        st.pop(); // If no cycle is found, pop the current node from the stack
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[n+1];

        // Build the graph using adjacency list
        for (auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<int> vis(n+1, 0); // Visited array to keep track of visited nodes
        stack<int> st; // Stack to keep track of the path in the DFS

        unordered_map<int, int> mp; // Map to store nodes involved in the cycle

        // Start DFS from node 1; Since the graph is not broken, we can start with any node
        if (dfs(adj, 1, -1, vis, st))
            cout << "Found Cycle" << endl;

        // Extract the cycle nodes from the stack
        while (!st.empty() && mp.find(st.top()) == mp.end()) {
            mp[st.top()]++;
            st.pop();
        }

        // Find the redundant edge by iterating over edges in reverse order
        // because we are supposed to return last edge from input
        for (int i = n-1; i >= 0; i--) {
            int one = edges[i][0];
            int two = edges[i][1];
            if (mp.find(one) != mp.end() && mp.find(two) != mp.end())
                return {one, two};
        }

        return {};
    }
};