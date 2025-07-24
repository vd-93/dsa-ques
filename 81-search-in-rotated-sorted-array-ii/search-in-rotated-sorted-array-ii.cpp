class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        // Binary search with duplicate handling in a rotated sorted array
        while (left <= right) {
            int mid = left + ((right - left) / 2);

            // If mid is the target, return true
            if (nums[mid] == target) {
                return true;
            }

            // If duplicates make it hard to determine which half is sorted
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
                continue; // Skip duplicates from both ends
            }

            // Left half is sorted
            if (nums[left] <= nums[mid]) {
                // If target lies in the left half
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // Right half is sorted
            else {
                // If target lies in the right half
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        // Target not found
        return false;
    }
};