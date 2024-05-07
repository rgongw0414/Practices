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
        // Iterative DFS with TC & SC: O(N), it's hardly readable compared with recursive DFS.
        // Node.val is unique for each node.
        // There are no repeated edges and no self-loops in the graph.
        // The Graph is connected and all nodes can be visited starting from the given node.
        if (!node) return nullptr;
        unordered_map<Node*, Node*> cloneMap; // mapping original nodes to their clones, preventing from nodes being copied over ans over again.
        cloneMap[node] = new Node(node->val); // make a copy of node

        stack<Node*> stk; // for DFS traversal
        stk.push(node); 
        while (!stk.empty()) {
            // DFS traverse and copy each node and make a clone of it.
            Node* currNode = stk.top();
            stk.pop();
            for (Node* neighbor: currNode->neighbors) {
                // copy each currNode's neighbor on-the-fly
                if (cloneMap.find(neighbor) == cloneMap.end()) {
                    // copy of neighbor has not been created, so make a copy of nieghbor manually.
                    cloneMap[neighbor] = new Node(neighbor->val); 
                    stk.push(neighbor); // push to stack for DFS traversal
                }
                Node* neighborCopy = cloneMap[neighbor]; // copy of neighbor
                cloneMap[currNode]->neighbors.push_back(neighborCopy);
            }
        }
        return cloneMap[node];
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // Recursive DFS with TC & SC: O(N)
        // Node.val is unique for each node.
        // There are no repeated edges and no self-loops in the graph.
        // The Graph is connected and all nodes can be visited starting from the given node.
        if (!node) return nullptr;
        unordered_map<Node*, Node*> cloneMap; // mapping original nodes to their clones, preventing from nodes being copied over ans over again.
        return cloneNode(node, cloneMap);
    }

    Node* cloneNode(Node* node, unordered_map<Node*, Node*>& cloneMap) {
        // Return a clone of node, check whether it has been copied yet.
        if (cloneMap.find(node) != cloneMap.end()) {
            // The clone of node has been created, so just return it from the hashmap.
            // *** This also stop from traversing the cycle of the graph ***
            return cloneMap[node];
        }
        // Otherwise, create a clone of it.
        Node* clone = new Node(node->val);
        cloneMap[node] = clone;
        for (auto &neighbor: node->neighbors) {
            clone->neighbors.push_back(cloneNode(neighbor, cloneMap));
        }
        return clone;
    }
};