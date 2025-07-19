class Solution {
public:
    // M-1 : First deciding which rows and cols to make zeroes and then in other loop making them zeroes
    // void setZeroes(vector<vector<int>>& matrix) {
    //     unordered_set<int> rows;
    //     unordered_set<int> cols;

    //     int m = matrix.size();
    //     int n = matrix[0].size();

    //     // Finding which rows and columns we have to make 0s
    //     for(int i = 0; i < m; i++) {
    //         for(int j = 0; j < n; j++) {
    //             if(matrix[i][j] == 0) {
    //                 rows.insert(i);
    //                 cols.insert(j);
    //             }
    //         }
    //     }

    //     // Setting the decided rows and columns to 0s
    //     for(int i = 0; i < m; i++) {
    //         for(int j = 0; j < n; j++) {
    //             if(rows.find(i) != rows.end() || cols.find(j) != cols.end()) {
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }
    // }

    // M-2: Same approach as M-1, just the way of setting 0s is slightly different
    // void setZeroes(vector<vector<int>>& matrix) {
    //     unordered_set<int> rows;
    //     unordered_set<int> cols;

    //     int m = matrix.size();
    //     int n = matrix[0].size();

    //     // Deciding which rows and cols to make 0s
    //     for(int i = 0; i < m; i++) {
    //         for(int j = 0; j < n; j++) {
    //             if(matrix[i][j] == 0) {
    //                 rows.insert(i);
    //                 cols.insert(j);
    //             }
    //         }
    //     }

    //     // Setting rows to 0
    //     for(int row : rows) {
    //         for(int j = 0; j < n; j++) {
    //             matrix[row][j] = 0;
    //         }
    //     }
        
    //     // Setting columns to 0
    //     for(int col : cols) {
    //         for(int i = 0; i < m; i++) {
    //             matrix[i][col] = 0;
    //         }
    //     }
    // }

    // M-3 : Using vectors instead of unordered_set to mark the rows and columns
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); // no. of rows
        int n = matrix[0].size(); // no. of cols

        vector<int> rows(m, 0);
        vector<int> cols(n, 0);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(rows[i] == 1 || cols[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};