/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // Iterative BFS with TC & SC: O(N), it's hardly readable compared with recursive BFS.
        // Node.val is unique for each node.
        // There are no repeated edges and no self-loops in the graph.
        // The Graph is connected and all nodes can be visited starting from the given node.
        if (!node) return nullptr;
        unordered_map<Node*, Node*> cloneMap; // mapping original nodes to their clones, preventing from nodes being copied over ans over again.
        cloneMap[node] = new Node(node->val); // make a copy of node

        queue<Node*> q; // for BFS traversal
        q.push(node); 
        while (!q.empty()) {
            // BFS traverse and copy each node and make a clone of it.
            Node* currNode = q.front();
            q.pop();
            for (Node* neighbor: currNode->neighbors) {
                // copy each currNode's neighbor on-the-fly
                if (cloneMap.find(neighbor) == cloneMap.end()) {
                    // copy of neighbor has not been created, so make a copy of nieghbor manually.
                    cloneMap[neighbor] = new Node(neighbor->val); 
                    q.push(neighbor); // push to stack for BFS traversal
                }
                Node* neighborCopy = cloneMap[neighbor]; // copy of neighbor
                cloneMap[currNode]->neighbors.push_back(neighborCopy);
            }
        }
        return cloneMap[node];
    }
};