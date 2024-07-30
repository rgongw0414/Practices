// requires better space complexity
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        for (auto& e: prerequisites) {
            adjList[e[0]].push_back(e[1]);
        }

        unordered_set<int> visiting;
        vector<int> order;
        unordered_set<int> outputted; // keep track of current outputted course_id
        for (int course_id = 0; course_id < numCourses; course_id++) {
            if (cycle_detected_dfs(course_id, adjList, visiting, order, outputted)) {
                return {};
            }
        }
        return order;
    }

    bool cycle_detected_dfs(int course_id, unordered_map<int, vector<int>>& adjList, unordered_set<int>& visiting, vector<int>& order, unordered_set<int>& outputted) {
        // return true, if cycle detected, indicating current order can't be finished
        if (visiting.count(course_id)) return true;
        if (outputted.count(course_id)) return false;
        visiting.insert(course_id);
        for (auto& next_preq_id: adjList[course_id]) {
            if (cycle_detected_dfs(next_preq_id, adjList, visiting, order, outputted)) {
                return true;
            }
        }
        order.push_back(course_id);
        visiting.erase(course_id);
        outputted.insert(course_id);
        return false;
    }
};
