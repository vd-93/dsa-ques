class Solution {
public:
    // M-1: using lookup hashset (3 nested loops)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        int n = nums.size();

        for(int i = 0; i < n-3; i++) {
            for(int j = i + 1; j < n - 2; j++) {
                // to store elements between j & k
                unordered_set<long long> hashset;

                for(int k = j+1; k < n; k++) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];

                    long long fourth = target - sum;

                    // fourth present in hashet
                    if(hashset.find(fourth) != hashset.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(temp.begin(), temp.end());

                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};