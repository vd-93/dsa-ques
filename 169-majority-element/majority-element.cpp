class Solution {
public:
    // M-1 : Sorting the array and returning the mid element
    // int majorityElement(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()/2];
    // }

    // M-2 : Moore's voting algo
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = NULL;

        for(int i = 0; i < nums.size(); i++) {
            if(count == 0) {
                candidate = nums[i];
                count++;
            }

            else if(nums[i] == candidate) {
                count++;
            }

            else {
                count--;
            }
        }

        return candidate;
    }
 };