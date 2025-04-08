class Solution {
private:
    struct Project {
        int profit;
        int capital;
    };

public:
    int findMaximizedCapital(int k, int W, std::vector<int>& Profits, std::vector<int>& Capital) {
        // Note that this is a simplified financial model, i.e., you don't lose capital when investing in a project once you have enough capital.
        // In reality, you may lose capital if you invest in a project that fails.
        // TC: O(nlogn), same as using two heaps, but this is more readable and faster as it uses a single heap and a vector.
        // SC: O(n)
        int n = Profits.size();
        
        // Combine profits and capital into a vector of structs or pairs
        std::vector<Project> projects(n);
        for (int i = 0; i < n; ++i) {
            projects[i] = {Profits[i], Capital[i]};
        }

        // Sort projects by their capital requirements (ascending): This is faster than using a min-heap for capital.
        std::sort(projects.begin(), projects.end(), [](const Project& a, const Project& b) {
            return a.capital < b.capital;
        });

        // Max-Heap for profits
        std::priority_queue<int> maxHeap;

        int index = 0;

        // Pick up to 'k' projects
        for (int i = 0; i < k; ++i) {
            // Add all projects that are affordable (capital <= W) to the heap
            while (index < n && projects[index].capital <= W) {
                maxHeap.push(projects[index].profit);
                ++index;
            }

            // If there are no affordable projects left, break early
            if (maxHeap.empty()) {
                break;
            }

            // Select the most profitable project and update available capital
            W += maxHeap.top();
            maxHeap.pop();
        }

        return W;
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // Two heaps: one for capital and one for profits
        // TC: O(nlogn)
        // SC: O(n)
        auto cmpCapital = [&](int a, int b) { return capital[a] > capital[b]; };
        auto cmpProfit = [&](int a, int b) { return profits[a] < profits[b]; };

        priority_queue<int, vector<int>, decltype(cmpCapital)> minCapital(cmpCapital);
        priority_queue<int, vector<int>, decltype(cmpProfit)> maxProfit(cmpProfit);

        for (int i = 0; i < capital.size(); i++) {
            // Bottom-up approach: Takes a lot of time to build! Use a vector instead.
            minCapital.push(i);
        }

        for (int i = 0; i < k; i++) {
            while (!minCapital.empty() && capital[minCapital.top()] <= w) {
                // Push all projects that can be completed with the current capital
                maxProfit.push(minCapital.top());
                minCapital.pop();
            }
            if (maxProfit.empty()) {
                break;
            }
            // Note that this is a simplified financial model, i.e., you don't lose capital when investing in a project once you have enough capital.
            // In reality, you may lose capital if you invest in a project that fails.
            w += profits[maxProfit.top()];
            maxProfit.pop();
        }

        return w;
    }
};