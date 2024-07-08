/*
    Courses & prerequisites, return ordering of courses to take to finish all courses
    Ex. numCourses = 2, prerequisites = [[1,0]] -> [0,1], take course 0 then 1

    All courses can be completed if there's no cycle, check for cycles

    Time: O(V + E)
    Space: O(V + E)
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        // build adjacency list of prereqs
        for (int i = 0; i < prerequisites.size(); i++) {
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        unordered_set<int> outputted;
        unordered_set<int> visiting;  // cycle detected, if one course found visiting during DFS traversal
        
        vector<int> result;
        for (int course = 0; course < numCourses; course++) {
            if (!dfs(course, m, outputted, visiting, result)) {
                // by dfs, we can find the top-priority course by the end of traversals
                return {};
            }
        }
        return result;
    }

private:
    // a course has 3 possible states:
    // outputted -> course added to result (the head is the first course should be taken)
    // visiting -> course not added to result, but added to cycle
    // unvisited -> course not added to result or visiting
    bool dfs(int course, unordered_map<int, vector<int>>& m, unordered_set<int>& outputted,
        unordered_set<int>& visiting, vector<int>& result) {
        
        if (visiting.find(course) != visiting.end()) {
            return false;
        }
        if (outputted.find(course) != outputted.end()) {
            return true;
        }
        visiting.insert(course);
        for (int i = 0; i < m[course].size(); i++) {
            int nextCourse = m[course][i];
            if (!dfs(nextCourse, m, outputted, visiting, result)) {
                return false;
            }
        }
        visiting.erase(course);
        outputted.insert(course);
        result.push_back(course);
        return true;
    }
};
