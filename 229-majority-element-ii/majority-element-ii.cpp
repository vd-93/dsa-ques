class Solution {
public:
    // M-1: Hashing ------------------------------------
    // vector<int> majorityElement(vector<int>& nums) {
    //     vector<int> ans;
    //     unordered_map<int, int> freq; // num -> frequency

    //     // Count frequencies
    //     for (int num : nums) {
    //         freq[num]++;
    //     }

    //     // Collect elements appearing more than floor(n/3) times
    //     int threshold = nums.size() / 3;
    //     for (auto entry : freq) {
    //         if (entry.second > threshold) {
    //             ans.push_back(entry.first);
    //         }
    //     }

    //     return ans;
    // }

    // M-2: Moore's voting algo (extended) ---------------
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;

        int count1 = 0, count2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;
        int n = nums.size();

        // Phase 1: Find potential candidates
        for (int i = 0; i < n; i++) {
            if (count1 == 0 && el2 != nums[i]) {
                count1 = 1;
                el1 = nums[i];
            } else if (count2 == 0 && el1 != nums[i]) {
                count2 = 1;
                el2 = nums[i];
            } else if (nums[i] == el1) {
                count1++;
            } else if (nums[i] == el2) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        // Phase 2: Verify counts of candidates
        count1 = 0;
        count2 = 0;
        int threshold = n / 3;

        for (int i = 0; i < n; i++) {
            if (nums[i] == el1) {
                count1++;
            } else if (nums[i] == el2) {
                count2++;
            }
        }

        // Include valid candidates in the answer
        if (count1 > threshold) {
            ans.push_back(el1);
        }
        if (count2 > threshold) {
            ans.push_back(el2);
        }

        return ans;
    }
};