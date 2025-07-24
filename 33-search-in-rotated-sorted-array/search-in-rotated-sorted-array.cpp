class Solution {
public:
    /* M-2 (prefer)
    Step 1 : Checking which half of the mid is sorted (left or right)
    Step 2 : Checking if the target lies in sorted half
            If yes, then searching in the sorted half
            If no, searching in the other half
    */
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        // Binary search in rotated sorted array
        while(left <= right) {
            int mid = left + ((right - left) / 2);

            // If the mid element is the target
            if(nums[mid] == target) {
                return mid;
            }

            // Check if the left half is sorted
            else if(nums[left] <= nums[mid]) {
                // Target lies within the sorted left half
                if(nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                // Otherwise, move to the right half
                else {
                    left = mid + 1;
                }
            }

            // Otherwise, the right half must be sorted
            else {
                // Target lies within the sorted right half
                if(nums[mid] < target && target <= nums[n-1]) {
                    left = mid + 1;
                }
                // Otherwise, move to the left half
                else {
                    right = mid - 1;
                }
            }
        }

        // Target not found
        return -1;
    }

    // -----------------------------------------------------------------
    /* M-1 : (own, long method) 
    First finding pivot index (ith index where a[i] > a[i-1]),
    then deciding in which part of the array to find the target
    [0, pivot] OR [pivot + 1, n - 1]
    */
    // int findPivotIndex(vector<int>& nums) {
    //     int left = 0;
    //     int right = nums.size() - 1;

    //     while(left <= right) {
    //         int mid = left + ((right - left) / 2);

    //         if(nums[mid] >= nums[0]) {
    //             left = mid + 1;
    //         }
    //         else {
    //             right = mid - 1;
    //         }
    //     }

    //     return right;
    // }

    // int binarySearch(vector<int>& nums, int target, int left, int right) {
    //     while(left <= right) {
    //         int mid = left + ((right - left) / 2);

    //         if(nums[mid] == target) {
    //             return mid;
    //         }
    //         else if(nums[mid] < target) {
    //             left = mid + 1;
    //         }
    //         else {
    //             right = mid - 1;
    //         }
    //     }

    //     return -1;
    // }

    // int search(vector<int>& nums, int target) {
    //     int pivotIndex = findPivotIndex(nums);
    //     int left;
    //     int right;

    //     if(target > nums[pivotIndex]) {
    //         return -1;
    //     }

    //     if(target >= nums[0] && target <= nums[pivotIndex]) {
    //         left = 0;
    //         right = pivotIndex;

    //         return binarySearch(nums, target, left, right);
    //     }

    //     return binarySearch(nums, target, pivotIndex + 1, nums.size() - 1);
    // }
};