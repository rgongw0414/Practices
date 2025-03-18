class RandomizedSet {
private:
    vector<int> r_vec; // To store elements
    unordered_map<int, int> r_map; // Maps value -> index in vector

public:
    RandomizedSet() {
        srand(time(NULL)); // Seed the random number generator
    }
    
    bool insert(int val) {
        if (r_map.count(val)) {
            return false; // Value already exists
        }
        r_map[val] = r_vec.size(); // Map value to its index in the vector
        r_vec.push_back(val); // Add value to the vector
        return true;
    }
    
    bool remove(int val) {
        if (!r_map.count(val)) {
            return false; // Value doesn't exist
        }
        int index = r_map[val];
        int lastVal = r_vec.back();
        
        // Move the last element into the spot of the element to be removed
        r_vec[index] = lastVal;
        r_map[lastVal] = index;
        
        // Remove the last element
        r_vec.pop_back();
        r_map.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % r_vec.size(); // Get random index
        return r_vec[randomIndex]; // Return the element at the random index
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */