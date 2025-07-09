class Solution {
public:
    // void moveZeroes(vector<int>& nums) {
    //     int i = 0; 
    //     int j = 0; // for finding non zero elements to swap with ith element
    //     int n = nums.size();
    //     while(j < n) {
    //         while(j < n && nums[j] ==0) {
    //             j++;
    //         }
    //         if(j < n) {
    //             swap(nums[i], nums[j]);
    //             i++;
    //             j++;
    //         }
    //     }
    // }

    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
       }
    }
};