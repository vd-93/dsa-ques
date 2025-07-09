class Solution {
public:
    // M-1---------------------------------------
    // void rotate(vector<int>& nums, int k) {

    //     int size = nums.size();
    //     vector<int>nums2(size);

    //     for(int i = 0; i < size; i++) {
    //         nums2[(i+k) % size] = nums[i];
    //     }
    //     nums = nums2;
    // }

    // M-2 --------------------------------------
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + (k % nums.size()));
        reverse(nums.begin() + (k % nums.size()), nums.end());
    }
};