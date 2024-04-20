class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      // bucket sort
      // time: O(N), space: O(N)
      unordered_map<int, int> table; // cnt 
      for (auto const& n: nums) {
          table[n]++;
      }
      vector<vector<int>> buckets(nums.size()+1);
      for (auto const& elem: table) {
          buckets[elem.second].emplace_back(elem.first);
      }
      vector<int> ans;
      int cnt = 0;
      for (int i = nums.size(); i >= 0; i--) {
        if (buckets[i].size() == 0) continue;
        if (cnt == k) break;
        for (auto &n: buckets[i]) {
          if (cnt == k) break;
          ans.emplace_back(n);
          cnt++;
        }
      }
      return ans;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      // heapsort
      // time: O(k*log(n)) k times of heapify
      unordered_map<int,int> map;
      for(int num : nums){
          map[num]++;
      }
      
      vector<int> res;
      // pair<first, second>: first is frequency,  second is number
      priority_queue<pair<int,int>> pq; 
      for(auto it = map.begin(); it != map.end(); it++){
          pq.push(make_pair(it->second, it->first));
          if(pq.size() > (int)map.size() - k){
              res.push_back(pq.top().second);
              pq.pop();
          }
      }
      return res;
    }
};