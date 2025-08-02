/* Approach:
 - The answer lies between 1 and the maximum element in the array.
    (becoz, the result for maximum elem and all int greater that it will be same)
 - Use Binary Search to find the smallest such divisor.
*/
class Solution {
public:
    /* Helper function to calculate the sum of ceil(num / divisor) for each
    element Stops early if sum exceeds threshold for efficiency */
    int getResult(vector<int> nums, int threshold, int divisor) {
        int res = 0;
        for (int num : nums) {
            res += ceil((double)num / divisor);

            // Early exit if result already exceeds threshold
            if (res > threshold) {
                break;
            }
        }
        return res;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        // Step 1: Find the maximum element (upper bound for binary search)
        int maxi = INT_MIN;
        for (int num : nums) {
            maxi = max(maxi, num);
        }

        int low = 1, high = maxi;

        // Step 2: Binary search for the smallest divisor
        while (low <= high) {
            int mid = low + ((high - low) / 2);

            int result = getResult(nums, threshold, mid);

            if (result <= threshold) {
                // Mid is a valid divisor, try smaller one
                high = mid - 1;
            } else {
                // Mid is too small, try a larger divisor
                low = mid + 1;
            }
        }

        // 'low' now points to the smallest valid divisor
        return low;
    }
};
