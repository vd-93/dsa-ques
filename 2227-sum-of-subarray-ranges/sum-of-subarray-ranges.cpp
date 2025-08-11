class Solution {
public:
    // M-1 : Brute O(N^2)
    long long subArrayRanges(vector<int>& nums) {
        long long total = 0;

        for(int i = 0; i < nums.size(); i++) {
            int mini = nums[i];
            int maxi = nums[i];

            for(int j = i; j < nums.size(); j++) {
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);

                total += (maxi - mini); 
            }
        }
        return total;
    }
};