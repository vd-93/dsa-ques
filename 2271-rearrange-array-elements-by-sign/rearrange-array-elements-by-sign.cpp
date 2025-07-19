class Solution {
public:
    // M-1 : First separating the pos and neg and then combining them
    // vector<int> rearrangeArray(vector<int>& nums) {
    //     vector<int> ans;
    //     vector<int> pos;
    //     vector<int> neg;

    //     for(int i = 0; i < nums.size(); i++) {
    //         if(nums[i] > 0) {
    //             pos.push_back(nums[i]);
    //         }
    //         else {
    //             neg.push_back(nums[i]);
    //         }
    //     }

    //     for(int i = 0; i < pos.size(); i++) {
    //         ans.push_back(pos[i]);
    //         ans.push_back(neg[i]);
    //     }

    //     return ans;
    // }

    // M-2: Optimal
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int posInd = 0, negInd = 1;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                ans[posInd] = nums[i];
                posInd += 2;
            }
            else if(nums[i] < 0) {
                ans[negInd] = nums[i];
                negInd += 2;
            }
        }

        return ans;
    }
};