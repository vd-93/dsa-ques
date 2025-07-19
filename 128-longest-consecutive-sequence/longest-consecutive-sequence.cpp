// Example for dry run
// [100, 101, 102, 100, 101, 4, 3, 2, 3, 2, 1, 1, 1, 2]

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Stores the last unique number in the sequence
        int lastSmall = INT_MIN;

        int count = 0, ans = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            // If current number extends the consecutive sequence
            if((nums[i] - 1) == lastSmall) {
                count++;
                lastSmall = nums[i];
            }
            // If current number is unique but doesn't extend the consecutive sequence
            else if(nums[i] != lastSmall) {
                // Resetting the count
                count = 1;
                lastSmall = nums[i];
            }

            ans = max(count, ans);
        }

        return ans;
    }
};