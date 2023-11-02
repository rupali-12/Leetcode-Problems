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
    // <sum, countVisited> 
    pair<int, int> solve(TreeNode* root,  int &ans){
        if(root==NULL){
           return {0, 0};
        }
        if(root->left==NULL && root->right==NULL){
            ans++;
            return {root->val,1};
        }
        
       pair<int, int> leftSum= solve(root->left, ans);
       pair<int, int> rightSum= solve(root->right, ans);
        
        // count cureent root node 
        int sum= leftSum.first + rightSum.first +root->val;
        int countVisited = leftSum.second + rightSum.second +1;  // +1 to count current node
        if(sum/countVisited == root->val){
            ans++;
        }
    
        return {sum, countVisited};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        solve(root, ans);
        return ans;
    }
};