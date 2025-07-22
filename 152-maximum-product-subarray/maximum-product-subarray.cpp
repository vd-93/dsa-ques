class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1, suffix = 1;
        int ans = INT_MIN;  // Stores the final maximum product

        // Traverse the array from both left-to-right (prefix) and right-to-left (suffix)
        for(int i = 0; i < n; i++) {
            // Reset prefix/suffix product to 1 if it becomes 0,
            // because multiplying further elements with 0 would always give 0.
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            // Calculate prefix product (left to right)
            prefix = prefix * nums[i];

            // Calculate suffix product (right to left)
            suffix = suffix * nums[n - i - 1];

            // Take the maximum among prefix, suffix, and previous maximum
            ans = max(ans, max(prefix, suffix));
        }

        // Return the maximum product of any subarray found
        return ans;
    }

};