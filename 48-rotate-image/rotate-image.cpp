class Solution {
public:
    // M-2 BRUTE (extra space) --------------------
    // void rotate(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     vector<vector<int>> ans(m, vector<int>(m));

    //     // 1st row become last col of ans matrix
    //     // 2nd row becomes 2nd last col of ans matrix
    //     // put elements of (i)th row in (m-i-1)th column
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < m; j++) {
    //             ans[j][m - i - 1] = matrix[i][j];
    //         }
    //     }
    //     matrix = ans;
    // }

    // M-1 OPTIMAL
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        // transpose (to take transpose, only traverse the lower part of
        // diagonal or upper part of diagonal and swap the elements)
        // here we are traversing lower part
        for(int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // revesre the rows
        for (int i = 0; i < m; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};