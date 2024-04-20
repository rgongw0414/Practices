class Solution {
public:

    /*
    edge case: height[i] == height[j]
    idea: neither i++ or j-- will create bigger area, because the area is limited by current left and right height.
          areas b/w (i+1, j) or (i, j-1) are limited by i and j no matter how high i+1 or j-1 is.
    */
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int ans = 0;
        while (i < j) {
            int area = min(height[i], height[j]) * (j-i); // best area found so far
            ans = max(ans, area);
            if (height[i] < height[j]) {
                i++; // move the smaller one in order to potentially create bigger area
            }
            else j--;
        }
        return ans;
    }
};
