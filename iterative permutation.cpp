#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to generate the next permutation of a vector of integers
// Returns true if a next permutation exists, false otherwise
bool my_next_permutation(vector<int>& nums) {
    int n = nums.size();
    // If the size of the vector is less than or equal to 1, no permutation can be generated
    if (n <= 1) return false;

    // Step 1: Find the largest index i such that nums[i] < nums[i+1]
    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    // If no such index exists, the sequence is already the last permutation
    // We reverse it to get the first permutation and return false
    if (i < 0) {
        reverse(nums.begin(), nums.end());
        return false;
    }

    // Step 2: Find the largest index j such that nums[j] > nums[i]
    int j = n - 1;
    while (nums[j] <= nums[i]) {
        j--;
    }

    // Step 3: Swap nums[i] and nums[j]
    swap(nums[i], nums[j]);

    // Step 4: Reverse the sequence starting from i+1
    reverse(nums.begin() + i + 1, nums.end());

    // Return true indicating that a next permutation has been generated
    return true;
}

int main() {
    // Test the function with an example
    vector<int> nums = {0, 3, 2, 1};
    
    cout << "Permutations:" << endl;
    // Generate and print all permutations using the next_permutation function
    do {
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    } while (my_next_permutation(nums)); // Continue until the function returns false

    return 0;
}
