class Solution {
public:
    int firstOcc(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            int mid = left + ((right - left) / 2);

            if(nums[mid] >= target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        if(left == nums.size() || nums[left] != target) {
            return -1;
        }

        return left;
    }

    int lastOcc(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            int mid = left + ((right - left) / 2);

            if(nums[mid] <= target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        if (right == nums.size() || right == -1 || nums[right] != target) {
            return -1;
        }

        return right;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOccurance = firstOcc(nums, target);
        int lastOccurance = lastOcc(nums, target);

        return {firstOccurance, lastOccurance};
    }
};