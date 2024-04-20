/*
Doubly linked-list 
LRU <-> ... <-> MRU

*/

class Node {

public: 
    int val;
    Node* prev;
    Node* next;
    int key;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LRUCache {
    // cleaner code, but repeated map insert/erase, and node pointer allocation/free
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;  // LRU
    Node* tail;  // MRU
    
public:
    LRUCache(int capacity) {
        // LRU node: head, MRU (most recent used): tail
        this->capacity = capacity;
        // head and tail work as dummy nodes 
        this->head = new Node(-1, -1); // head->next: LRU node, 
        this->tail = new Node(-1, -1); // tail->prev: MRU node
        this->head->next = this->tail; // head and tail wouldn't be the same, even when initialized.
        this->tail->prev = this->head; // benefits of doing so: In removeNode, we don't have to deal with head and tail, or edge cases, 
        // e.g. when one node left in list (excluding head and tail), there no need to worry about head and tail, because they work as dummy nodes, which will never be deleted.
    }
    void removeNode(Node *target) {
        // remove the node from list; note that we have to free the memory manually after calling this function
        // target: the target node we want to remove from list
        // targetPrev->target->targetNext
        auto targetPrev = target->prev;
        auto targetNext = target->next;
        targetPrev->next = targetNext;
        targetNext->prev = targetPrev;
        this->cache.erase(target->key);
        delete target;
    } 
    void insertNode(Node *newMRU) {
        // insert newNode into list, and set as MRU node, i.e. set as the node prev to tail.
        // from: origMRU->tail
        // to:   origMRU->newMRU->tail
        auto origMRU = this->tail->prev;
        origMRU->next = newMRU;
        newMRU->prev = origMRU;
        newMRU->next = this->tail; // MRU is the node prev to tail
        this->tail->prev = newMRU;
        this->cache[newMRU->key] = newMRU;
    }
    
    int get(int key) {
        if (this->cache.find(key) == this->cache.end()) {
            return -1;
        }
        Node *newNode = new Node(key, this->cache[key]->val); // new node to be set as MRU, which with its key and value copy of orig node
        this->removeNode(this->cache[key]); // remove the node from cache
        this->insertNode(newNode); // insert into list, and set as MRU node.
        return newNode->val;
    }
    
    void put(int key, int value) {
        if (this->cache.find(key) != this->cache.end()) {
            this->removeNode(this->cache[key]);
        }
        Node* newNode = new Node(key, value);
        this->insertNode(newNode);
        if (this->cache.size() > this->capacity) {
            auto lruNode = this->head->next;
            this->removeNode(lruNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */