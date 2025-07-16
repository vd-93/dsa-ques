class Solution {
public:
    // M-1 : Brute force ------------------------------------------
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     int flag = false;

    //     for(int i = 0; i < nums.size()-1; i++) {
    //         for(int j = i+1; j < nums.size(); j++) {
    //             if(target == nums[i] + nums[j]) {
    //                 return {i, j};
    //             }
    //         }
    //     }
    //     return {};
    // }

    // M-2 : hashing -------------------------------------------
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp; // map[element] -> index

        for(int i = 0; i < nums.size(); i++) {
            if(mp.find(target - nums[i]) != mp.end()) {
                return {mp[target - nums[i]], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};