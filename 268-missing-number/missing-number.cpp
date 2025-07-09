class Solution {
public:
    // M-1 : (Sum or 1 to N numbers) - (array sum)
    // int missingNumber(vector<int>& nums) {
    //     int n = nums.size();
    //     int oneToNSum = n * (n + 1) / 2;

    //     int arraySum = 0;
    //     for(int i = 0; i < n; i++) {
    //         arraySum += nums[i];
    //     }

    //     return oneToNSum - arraySum;
    // }

    // M-2 : XOR
    // int missingNumber(vector<int>& nums) {
    //     int ans = 0;

    //     for(int i = 0; i < nums.size(); i++) {
    //         ans ^= i+1;
    //         ans ^= nums[i];
    //     }

    //     return ans;
    // }

    // M-3 : Binary search
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Required for binary search
        int left = 0, right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > mid) {
                // missing number is on the left
                right = mid;
            } else {
                // nums[mid] == mid, search in right half
                left = mid + 1;
            }
        }

        // left is the first index where nums[i] != i
        return left;
    }
};