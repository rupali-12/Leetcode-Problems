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
    int solve(TreeNode*root, int sum){
        if(root==NULL || sum<-1000000007) return 0;
        int res=0;
        if(root->val==sum){
            res++;
        }
        res+= solve(root->left, sum-root->val);
        res+= solve(root->right, sum-root->val);
        return res;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }
        return solve(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};