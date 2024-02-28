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
   
    int findBottomLeftValue(TreeNode* root) {
        // if(root->left==NULL && root->right==NULL){
        //     return root->val;
        // }
      queue<TreeNode*>q;
        int ans= root->val;
         q.push(root);
    
        while(!q.empty()){
            TreeNode* frontNode= q.front();
            q.pop();
            
        ans= frontNode->val; 
            
            // right should inserted first
             // if right exist 
            if(frontNode->right){
                q.push(frontNode->right);
            }
            
             // if left exist 
            if(frontNode->left){
                q.push(frontNode->left);
            }
        }
        
        return ans;
    }
};