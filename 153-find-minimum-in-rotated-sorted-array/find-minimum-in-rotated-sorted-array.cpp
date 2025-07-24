class Solution {
public:
    // M-2 (prefer)
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = INT_MAX;

        while (left <= right) {
            int mid = left + ((right - left) / 2); 

            // Case 1: The current subarray is already sorted
            // So, the smallest element is at index `left`
            if (nums[left] <= nums[right]) {
                // Update answer with the smallest seen so far
                ans = min(ans, nums[left]); 
                break; // No need to search further
            }

            // Case 2: Left half [left...mid] is sorted
            if (nums[left] <= nums[mid]) {
                // Update answer with the minimum of the sorted half
                ans = min(ans, nums[left]); 
                left = mid + 1; // Move to the right half
            }
            // Case 3: Right half [mid...right] is sorted
            else {
                // Update answer with the minimum of the sorted half
                ans = min(ans, nums[mid]); 
                right = mid - 1; // Move to the left half
            }
        }

        return ans;
    }


    // ---------------------------------------
    // M-1 : (Do not prefer)
    // int findMin(vector<int>& nums) {
    //     int left = 0;
    //     int right = nums.size() - 1;

    //     while(left < right) {
    //         int mid = left + ((right - left) / 2);
            
    //         if(nums[left] > nums[right]) {
    //             /* both the nums[left] & nums[mid] are greater than nums[right]
    //             that means minimum lies in right side part of the mid
    //             */
    //             if(nums[mid] > nums[right]) {
    //                 left = mid + 1;
    //             }
    //             /* if nums[mid] is not greater than nums[right] that means 
    //             there is no guarantee that the left part of mid will not contain 
    //             the minimum element so we are just eliminating the nums[left] 
    //             */
    //             else {
    //                 left++;
    //             }
    //         }
    //         else {
    //             right = mid - 1;
    //         }
    //     }

    //     return nums[left];
    // }
};