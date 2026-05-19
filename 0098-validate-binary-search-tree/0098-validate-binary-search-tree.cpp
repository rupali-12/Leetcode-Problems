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
    bool isValidBST(TreeNode* root, long mn = LONG_MIN, long mx = LONG_MAX) {
        if(root==NULL) return true;
        
        if(root->val > mn && root->val <mx){
           bool left = isValidBST(root->left, mn, root->val);
           bool right = isValidBST(root->right, root->val, mx);
           return left && right;
        }
        return false;
    }
};