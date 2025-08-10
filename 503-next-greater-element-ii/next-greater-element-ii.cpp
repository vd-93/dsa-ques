class Solution {
public:
    // M-1 : Brute O(n^2)
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> nge(n, -1);

        for(int i = 0; i < n; i++) {
            // Iterating the circular array to find nge of current num (nums[i])
            for(int j = i + 1; j <= i + n - 1; j++) {
                int index = j % n;
                
                if(nums[index] > nums[i]) {
                    nge[i] = nums[index];
                    break;
                }
            }
        }
        return nge;
    }
};