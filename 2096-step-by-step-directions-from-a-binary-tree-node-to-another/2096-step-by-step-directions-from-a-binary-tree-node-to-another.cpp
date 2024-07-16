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
    TreeNode* lca(TreeNode* root, int start, int dest){
        if(!root){
            return NULL;
        }
        
        if(root->val==start || root->val==dest){
            return root;
        }
        
        TreeNode* left= lca(root->left, start, dest);
        TreeNode* right= lca(root->right, start, dest);
         if(left && right){
             return root;
         }
        
        return left? left: right;
    }
    bool findPath(TreeNode* root, int target, string &path){
        if(!root) return false;
        if(root->val== target) return true;
        
        // Explore left 
        path.push_back('L');
        if(findPath(root->left, target, path)){
            return true;
        }
        // backtrack 
        path.pop_back();
        
         // Explore right 
        path.push_back('R');
        if(findPath(root->right, target, path)){
            return true;
        }
        // backtrack 
        path.pop_back();
        
        return false;
        
    } 
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // Approach-1: 
        TreeNode* LCA = lca(root, startValue, destValue);
        string lcaToStart="";
        string lcaToDest= "";
         findPath(LCA, startValue, lcaToStart);
        findPath(LCA, destValue, lcaToDest);
        
        string ans="";
        for(int i=0; i<lcaToStart.length(); i++){
            ans+= 'U';
        }
        
        ans+= lcaToDest;
        return ans;
    }
};