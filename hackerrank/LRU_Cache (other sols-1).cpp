class LRUCache : public Cache{
public:
    LRUCache(int capacity) {
        cp = capacity;
        tail = NULL;
        head = NULL;
    }
    void set(int key, int val) {
        if(mp.find(key) != mp.end())
            mp[key]->value = val;
        else {
            mp[key] = new Node(NULL, head, key, val);
            if(head) head->prev = mp[key];
            head = mp[key];
            if(!tail) tail = head;
            if(mp.size() > cp) {
                mp.erase(tail->key);
                tail = tail->prev;
                delete tail->next;
                tail->next = NULL;
            }
        }
    }
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            if(!mp[key]->next)
                tail = mp[key]->prev;
            head = mp[key];
            while(mp[key]->prev) {
                Node* temp = mp[key]->prev;
                mp[key]->prev = mp[key]->prev->prev;
                if(mp[key]->prev)
                    mp[key]->prev->next = mp[key];
                if(mp[key]->next)
                    mp[key]->next->prev = temp;
                temp->next = mp[key]->next;
                temp->prev = mp[key];
                mp[key]->next = temp;
            }
            return mp[key]->value;
        }
        else
            return -1;
    }
};