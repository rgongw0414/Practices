class TimeMap {
    unordered_map<string, vector<pair<int, string>>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        this->m[key].emplace_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        // better TC
        int l = 0, r = this->m[key].size() - 1;
        // int time_prev = -1;
        while (l <= r) {
            // find the max timestamp_prev satisfying timestamp
            int mid = l + (r-l) / 2;            
            int cur_time = m[key][mid].first;
            if (cur_time == timestamp) {
                return this->m[key][mid].second;
            }
            else if (cur_time < timestamp) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        // if the wanted value has been inserted before, 
        // the searching would stopped at r == 0, 
        // which is the first elem of m[key].
        if (r < 0) 
            return "";
        return this->m[key][r].second;
    }
};


class TimeMap {
    unordered_map<string, unordered_map<int, string>> m;
    unordered_map<string, vector<int>> t;
public:
    TimeMap() {
        
    }
    /*
    readable solution, maybe less memory needed?
    auto it = m.begin();
    it + offset
    */
    void set(string key, string value, int timestamp) {
        this->m[key][timestamp] = value;
        this->t[key].emplace_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        int l = 0, r = this->t[key].size() - 1;
        int time_prev = -1;
        while (l <= r) {
            // find the max timestamp_prev satisfying timestamp
            int mid = l + (r-l) / 2;            
            if (max(time_prev, this->t[key][mid]) <= timestamp)
                time_prev = max(time_prev, this->t[key][mid]);            
            if (this->t[key][mid] == timestamp) {
                time_prev = timestamp;
                break;
            }
            else if (this->t[key][mid] < timestamp) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        if (time_prev == -1) 
            return "";
        return this->m[key][time_prev];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */