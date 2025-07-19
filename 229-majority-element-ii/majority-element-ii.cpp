class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> freq; // num -> frequency

        // Count frequencies
        for (int num : nums) {
            freq[num]++;
        }

        // Collect elements appearing more than floor(n/3) times
        int threshold = nums.size() / 3;
        for (auto entry : freq) {
            if (entry.second > threshold) {
                ans.push_back(entry.first);
            }
        }

        return ans;
    }
};