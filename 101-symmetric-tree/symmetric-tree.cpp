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
    // p and q are the current nodes of the left and right subtree of the root
    bool isMrrorImage(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) {
            return p == q;
        }

        /* if we go to the left of left subtree, go to the right of right subtree
          If we go the right of left subtree, go to the left of right subtree
         */
        return (p->val == q->val) && isMrrorImage(p->left, q->right) &&
               isMrrorImage(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isMrrorImage(root->left, root->right);
    }
};