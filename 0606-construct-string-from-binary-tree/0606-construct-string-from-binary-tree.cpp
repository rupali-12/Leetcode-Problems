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
    string solve(TreeNode* root){
        if(root==NULL) return "";
        string left="", right="";
        if(root->left==NULL){
           if(root->right!=NULL){
                left+= "()";
           }
        }
        else{
            left+="(" + to_string(root->left->val)+ solve(root->left) + ")";
        }
        if(root->right!=NULL){
            right+="(" + to_string(root->right->val)+ solve(root->right) +  ")";
        }
        string ans= left+right;
        return ans;
    }
    string tree2str(TreeNode* root) {
        if(root==NULL) return "";
        string ans="";
    
        ans+= to_string(root->val)+ solve(root);
        return ans;
    }
};