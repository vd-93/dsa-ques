class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        // If the array has only one element, return it
        if (n == 1)
            return nums[0];

        // Check if the first element is the unique one
        if (nums[0] != nums[1])
            return nums[0];

        // Check if the last element is the unique one
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        // Set binary search bounds (excluding already-checked boundaries)
        int left = 1;
        int right = n - 2;

        while (left <= right) {
            int mid = left + ((right - left) / 2); // Prevent overflow

            // If mid is the unique element (not equal to neighbors), return it
            if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            /**
            * Logic:
            * - Before the single element, pairs start at even indices (0, 2, 4, ...)
            * - After the single element, pairs start at odd indices (1, 3, 5, ...)
            * So based on whether the index is even/odd and how it's paired,
            * we decide which side to continue the search on.
            */

            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
                (mid % 2 == 1 && nums[mid - 1] == nums[mid])) {
                // Unique element lies to the right
                left = mid + 1;
            } else {
                // Unique element lies to the left
                right = mid - 1;
            }
        }

        // Should never reach here for valid input (since a unique element is guaranteed)
        return -1;
    }

};