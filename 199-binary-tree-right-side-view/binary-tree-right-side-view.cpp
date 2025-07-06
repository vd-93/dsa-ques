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
    // M-1 using iterative level order traversal -----------------------------
    // vector<int> rightSideView(TreeNode* root) {
    //     vector<int> ans;

    //     if (!root) {
    //         return ans;
    //     }

    //     // map<horizontal level(y), node's value)
    //     map<int, int> mp;

    //     // queue<{node, horizontal level(y)}
    //     queue<pair<TreeNode*, int>> q;

    //     q.push({root, 0});

    //     while (!q.empty()) {
    //         auto p = q.front();
    //         q.pop();

    //         TreeNode* node = p.first;
    //         int y = p.second;

    //         /* As we are doing level order traversal, hence eventually at the
    //         end we will have the right most node for each horizontal level, as
    //         in level order we consider nodes from left to right*/
    //         mp[y] = node->val;

    //         if (node->left) {
    //             q.push({node->left, y + 1});
    //         }
    //         if (node->right) {
    //             q.push({node->right, y + 1});
    //         }
    //     }

    //     for (auto it : mp) {
    //         ans.push_back(it.second);
    //     }

    //     return ans;
    // }

    // M-2-----------------------------------------------------------------------
    // We are doing reversend preorder traversal (Root Right Left)
    void getRightSideView(TreeNode* node, int level, vector<int>& ans) {
        if (!node) {
            return;
        }

        // This means that we are visiting this level for the first time
        // hence add it to our ans vector as this has to be the right most node
        // of this level
        if (level == ans.size()) {
            ans.push_back(node->val);
        }

        if (node->right) {
            getRightSideView(node->right, level + 1, ans);
        }
        if (node->left) {
            getRightSideView(node->left, level + 1, ans);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        getRightSideView(root, 0, ans);

        return ans;
    }
};