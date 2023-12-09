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
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int>ans;
        // if(root==NULL){
        //     return ans;
        // }
        // vector<int>left =inorderTraversal(root->left);
        // ans.insert(ans.end(), left.begin(), left.end());
        // ans.push_back(root->val);
        //  vector<int>right =inorderTraversal(root->right);
        // ans.insert(ans.end(), right.begin(), right.end());
        // return ans;
        
        // Morris traversal
       vector<int>ans;
        if(root==NULL){
            return ans;
        }
        TreeNode* curr= root;
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr= curr->right;
            }
            else{
                TreeNode* pred= curr->left;
                while(pred->right!=NULL && pred->right!=curr){
                    pred= pred->right;
                }
                 
                // if pred->right not exist 
                if(pred->right==NULL){
                    pred->right= curr;
                    curr= curr->left;
                }
                else{
                    pred->right=NULL;
                    ans.push_back(curr->val);
                    curr= curr->right;
                }
            }
        }
        
        
            
        return ans;
    }
};