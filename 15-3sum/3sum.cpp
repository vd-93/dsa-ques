class Solution {
public:
    // M-1 : Hashing (gives TLE)
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     // To store unique triplets
    //     set<vector<int>> st;

    //     // Outer loop: pick first element one by one
    //     for (int i = 0; i < nums.size() - 2; i++) {
    //         unordered_set<int>hashset; // HashSet to store seen numbers for
    //         the current i

    //         // Inner loop: pick second element
    //         for (int j = i + 1; j < nums.size(); j++) {
    //             // Compute the required third element to make the sum zero
    //             int third = -(nums[i] + nums[j]);

    //             // If third element is found in hashset, we found a triplet
    //             if (hashset.find(third) != hashset.end()) {
    //                 vector<int> temp = {nums[i], nums[j], third};

    //                 // Sort the triplet before inserting to handle duplicate
    //                 // values in different order
    //                 sort(temp.begin(), temp.end());

    //                 st.insert(temp);
    //             } else {
    //                 // Store nums[j] in hashset to check for next potential
    //                 // pairs
    //                 hashset.insert(nums[j]);
    //             }
    //         }
    //     }

    //     vector<vector<int>> ans(st.begin(), st.end());
    //     return ans;
    // }

    // M-2: Iteration + 2 pointers ---------------------
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        // Step 1: Sort the array to enable two-pointer approach and simplify
        // duplicate handling
        sort(nums.begin(), nums.end());

        // Step 2: Iterate through the array, fixing the first element of the
        // triplet
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate first elements to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Step 3: Initialize two pointers
            int left = i + 1;  // Second element
            int right = n - 1; // Third element

            // Step 4: Find pairs using two-pointer approach
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    left++;
                } 
                else if (sum > 0) {
                    right--;
                } 
                else {
                    // Found a valid triplet
                    ans.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    // Skip duplicate second elements
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // Skip duplicate third elements
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};