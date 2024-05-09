class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Directed Graph cycle detection with hashset, DFS, and adj-list.
        // DFS with Adjacency-list
        // Key points: 
        //     1. Detect cycle (course that can't be passed) with a hash-set, or an array.
        //     2. Consider [1,0] as an edge: 1 -> 0, so if a node (course) got no out-edges, 
        //       indicating it has no prerequisites, i.e. it can be passed.
        //     3. Clean the list of the course, if all its prerequisites (adj nodes) can be passed.
        unordered_map<int, vector<int>> coursePrereqMap; // course -> its list of prerequisites
        for (auto& courseP: prerequisites) {
            int course = courseP[0];
            int prerequisite = courseP[1];
            coursePrereqMap[course].push_back(prerequisite);
        }

        unordered_set<int> visited; // for detecting cycle
        for (int i = 0; i < numCourses; i++) {
            // check if each course can be finished
            if (!canFinish_i(i, coursePrereqMap, visited)) return false;
        }
        return true;
    }

    bool canFinish_i(int i, unordered_map<int, vector<int>> &coursePrereqMap, unordered_set<int> &visited) {
        // return if course i can be finished
        // check its prerequisites through coursePrereqMap
        if (visited.count(i)) return false; // The same course is visited twice, indicating a cycle is detected, i.e. this course can't be passed.
        if (coursePrereqMap[i].empty()) return true; // no prerequisite for course i, so it can be passed.
        visited.insert(i);
        for (auto &prereq: coursePrereqMap[i]) {
            // check if its prerequisites can be passed
            if (!canFinish_i(prereq, coursePrereqMap, visited)) {
                // visited.erase(i); the courses in the cycle are not erased, because once other courses traverse to one of the course in the cycle, that course would be detected twice by the hash-set, similar idea applys to the clear of coursePrereqMap.
                // For more easy understanding, refer to the graph under repo.
                return false;
            }
        }
        visited.erase(i); // before backtracking, mark as not visited.
        coursePrereqMap[i].clear(); // marked as empty, because empty adj-list means it can be passed.
        return true;
    }
};