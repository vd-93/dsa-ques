class Solution {
public:
    // void sortColors(vector<int>& nums) {
        // M-1 counting sort
        // int count0 = 0, count1 = 0, count2 = 0;

        // for(int i = 0; i < nums.size(); i++) {
        //     if(nums[i] == 0) count0++;
        //     else if(nums[i] == 1) count1++;
        //     else count2++;
        // }

        // for(int i = 0; i < count0; i++) {
        //     nums[i] = 0;
        // }
        // for(int i = count0; i < count0 + count1; i++) {
        //     nums[i] = 1;
        // }
        // for(int i = count0 + count1; i < nums.size(); i++) {
        //     nums[i] = 2;
        // }
    // }

    // M-2 : Dutch National Flag Algo
    // [0 -> (low - 1)] = 0 , low's left side will have all 0's
    // [low -> high] = 1  OR [low -> (mid - 1)] = 1
    // [(high+1) -> (size - 1)] = 2 , high's right side will have all 2's
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid = 0;

        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }

            else if(nums[mid] == 1) {
                mid++;
            }

            // nums[mid] == 2
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};