class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // binary search, more efficient, but very tricky dealing with edge cases
        // C++ round up negative integer division, unlike round down as python 

        int n1 = nums1.size(), n2 = nums2.size();
        int half = (n1 + n2) / 2;
        if(n2 < n1) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int l = 0;
        int r = n1 - 1;
        while(true) {
            // floor((double)(n)/2): instead round up negative value, round down like python
            int mid1 = l + floor((double)(r-l)/2); // A Mid, round down instead of rounding towards 0
            int mid2 = half - mid1 - 2;      // B Mid
            int Aleft = mid1 >= 0 ? nums1[mid1] : INT_MIN;
            int Aright = (mid1 + 1) < n1 ? nums1[mid1 + 1] : INT_MAX;
            int Bleft = mid2 >= 0 ? nums2[mid2] : INT_MIN;
            int Bright = (mid2 + 1) < n2 ? nums2[mid2 + 1] : INT_MAX;
            
            // partition is correct
            if(Aleft <= Bright && Bleft <= Aright) {
                // Odd
                if((n1 + n2) % 2) {
                    return min(Aright, Bright);
                }
                
                // Even
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            }
            else if(Aleft > Bright) {
                r = mid1 - 1;
            }
            else {
                l = mid1 + 1;
            }
        }
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // two pointers: O(m+n)
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0;
        int half = (n1 + n2) / 2;
        int prev, cur;
        int cnt = 0;
        while (cnt++ <= half) {
            prev = cur;
            if (i >= n1) {
                cur = nums2[j++];
            }
            else if (j >= n2) {
                cur = nums1[i++];
            }
            else if (nums1[i] <= nums2[j]) cur = nums1[i++];
            else cur = nums2[j++];
        }
        // cnt == half + 1
        double ans;
        if ((n1+n2)%2 == 0) {
            ans = ((double)prev+(double)cur) / 2;
        }
        else {
            ans = cur;
        }
        return ans;
    }
};