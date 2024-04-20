class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long n = piles.size();
        long ans = LONG_MAX;
        long l = 1, r = *max_element(piles.begin(), piles.end());
        // possible value for k: [1, max(piles)]
        // binary searching minimun k in [1, max(piles)]
        while (l <= r) {
            long k = l + (r-l)/2;
            long hrs = 0;
            for (int p: piles) {
                hrs += (long)ceil((double)p/(double)k);
                if (hrs > h) break;
            }
            if (hrs <= h) {
                ans = min(ans, k);
                r = k - 1;
            }
            else l = k + 1;            
        }
        return ans;
    }
};

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // brute-force
        long n = piles.size();
        // h >= n
        // if h == n, then k = max(piles) (0+1)-th max
        // if h > n, then k >= (h-n)-th max of piles
        // sort(piles.begin(), piles.end());
        long k = 1;
        long s = 0;
        for (int p: piles) s += (long)p;
        while (true) {
            if (s <= k*(long)h) {
                int cnt = 0;
                for (int p: piles) {
                    cnt += (int)ceil(((double)p/(double)k));
                    if (cnt > h) break;
                }
                if (cnt <= h) {
                    break;
                }
            }
            k++;
        }
        return k;
    }
};