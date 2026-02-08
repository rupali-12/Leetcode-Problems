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

//  A binary tree is height-balanced if for every node,
// the height difference between its left subtree and right subtree is at most 1.
class Solution {
public:
    int height(TreeNode* root){
        if(root ==NULL) return 0;

        int left = height(root->left);
        int right = height(root->right);
        return max(left, right) +1;
    }
    bool isBalanced(TreeNode* root){
        if(root==NULL) return true;

        // check for root 
        int left = height(root->left);
        int right = height(root->right);
        if(abs(left-right)>1) return false;

        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);
        return leftAns && rightAns; 
    }
};