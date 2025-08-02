class Solution {
public:
    /*
    Approach:
    Binary Search Range:
    - Minimum capacity (`low`) = max(weights), because you must at least be able
    to carry the heaviest item.
    - Maximum capacity (`high`) = sum(weights), as that's the total weight if
    you ship everything in one day.

    For each mid (candidate capacity), simulate the number of days required to
    ship all packages using that capacity.
    - If the required days > given days, the capacity is too small → increase
    the capacity.
    - If the required days <= given days, try with a smaller capacity to
    minimize the answer.

    Time Complexity:
    - Binary search runs in O(log(sum(weights) - max(weights)))
    - For each capacity check, we traverse weights once: O(n)
    - So total complexity = O(n * log(sum - max))
    */

    // Helper function to compute the number of days required for a given ship capacity
    int getReqDays(vector<int>& weights, int capacity) {
        int reqDays = 1; // Start with day 1
        int wtSum = 0;

        for (int wt : weights) {
            // If adding this package exceeds capacity, use a new day
            if (wtSum + wt > capacity) {
                reqDays++; // Start new day
                wtSum = 0; // Reset weight sum
            }
            wtSum += wt;
        }

        return reqDays;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxWt = INT_MIN;
        int wtSum = 0;

        // Determine the search range for capacity
        for (int wt : weights) {
            maxWt = max(wt, maxWt); // Minimum possible capacity
            wtSum += wt;          // Maximum possible capacity
        }

        int low = maxWt, high = wtSum;

        while (low <= high) {
            int mid = low + ((high - low) / 2);

            int reqDays = getReqDays(weights, mid);

            if (reqDays > days) {
                // Too many days → need more capacity
                low = mid + 1;
            } else {
                // try with a smaller capacity to minimize the answer.
                high = mid - 1;
            }
        }

        // 'low' is the smallest valid capacity
        return low;
    }
};
