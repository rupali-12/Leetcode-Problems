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
    bool isIdentical(TreeNode* root, TreeNode* subRoot){
         if(root==NULL && subRoot==NULL){
            return true;
        }
         if(root==NULL || subRoot==NULL){
            return false;
        }
        if(root->val!=subRoot->val){
            return false;
        }
        bool leftAns = isIdentical(root->left, subRoot->left);
        bool rightAns = isIdentical(root->right, subRoot->right);
        return leftAns && rightAns;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       if(!root){
           return false;
       }
        if(isIdentical(root, subRoot)){
            return true;
        }
        bool lAns = isSubtree(root->left, subRoot);
        bool rAns = isSubtree(root->right, subRoot);
        return lAns || rAns;
    }
};