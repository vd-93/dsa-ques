class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int size = nums.size();

        while(j < size) {
            while(j < size && nums[i] == nums[j]) {
                j++;
            }
            if(j < size) {
                nums[i+1] = nums[j];
                i++;
                j++;
            }
        }

        return i + 1;
    }

    // int removeDuplicates(vector<int>& nums) {
    //     int i = 0; 
    //     int j = 1;
    //     int size = nums.size();

    //     for(int j = 1; j < size; j++) {
    //         if(nums[i] == nums[j]) {
    //             continue;
    //         }
    //         else {
    //             swap(nums[++i], nums[j]);
    //         }
    //     }
    //     return i + 1;
    // }
};