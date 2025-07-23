class Solution {
public:
    // M-1
    // Function to find the first occurrence of target in sorted array
    // int firstOcc(vector<int>& nums, int target) {
    //     int left = 0;
    //     int right = nums.size() - 1;

    //     // Binary search to find the leftmost (first) occurrence
    //     while (left <= right) {
    //         int mid = left + ((right - left) / 2);

    //         if (nums[mid] >= target) {
    //             right =
    //                 mid - 1; // move left if mid is greater or equal to target
    //         } else {
    //             left = mid + 1; // move right
    //         }
    //     }

    //     // After loop, check if left is valid index and matches target
    //     if (left == nums.size() || nums[left] != target) {
    //         return -1; // target not found
    //     }

    //     return left; // first occurrence index
    // }

    // // Function to find the last occurrence of target in sorted array
    // int lastOcc(vector<int>& nums, int target) {
    //     int left = 0;
    //     int right = nums.size() - 1;

    //     // Binary search to find the rightmost (last) occurrence
    //     while (left <= right) {
    //         int mid = left + ((right - left) / 2);

    //         if (nums[mid] <= target) {
    //             left = mid + 1; // move right if mid is less or equal to target
    //         } else {
    //             right = mid - 1; // move left
    //         }
    //     }

    //     // After loop, check if right is a valid index and matches target
    //     if (right == -1 || nums[right] != target) {
    //         return -1; // target not found
    //     }

    //     return right; // last occurrence index
    // }

    // vector<int> searchRange(vector<int>& nums, int target) {
    //     int firstOccurance = firstOcc(nums, target);
    //     int lastOccurance = lastOcc(nums, target);

    //     return {firstOccurance, lastOccurance};
    // }


    // M-2 ----------------------------------
    int firstOcc(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;

        while(left <= right) {
            int mid = left + ((right - left) / 2);

            if(nums[mid] == target) {
                ans = mid;
                right = mid - 1;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }

    int lastOcc(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;

        while(left <= right) {
            int mid = left + ((right - left) / 2);

            if(nums[mid] == target) {
                ans = mid;
                left = mid + 1;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOcc(nums, target), lastOcc(nums, target)};
    }
};