class Solution {
public:
    // M-1 -------------------------------- 
    // vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //     vector<vector<int>> ans;

    //     // Step 1: Sort intervals based on starting time
    //     sort(intervals.begin(), intervals.end());
    //     int n = intervals.size();

    //     // Step 2: Iterate through each interval
    //     for (int i = 0; i < n; i++) {
    //         int start = intervals[i][0]; // Starting point of current interval
    //         int end = intervals[i][1];   // Ending point of current interval

    //         // Optimization: If current interval is completely inside the last
    //         // merged interval, we skip it as it's already merged.
    //         if (!ans.empty() && end <= ans.back()[1]) {
    //             continue;
    //         }

    //         // Step 3: Try to merge overlapping intervals with the current one
    //         for (int j = i + 1; j < n; j++) {
    //             // If the next interval overlaps with the current merged interval
    //             if (intervals[j][0] <= end) {
    //                 end = max(
    //                     end,
    //                     intervals[j][1]); // Extend the merged interval's end
    //             } else {
    //                 break; // No overlap, so break out of inner loop
    //             }
    //         }

    //         // Step 4: Add the merged interval to the answer list
    //         ans.push_back({start, end});
    //     }

    //     return ans;
    // }

    // M-2: ---------------------------------
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();

        // Step 1: Sort the intervals based on starting point
        sort(intervals.begin(), intervals.end());

        // Step 2: Traverse through the sorted intervals
        for(int i = 0; i < n; i++) {
            // Case 1: If answer list is empty OR current interval does not overlap
            // with the last interval in the answer list, simply add it.
            if(ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            }
            // Case 2: Overlapping interval found
            // Merge by updating the end time of the last interval in the answer list.
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        // Step 3: Return the merged intervals
        return ans;
    }

};