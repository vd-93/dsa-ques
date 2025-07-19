class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>
            ans; // Final result to store all rows of Pascal's Triangle

        for (int i = 0; i < numRows; i++) {
            vector<int> row; // Vector to store the current row

            for (int j = 0; j <= i; j++) {
                // First and last elements of each row are always 1 
                // This also handles the cases of first two rows of pascal triangle ([1], [1,1])
                if (j == 0 || j == i) {
                    row.push_back(1);
                } else {
                    // Element at position (i, j) is the sum of two elements
                    // from the previous row: ans[i-1][j-1] (element above-left)
                    // + ans[i-1][j] (element directly above)
                    row.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
                }
            }

            // Add the completed row to the final answer
            ans.push_back(row);
        }

        return ans;
    }
};