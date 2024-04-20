class Solution {
public:
    int trap(vector<int>& height) {
        // Time: O(N), space: O(1) which is optimized with two pointers        
        // water in each idx = min(max height of i's lhs, max height of i's rhs) - height[i]
        /*
        *** not intuitive because of two pointers *** 
        *** key idea: utilize min(maxL, maxR) to move the two pointers *** 
        */
        int n = height.size();
        int maxL = height[0], maxR = height[n-1]; // current found maxL/R of a certain point
        int i = 0, j = n-1;
        int ans = 0;
        while (i < j) { // iterate till i == j
            if (maxL <= maxR) {  // *** this is the trick makes two pointers work, which is utilizing min(maxL, maxR) ***
                i++;
                int water = maxL - height[i];
                if (water > 0) ans += water;
                maxL = max(maxL, height[i]);
            }
            else { // *** this is the trick makes two pointers work ***
                j--;
                int water = maxR - height[j];
                if (water > 0) ans += water;
                maxR = max(maxR, height[j]);
            }
        }
        return ans;
    }
};


class Solution {
public:
    int trap(vector<int>& height) {
        // build a 2-d array wrt the graph
        int mh = 0;
        for (auto const& h: height) mh = std::max(mh, h);
        int ans = 0;
        for (int j = 0; j < mh; j++) {
            int l = 0;
            while (height[l]-j <= 0 and l < height.size()-1) l++;
            int r = l+1;
            while (l < r and l < height.size()-1 and r < height.size()) {
                if (height[l]-j > 0 and height[r]-j > 0) {
                    if (r-l-1 == 0) { // two blocks are adj
                        l = r;
                        r++;
                    }
                    else if (r-l-1 > 0) { // at least one unit of water
                        ans += (r-l-1);
                        l = r;
                        r = l+1;                        
                    }
                }
                else if (height[l]-j > 0 and height[r]-j <= 0) {
                    while (r < height.size() and height[r]-j <= 0) r++;
                }
                else r++;
            }
        }
        return ans;
    }
};