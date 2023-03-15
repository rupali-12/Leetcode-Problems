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
    TreeNode* deleteNode(TreeNode* root, int key) {
         if(root==NULL){
        return root;
    }
    
    if(root->val ==key){
        // 0 child
        if(root->left==NULL && root->right==NULL){
            delete(root);
            return NULL;
        }
        
        // 1 child
        if((root->left==NULL &&root->right!=NULL) || (root->left!=NULL && root->right==NULL)){
            if(root->left!=NULL){
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else{
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
        }
        
        // 2 child
        if(root->left!=NULL && root->right!=NULL){
            TreeNode* pre= root->left;
            while(pre->right!=NULL){
                pre= pre->right;
            }
           int maxValue =pre->val;
              root->val =maxValue;
              root->left = deleteNode(root->left, maxValue);
              return root;
        }
        
    }
    else if(root->val>key){
        root->left = deleteNode(root->left, key);
        return root;
    }
    else{
        root->right = deleteNode(root->right, key);
        return root;
    }
        return root;
    }
};