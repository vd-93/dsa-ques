/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution { 
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> verticalOrder;

        // nested map structure:
        // outer: column number (x coordinate)
        // inner: row number (y coordinate)
        // innermost multiset: to store multiple nodes in sorted order at same position
        map<int, map<int, multiset<int>>> nodes;

        // queue to do BFS:
        // stores {node, {column number x, row number y}}
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});  // root is at column 0, row 0

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int x = p.second.first;   // column
            int y = p.second.second;  // row

            // insert node value into map at its coordinate
            nodes[x][y].insert(node->val);

            // enqueue left child with column-1 and row+1
            if (node->left) {
                q.push({node->left, {x - 1, y + 1}});
            }
            // enqueue right child with column+1 and row+1
            if (node->right) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }

        // now build the answer from the collected nodes
        // go through columns in order
        for (auto& p : nodes) {
            vector<int> col;
            // within each column, go through rows in order
            for (auto& q : p.second) {
                // insert all node values in this row, already sorted by multiset
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            verticalOrder.push_back(col);
        }

        return verticalOrder;
    }
};