class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();

        // Step 1: Find the break point
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        // If no break point, that means the array the last permutation, reverse whole array
        if(ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find next greater element to the right side of ind and swap
        for(int i = n - 1; i > ind; i--) {
            if(nums[i] > nums[ind]) {
                swap(nums[ind], nums[i]);
                break;
            }
        }

        // Step 3: Reverese the suffix
        reverse(nums.begin() + ind + 1, nums.end());
    }
};