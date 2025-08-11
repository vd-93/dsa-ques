class Solution {
public:
    // M-2 Optimal
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st; // Stack to store indices of increasing bar heights
        int ans = 0; 

        // Iterate through all bars
        for (int i = 0; i < n; i++) {
            // Maintain increasing stack; pop if current bar is smaller
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int barHt =
                    heights[st.top()]; // Height of the bar to be processed
                st.pop();              // Pop the bar as we found its NSE

                int nse = i; // NSE is current index
                int pse =
                    st.empty() ? -1 : st.top(); // PSE is new top or -1 if empty

                int area = (nse - pse - 1) * barHt; // Width = NSE - PSE - 1
                ans = max(ans, area);               // Update max area
            }
            st.push(i); // Push current index to stack
        }

        // Process remaining bars in the stack (no NSE found for them)
        while (!st.empty()) {
            int barHt = heights[st.top()];
            st.pop();

            int nse = n; // NSE is beyond last index
            int pse = st.empty() ? -1 : st.top();

            int area = (nse - pse - 1) * barHt;
            ans = max(ans, area);
        }

        return ans;
    }

    /* M-1
    Traverse the heights array
        the maximum area of rectangle containing the curr bar will be
            (nse - pse - 1) * heights[i]
    */

    // NOTE: we are storing indecies in nse and pse and not the actual elements
    // vector<int> getPSE(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> pse(n);
    //     stack<int> st;

    //     for(int i = 0; i < n; i++) {
    //         while(!st.empty() && nums[st.top()] >= nums[i]) {
    //             st.pop();
    //         }

    //         pse[i] = st.empty() ? -1 : st.top();

    //         st.push(i);
    //     }

    //     return pse;
    // }

    // vector<int> getNSE(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> nse(n);
    //     stack<int> st;

    //     for(int i = n - 1; i >= 0; i--) {
    //         while(!st.empty() && nums[st.top()] >= nums[i]) {
    //             st.pop();
    //         }

    //         nse[i] = st.empty() ? n : st.top();

    //         st.push(i);
    //     }

    //     return nse;
    // }

    // int largestRectangleArea(vector<int>& heights) {
    //     vector<int> pse = getPSE(heights);
    //     vector<int> nse = getNSE(heights);

    //     int ans = 0;

    //     for(int i = 0; i < heights.size(); i++) {
    //         int left = i - pse[i];
    //         int right = nse[i] - i;

    //         int area = (left + right - 1) * heights[i];

    //         ans = max(ans, area);
    //     }

    //     return ans;
    // }
};