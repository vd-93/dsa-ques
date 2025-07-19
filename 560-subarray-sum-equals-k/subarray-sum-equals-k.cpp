class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Map to store count of prefix sums encountered so far
        // Key: prefixSum, Value: number of times this prefixSum has occurred
        map<int, int> prefixSumCount;

        prefixSumCount[0] = 1; // To handle subarrays starting from index 0

        int ans = 0;       // Final count of subarrays with sum equal to k
        int prefixSum = 0; // Running prefix sum

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i]; // Update running prefix sum

            // Check if there exists a prefix sum such that: 
            // current prefixSum - earlier prefixSum = k
            // => earlier prefixSum = prefixSum - k
            // i.e to increase the count there must exist (current prefixSum - k) value in map 
            if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
                ans += prefixSumCount[prefixSum - k]; // Add the count of such prefix sums
            }

            // Store/update the current prefix sum in the map
            prefixSumCount[prefixSum]++;
        }

        return ans; // Return total number of subarrays with sum equal to k
    }
};
