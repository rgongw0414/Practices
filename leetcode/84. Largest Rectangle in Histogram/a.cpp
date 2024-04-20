class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // find the left/right bound of each rec of heights[i]
        int n = heights.size();
        stack<int> s; 
        vector<int> left_bound(n,0),right_bound(n,n); 
        for(int i=0;i<n;i++) {
            // find the idx that heights[i] can not extend left, which is its rec left bound 
            while(!s.empty() && heights[i]<=heights[s.top()])  s.pop();
            // *** after poping, the top element idx must be the idx of the rec that stop heights[i] from extending left ***
            if(s.empty())  left_bound[i]=0; // it means that current rec can extend all the way to idx 0.
            else  left_bound[i] = s.top()+1;
			
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1; i>=0; i--)  {
            while(!s.empty() && heights[i]<=heights[s.top()])  s.pop();
            // *** after poping, the top element idx must be the idx of the rec that stop heights[i] from extending right ***
            if(s.empty()) right_bound[i] = n-1; // it means that current rec can extend all the way to idx n-1.
            else  right_bound[i] = s.top()-1;
            s.push(i);
        }
        int maxi = 0, area;
        for(int i=0; i<n; i++) {
            area = (right_bound[i]-left_bound[i]+1)*heights[i];
            maxi = max(maxi, area);
        }
        return maxi; 
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // find the left/right bound of each rec of heights[i]
        int n = heights.size();
        stack<int> s; 
        vector<int> left_bound(n,0),right_bound(n,n); 
        for(int i=0;i<n;i++) {
            // find the idx that heights[i] can not extend left, which is its rec left bound 
            while(!s.empty() && heights[i]<=heights[s.top()])  s.pop();
            if(s.empty())  left_bound[i]=0; 
            else  left_bound[i] = s.top()+1;
			
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1; i>=0; i--)  {
            while(!s.empty() && heights[i]<=heights[s.top()])  s.pop();
            if(s.empty()) right_bound[i] = n-1;
            else  right_bound[i] = s.top()-1;
            s.push(i);
        }
        int maxi = 0, area;
        for(int i=0; i<n; i++) {
            area = (right_bound[i]-left_bound[i]+1)*heights[i];
            maxi = max(maxi, area);
        }
        return maxi; 
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<pair<int, int>> stk; // (start idx of this rec, height)
        stk.emplace(make_pair(0, heights[0]));
        for (int i = 1; i < n; i++) {
            int start = i;
            while (stk.top().second > heights[i]) {
                // the top rec can not extend right anymore, on the other hand, it mean the rec can grow left.
                start = stk.top().first; // update the start idx of this rec, because it can grow left.
                auto h = stk.top().second;
                int area = h * (i-start); // includes area = h * 1
                ans = max(ans, area);
                stk.pop();
                if (stk.empty()) break;
            }
            // the start idx of current rec has been updated to its left most extendable idx by the loop above
            stk.emplace(make_pair(start, heights[i])); 
        }
        while (!stk.empty()) {
            // the remaining recs are those can extend from its start all the way to the end.
            auto start = stk.top().first;
            auto h = stk.top().second;
            int area = h * (n-start);
            ans = max(ans, area);
            stk.pop();
        }
        return ans;
    }
};