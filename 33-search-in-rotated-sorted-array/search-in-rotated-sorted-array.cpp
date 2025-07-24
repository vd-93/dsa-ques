class Solution {
public:
    /* M-1 : First finding pivot index (ith index where a[i] > a[i-1]),
    then deciding in which part of the array to find the target
    [0, pivot] OR [pivot + 1, n - 1]
    */
    int findPivotIndex(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            int mid = left + ((right - left) / 2);

            if(nums[mid] >= nums[0]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return right;
    }

    int binarySearch(vector<int>& nums, int target, int left, int right) {
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

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivotIndex = findPivotIndex(nums);
        int left;
        int right;

        if(target > nums[pivotIndex]) {
            return -1;
        }

        if(target >= nums[0] && target <= nums[pivotIndex]) {
            left = 0;
            right = pivotIndex;

            return binarySearch(nums, target, left, right);
        }

        return binarySearch(nums, target, pivotIndex + 1, nums.size() - 1);
    }
};