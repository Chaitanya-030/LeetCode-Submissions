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
    int solve(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) {
            if(root->val) return 0;
            return 1;
        }

        int lt = solve(root->left);
        int rt = solve(root->right);

        if(lt) root->left = NULL;
        if(rt) root->right = NULL;

        if(!root->left && !root->right && root->val == 0) return 1;
        return 0;
    }

    TreeNode* pruneTree(TreeNode* root) {
        int ans = solve(root);
        if(ans) return NULL;
        return root;
    }
};