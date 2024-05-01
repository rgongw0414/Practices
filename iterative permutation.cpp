#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to generate the next permutation of a vector of integers
// Returns true if a next permutation exists, false otherwise
bool my_next_permutation(vector<int>& nums) {
    // What this function actually does: generated the next permutation of the numbers, and also, increased nums by the smallest amount
    // i.e. started from: 1223, the next one is 1232, instead of 1332, because from 1223 to 1232 the difference b/w them is the smallest.
    // We only change the position of a "digit" when everything to the right is in descending order, 
    // because if it isn't in descending order, then there are still more permutations to go (i.e. we can "increase" the permutation by a smaller amount).
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
    // *** LIMIT: to show all the permutations, nums must be sorted in ascending order first, otherwise,
    //            if nums is in descending order, it will be returned right after calling my_next_permutation, e.g. nums = {3, 2, 1, 0}, 
    //            and as a result, not all the permutations are shown. ***
    /*
    Permutations:
        1 2 2 3 
        1 2 3 2 
        1 3 2 2 
        2 1 2 3 
        2 1 3 2 
        2 2 1 3 
        2 2 3 1 
        2 3 1 2 
        2 3 2 1 
        3 1 2 2 
        3 2 1 2 
        3 2 2 1 
    We can see that the nums vector is permuted in lexicographic order, generating all possible permutations.
    But if looked closely, the printed nums are lexicographic order, specifically they are "numbers" in ascending order: 
    1223 -> 1232 -> 1322 -> 2123 -> 2132 -> 2213 -> 2231 -> 2312 -> 2321 -> 3122 -> 3212 -> 3221, 
    which is the idea of the my_next_permutation function, permute the numbers from the smallest to the largest (from 1223 to 3221), if not started from 1223, 
    e.g. started from 1322, 1223 and 1232 would benn skipped, i.e. 2 permutations are skipped.
    */
    vector<int> nums = {1, 2, 3, 4}; 
    // reverse(nums.begin(), nums.end());
    // sort(nums.begin(), nums.end()); // if nums is not sorted in ascending order, it will be returned right after calling my_next_permutation.
    int permutationCount = 0;
    cout << "Permutations:" << endl;
    // Generate and print all permutations using the next_permutation function
    do {
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
        permutationCount++;
    } while (my_next_permutation(nums)); // Continue until the function returns false
    // for (int num : nums) {
    //     cout << num << " ";
    // }
    cout << "Total permutations: " << permutationCount << endl;
    return 0;
}
