/*
    Given array of tasks & cooldown b/w same tasks, return least # of units of time
    Ex. tasks = ["A","A","A","B","B","B"] n = 2 -> 8 (A->B->idle->A->B->idle->A->B)

    Key is to determine # of idles, greedy: always arrange task w/ most freq first
    3A, 2B, 1C -> A??A??A -> AB?AB?A -> ABCAB#A, since A most freq, needs most idles

    Time: O(n)
    Space: O(1)
*/
/*
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // math analysis
        vector<int> counter(26);
        
        int maxCount = 0;
        int maxCountFrequency = 0;
        
        for (int i = 0; i < tasks.size(); i++) {
            counter[tasks[i] - 'A']++;
            int currCount = counter[tasks[i] - 'A'];
            
            if (maxCount == currCount) {
                maxCountFrequency++;
            } else if (maxCount < currCount) {
                maxCount = currCount;
                maxCountFrequency = 1;
            }
        }
        
        int partCount = maxCount - 1;
        int partLength = n - (maxCountFrequency - 1);
        int emptySlots = partCount * partLength;
        int availableTasks = tasks.size() - maxCount * maxCountFrequency;
        int idles = max(0, emptySlots - availableTasks);
        
        return tasks.size() + idles;
    }
};
*/

// Time O(n * cooldown) = O(n*1) = O(n)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;  // maxHeap: sort by the number of each job 

        // first: remaining number this job, remaining cooling time of this job
        // second: the time this job end cooling
        queue<pair<int, int>> q; 

        vector<int> counter(26);
        for (int i = 0; i < tasks.size(); ++i)
            ++counter[tasks[i] - 'A'];
        for (int i = 0; i < 26; ++i) {
            if (counter[i])
                pq.push(counter[i]);
        }

        int time = 0;
        while (!q.empty() || !pq.empty()){
            ++time;
            if (!pq.empty()) {
                if (pq.top() - 1)
                    q.push({pq.top() - 1, time + n});
                pq.pop(); // trick!!!
            }
            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);  // trick!!!
                q.pop();
            }
        }
        return time;
    }
};


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // brute-force: always choose the job with max count
        vector<pair<int, int>> charCount(26, {0, 0}); // map remaining job count to its remaining cooling time
        for (auto &t: tasks) {
            charCount[t - 'A'].first++;
        }
        
        int cycleUsed = 0;
        while (true) {
            cycleUsed++;
            // sort the job, so that the job with max count is alwayas chosen
            sort(charCount.begin(), charCount.end(), 
                [](auto &a, auto &b) {
                    return a.first > b.first;
                }
            );

            for (int i = 0; i < 26; i++) {
                // have being cooling, and the job is not done
                if (charCount[i].first > 0 and charCount[i].second > 0) {
                    charCount[i].second--;
                }
            }

            for (int i = 0; i < 26; i++) {
                if (charCount[i].second == 0 and charCount[i].first > 0) {
                    charCount[i].first--;   
                    charCount[i].second = n + 1;
                    break;
                }
            }

            bool done = true;
            for (int i = 0; i < 26; i++) {
                if (charCount[i].first > 0) {
                    done = false;
                    break;
                }
            }
            if (done) break;
        }
        return cycleUsed;
    }
};