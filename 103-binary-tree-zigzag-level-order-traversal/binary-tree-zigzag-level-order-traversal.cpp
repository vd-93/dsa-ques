/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Zigzag traversal is the modified version of level order traversal
        // consider it as take the first level as it is, then take the reversed next level, like this
        // reverse the alternate levels.
        
        vector<vector<int>> zigzag;
        if(!root) {
            return zigzag;
        }

        queue<TreeNode*> q;
        q.push(root);
        
        // Flag to determine whether to take current level left to right or right to left
        bool leftToRight = true;

        while(!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for(int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                
                // if leftToRight is false, start adding elements from the back,
                // so that we will get the reversed level (i.e right to left)
                int index = leftToRight ? i : (size - 1 - i);

                level[index] = temp -> val;

                if(temp -> left) {
                    q.push(temp -> left);
                }
                if(temp -> right) {
                    q.push(temp -> right);
                }
            }

            zigzag.push_back(level);
            
            // update the value of the flag
            leftToRight = !leftToRight;
        }

        return zigzag;
    }

};