/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case: if root is null or matches one of the targets
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        // search left and right subtrees
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        // if both sides return non-null, current node is the LCA
        if (leftLCA && rightLCA) {
            return root;
        }

        // otherwise, propagate non-null result upwards
        return leftLCA != nullptr ? leftLCA : rightLCA;
    }
};