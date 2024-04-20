class Solution {
private:
    unordered_map<Node *, Node *> map;
public:
    Node *copyRandomList(Node *head) {
        if (!head) return head;
        if (map.find(head) != map.end()) {
            // return the node if already copied
            // for: newNode->random = copyRandomList(head->random);
            return map[head];
        }
        Node *newNode = new Node(head->val);
        map[head] = newNode;
        newNode->next = copyRandomList(head->next);
        newNode->random = copyRandomList(head->random);  // all the nodes are already copied in line-14
        return newNode;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // cleaner code
        if (!head) return nullptr; // no node in list
        unordered_map<Node*, Node*> node_map; // map old node ptr to newly created node ptr, in order to check created or not.
        // <orig pointer, new node pointer>, new node is a copy of the orig node
        Node *curr = head;
        while (curr) {
            node_map[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr) {
            node_map[curr]->next = node_map[curr->next];
            node_map[curr]->random = node_map[curr->random];
            curr = curr->next;
        }
        return node_map[head];
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr; // no node in list
        unordered_map<Node*, Node*> node_map; // map old node ptr to newly created node ptr, in order to check created or not.
        // <orig pointer, new node pointer>, new node is a copy of the orig node
        Node *curr = head;
        Node *newNode = new Node(curr->val);
        Node *newHead = newNode;
        node_map[curr] = newNode;
        // need to create new nodes for next and random
        Node *newNext = nullptr;
        if (curr->next) {
            // create a copy of the orig node's next node
            newNext = new Node(curr->next->val);
            node_map[curr->next] = newNext;
        }
        newNode->next = newNext; // update the next ptr of the ceated new node

        Node *newRandom = nullptr;
        if (curr->random) {
            // is this a better style?
            newRandom = new Node(curr->random->val);
            auto insertionResult = node_map.insert({curr->random, newRandom}); // iterator to the inserted element
            bool intertionSucceed = insertionResult.second;
            if (!intertionSucceed) {
                delete newRandom; // prevent from memory laek
                // or alternatively: delete insertionResult.first->second;
                newRandom = node_map[curr->random];
            }
            // if succeed, the newRandom is the pointer to the inserted node, i.e., it's already handled by line-39.
        }
        newNode->random = newRandom;

        curr = curr->next;
        while (curr) {
            // here newNode, newNext, newRandom are prev nodes
            newNode = node_map[curr];
            newNext = nullptr;
            if (curr->next) {
                newNext = new Node(curr->next->val);
                auto insertionResult = node_map.insert({curr->next, newNext}); // iterator to the inserted element
                bool intertionSucceed = insertionResult.second;
                if (!intertionSucceed) {
                    // next node might be pointed by the random ptr of other copied nodes
                    delete newNext; // prevent from memory laek
                    // or alternatively: delete insertionResult.first->second;
                    newNext = node_map[curr->next]; // return the existing node pointer
                }
            }

            newRandom = nullptr;
            if (curr->random) {
                // random might repeatedly points to prev nodes
                newRandom = new Node(curr->random->val);
                auto insertionResult = node_map.insert({curr->random, newRandom}); // iterator to the inserted element
                bool intertionSucceed = insertionResult.second;
                if (!intertionSucceed) {
                    delete newRandom; // prevent from memory laek
                    // or alternatively: delete insertionResult.first->second;
                    newRandom = node_map[curr->random];
                }
                // if succeed, the newRandom is the pointer to the inserted node, i.e., it's already handled by line-72.
            }
            newNode->next = newNext;
            newNode->random = newRandom;
            curr = curr->next;
        }
        return newHead;
    }
};