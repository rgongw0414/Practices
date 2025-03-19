#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        // TC=SC=O(N)
        int n = ratings.size();
        std::vector<int> candies(n, 1);
        // First pass: Takes care of the second condition but only accounts for the child's left neighbor
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        // Second pass: Makes sure candies[i] is larger than the right child candies[i+1]
        // Why not do it from left to right? Because the updated candies[i] is not taking into consideration in the next iteration.
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                // The maximum between its candies[i] and one more than the right neighbor's candies. 
                // This ensures that both neighboring conditions are checked and satisfied.
                candies[i] = std::max(candies[i], candies[i + 1] + 1);
            }
        }

        int totalCandies = 0;
        for (int& candy : candies) {
            totalCandies += candy;
        }

        return totalCandies;
    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        // TC=O(N^2), SC=O(N)
        int ans = 0;
        int n = ratings.size();
        vector<int> candies(n, 0); // record the number of each child's received candies
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && ratings[i] > ratings[i+1]) {
                // give child-i enough candies s.t. child-i has more candies than child-(i+1)
                while (candies[i] <= candies[i+1]) candies[i]++;
            }
            if (i > 0 && ratings[i-1] < ratings[i]) {
                // give child-i enough candies s.t. child-i has more candies than child-(i-1)
                while (candies[i-1] >= candies[i]) candies[i]++;
            }
            cout << candies[i] << " ";
        }
        cout << endl;
        for (int i = n - 1; i >= 0; i--) {
            if (i > 0 && ratings[i-1] < ratings[i]) {
                // give child-i enough candies s.t. child-i has more candies than child-(i-1)
                while (candies[i-1] >= candies[i]) candies[i]++;
            }
            if (i < n - 1 && ratings[i] > ratings[i+1]) {
                // give child-i enough candies s.t. child-i has more candies than child-(i+1)
                while (candies[i] <= candies[i+1]) candies[i]++;
            }
            cout << candies[n-i-1] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            ans += candies[i];
        }
        return ans + n;
    }
};

int main() {
    Solution sol;
    vector<int> ratings = {3,2,1,1,4,3,3};
    for (int i = 0; i < ratings.size(); i++) {
        cout << ratings[i] << " ";
    }
    cout << endl;
    cout << sol.candy(ratings) << endl;
    return 0;
}