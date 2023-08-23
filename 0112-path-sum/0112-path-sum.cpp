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

    bool hasPathSum(TreeNode* root, int targetSum) {
       if(!root){
           return false;
       }
        int sum=0;
        sum+= root->val;
        if(sum==targetSum && root->left==NULL && root->right==NULL){
            return true;
        }
        return hasPathSum(root->left, targetSum-sum) || hasPathSum(root->right, targetSum-sum);
    }
};