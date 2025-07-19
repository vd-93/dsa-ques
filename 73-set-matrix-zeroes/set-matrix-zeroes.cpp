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
    // void setZeroes(vector<vector<int>>& matrix) {
    //     int m = matrix.size(); // no. of rows
    //     int n = matrix[0].size(); // no. of cols
        
    //     // Vectors to mark rows and cols which we have to make 0s
    //     vector<int> rows(m, 0);
    //     vector<int> cols(n, 0);

    //     // Marking rows and columns
    //     for(int i = 0; i < m; i++) {
    //         for(int j = 0; j < n; j++) {
    //             if(matrix[i][j] == 0) {
    //                 rows[i] = 1;
    //                 cols[j] = 1;
    //             }
    //         }
    //     }

    //     // Making rows and columns 0's
    //     for(int i = 0; i < m; i++) {
    //         for(int j = 0; j < n; j++) {
    //             if(rows[i] == 1 || cols[j] == 1) {
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }
    // }

    // M-4 : Using matrix's first row and column for marking
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // separate for marking first column due to intersection of first row and column
        int col0 = 1;

        // marking rows and columns
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    // marking row
                    matrix[i][0] = 0;

                    // marking column
                    if(j == 0) {
                        col0 = 0;
                    }
                    else {
                        matrix[0][j] = 0;
                    }
                }
            }
        }

        // Setting rows and columns to 0s based on markers in 1st row and column
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Making 1st row zero if needed
        if(matrix[0][0] == 0) {
            for(int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Making 1st column zero if needed
        if(col0 == 0) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};