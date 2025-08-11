class Solution {
public:
    /* M-1
    Traverse the heights array
        the maximum area of rectangle containing the curr bar will be
            (nse - pse - 1) * heights[i]
    */
    
    // NOTE: we are storing indecies in nse and pse and not the actual elements
    vector<int> getPSE(vector<int>& nums) {
        int n = nums.size();
        vector<int> pse(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return pse;
    }

    vector<int> getNSE(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return nse;
    }


    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse = getPSE(heights);
        vector<int> nse = getNSE(heights);

        int ans = 0;

        for(int i = 0; i < heights.size(); i++) {
            int left = i - pse[i];
            int right = nse[i] - i;

            int area = (left + right - 1) * heights[i];

            ans = max(ans, area);
        }

        return ans;
    }
};