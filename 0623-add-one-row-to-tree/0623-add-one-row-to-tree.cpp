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
    void dfs(TreeNode* root, int val, int depth, int currdepth){
        if(!root) return;
        
        if(currdepth==depth-1){
            TreeNode* newleft= new TreeNode(val);
            newleft->left= root->left;
            root->left= newleft;
            
            TreeNode* newright= new TreeNode(val);
            newright->right= root->right;
            root->right= newright;
            
            return;
        }
        dfs(root->left, val, depth, currdepth+1);
        dfs(root->right, val, depth, currdepth+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
             TreeNode* node= new TreeNode(val);
             node->left= root;   
            return node;
        }
        
       dfs(root, val, depth, 1);
        return root;
    }
};