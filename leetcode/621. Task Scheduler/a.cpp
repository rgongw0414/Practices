#include <bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    vector<pair<int, int>> charCount(26, {0, 0});
    // vector<int> charCooling(26, 0); // indicating each char is cooling or not, if not, it can be processed.
    for (auto &t: tasks) {
        charCount[t - 'A'].first++;
    }
    sort(charCount.begin(), charCount.end(), 
        [](auto &a, auto &b) {
            return a.first > b.first;
        }
    );
    
    int cycleUsed = 0;
    while (true) {

        int idxToSkip = -1; // the idx of done job
        for (int i = 0; i < 26; i++) {
            // cooling finished, and there are jobs to be done
            if (charCount[i].second == 0 and charCount[i].first > 0) {
                idxToSkip = i;
                charCount[i].first--;   
                if (charCount[i].first) charCount[i].second = n;
                break;
            }
        }
        cycleUsed++;

        bool done = true;
        for (int i = 0; i < 26; i++) {
            if (charCount[i].first > 0) {
                done = false;
                break;
            }
        }
        if (done) break;

        for (int i = 0; i < 26; i++) {
            if (idxToSkip == i) continue;

            // have being cooling, and the job is not done
            if (charCount[i].first > 0 and charCount[i].second > 0) {
                charCount[i].second--;
            }
        }

    }
    return cycleUsed;
}

int main() {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'C', 'D', 'D', 'E'};
    int n = 2;
    cout << leastInterval(tasks, n) << endl;
    return 0;
}