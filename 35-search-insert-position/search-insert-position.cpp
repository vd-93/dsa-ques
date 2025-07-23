class Solution {
public:
    /* In short we are finding lower bound here, if the target is 
    present in the array, returning its index, if not returning the smallest index 
    where the element is greater than the target
    */
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            int mid = left + ((right - left) / 2);

            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};