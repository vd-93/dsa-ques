// Example for dry run
// [100, 101, 102, 100, 101, 4, 3, 2, 3, 2, 1, 1, 1, 2]

class Solution {
public:
    // M-1 :
    // O(NlogN) + O(N)
    // int longestConsecutive(vector<int>& nums) {
    //     // Stores the last unique number in the sequence
    //     int lastSmall = INT_MIN;

    //     int count = 0, ans = 0;

    //     sort(nums.begin(), nums.end());

    //     for(int i = 0; i < nums.size(); i++) {
    //         // If current number extends the consecutive sequence
    //         if((nums[i] - 1) == lastSmall) {
    //             count++;
    //             lastSmall = nums[i];
    //         }
    //         // If current number is unique but doesn't extend the consecutive
    //         sequence else if(nums[i] != lastSmall) {
    //             // Resetting the count
    //             count = 1;
    //             lastSmall = nums[i];
    //         }

    //         ans = max(count, ans);
    //     }

    //     return ans;
    // }

    // M-2: using unordered set
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st; // To store unique elements for O(1) lookups
        int count = 0; 
        int ans = 0; 

        // Step 1: Insert all elements into the unordered_set
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        // Step 2: Traverse each unique element in the set
        for (int num : st) {

            // Check if current num is the potential starting point of a
            // sequence i.e., num - 1 is not present, so num could be sequence's
            // smallest element
            if (st.find(num - 1) == st.end()) {
                int x = num; // Starting element of current sequence
                count = 1;   // Initialize sequence length to 1

                // Count how long the consecutive sequence extends from num
                while (st.find(x + 1) != st.end()) {
                    count++;
                    x++; 
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};