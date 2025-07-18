class Solution {
public:
    // M-1 Brute
    // TC: O(n^2) -> TLE
    // int maxSubArray(vector<int>& nums) {

    //     int ans = INT_MIN;
    //     for (int i = 0; i < nums.size(); i++) {
    //         int sum = 0;
    //         for (int j = i; j < nums.size(); j++) {
    //             sum += nums[j];
    //             ans = max(ans, sum);
    //         }
    //     }
    //     return ans;
    // }

    // M-2 Optimal (Kadane's algo)
    // TC: O(N)
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;
        vector<int> subarray;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans = max(ans, sum);

            // Not carrying the negative sum forward
            if (sum < 0) {
                sum = 0;
            }
        }

        return ans;
    }

    // Additional --------------------
    // if we have to return the subarray with max sum
    // int maxSubArray(vector<int>& nums) {

    //     int ans = nums[0];
    //     int sum = 0;
    //     int start = 0, end = 0, tempStart = 0;

    //     for (int i = 0; i < nums.size(); i++) {
    //         sum += nums[i];

    //         if (sum > ans) {
    //             ans = sum;
    //             start = tempStart;
    //             end = i;
    //         }

    //         if (sum < 0) {
    //             sum = 0;
    //             tempStart = i + 1;
    //         }
    //     }

    //     cout << "startInd: " << start << ", endInd: " << end << endl;
    //     return ans;
    // }
};