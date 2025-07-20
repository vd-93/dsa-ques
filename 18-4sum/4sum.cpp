class Solution {
public:
    // M-1: using lookup hashset (3 nested loops)
    // vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //     set<vector<int>> st;
    //     int n = nums.size();

    //     for(int i = 0; i < n-3; i++) {
    //         for(int j = i + 1; j < n - 2; j++) {
    //             // to store elements between j & k
    //             unordered_set<long long> hashset;

    //             for(int k = j+1; k < n; k++) {
    //                 long long sum = nums[i] + nums[j];
    //                 sum += nums[k];

    //                 long long fourth = target - sum;

    //                 // fourth present in hashet
    //                 if(hashset.find(fourth) != hashset.end()) {
    //                     vector<int> temp = {nums[i], nums[j], nums[k],
    //                     (int)fourth}; sort(temp.begin(), temp.end());

    //                     st.insert(temp);
    //                 }
    //                 hashset.insert(nums[k]);
    //             }
    //         }
    //     }

    //     vector<vector<int>> ans(st.begin(), st.end());
    //     return ans;
    // }

    // M-2: --------------------------------------------------------
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();

        // Step 1: Sort the array to apply two-pointer technique easily
        sort(nums.begin(), nums.end());

        // Outer loop: fix the first element
        for (int i = 0; i < n - 3; i++) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Second loop: fix the second element
            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicates for the second element
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // Two pointers for the remaining two elements
                int k = j + 1;
                int l = n - 1;

                while (k < l) {
                    // Use long long to prevent integer overflow during summation
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target) {
                        // Found a valid quadruplet
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;

                        // Skip duplicates after finding a valid quadruplet
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    } else if (sum < target) {
                        k++;
                    } else { // sum > target
                        l--;
                    }
                }
            }
        }

        return ans;
    }
};