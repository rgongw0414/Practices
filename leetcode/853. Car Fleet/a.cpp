class Solution {
public:

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        /*
        A and B will be in the same fleet, if arrival time of A > the arrival time of B, 
        be in the different fleet, otherwise.
        position: [0, 3, 5, 8, 10]
        arrival time: [12, 3, 7, 1, 1]
        fleet 1: 8, 10
        fleet 2: 3, 5
        fleet 3: 0
        */
        int n = speed.size();
        int ans = 0;
        vector<pair<int, float>> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i].first = position[i];
            vec[i].second = (float) (target-position[i]) / speed[i];
        }
        sort(vec.begin(), vec.end());
        float maxTime = 0;
        for (int i = n-1; i >= 0; i--) {
            if (vec[i].second > maxTime) {
                ans++;
                maxTime = vec[i].second;
            }
        }
        return ans;
    }
};