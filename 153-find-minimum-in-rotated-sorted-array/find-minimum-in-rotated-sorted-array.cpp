class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while(left < right) {
            int mid = left + ((right - left) / 2);
            
            if(nums[left] > nums[right]) {
                /* both the nums[left] & nums[mid] are greater than nums[right]
                that means minimum lies in right side part of the mid
                */
                if(nums[mid] > nums[right]) {
                    left = mid + 1;
                }
                /* if nums[mid] is not greater than nums[right] that means 
                there is no guarantee that the left part of mid will not contain 
                the minimum element so we are just eliminating the nums[left] 
                */
                else {
                    left++;
                }
            }
            else {
                right = mid - 1;
            }
        }

        return nums[left];
    }
};