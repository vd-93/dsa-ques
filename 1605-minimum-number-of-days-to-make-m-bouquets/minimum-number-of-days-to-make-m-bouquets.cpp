class Solution {
public:
    /* Helper function to check if it's possible to make 'm' bouquets
     each of size 'k' on a given 'day' */
    bool checkIfPossible(vector<int>& arr, int m, int k, int day) {
        int numOfBoq = 0; // Total bouquets we can form
        int count = 0;    // Count of consecutive flowers bloomed by 'day'

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= day) {
                // Flower has bloomed by 'day', increase the consecutive count
                count++;
            } else {
                /* Flower not bloomed — calculate how many bouquets we can form
                 with the current streak */
                numOfBoq += (count / k);
                count = 0; // Reset streak
            }
        }
        // After loop, check if any bouquets can be formed with remaining streak
        numOfBoq += (count / k);

        // Return true if we can form at least 'm' bouquets
        return numOfBoq >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowersReq = m * 1LL * k;

        // If total required flowers exceed available, it's impossible
        if (totalFlowersReq > bloomDay.size()) {
            return -1;
        }

        // Find the minimum and maximum bloom day in the array
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int day : bloomDay) {
            mini = min(mini, day);
            maxi = max(maxi, day);
        }

        // Binary search on the range of days [mini, maxi]
        int low = mini;
        int high = maxi;

        while (low <= high) {
            int mid = low + ((high - low) / 2);

            // Check if it's possible to make the bouquets on 'mid' day
            if (checkIfPossible(bloomDay, m, k, mid)) {
                // Try to find an even smaller valid day
                high = mid - 1;
            } else {
                // Not possible — increase the day
                low = mid + 1;
            }
        }

        /* 'low' will be pointing to the smallest day when it's possible to make
        the bouquets */
        return low;
    }
};
