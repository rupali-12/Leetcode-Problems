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
//         // Approahc-2:  works on GFG 
//      int solve(TreeNode* root, int& res){
//           if(root==NULL) return 0;
//         int left= solve(root->left, res);
//         int right= solve(root->right, res);
//         // case when root combined with left and right and pass to root
//          int temp= max(left, right) +1;
//          int ans= max(temp, 1+left+right);
         
//          res= max(res, ans);
//         return temp;
//     }
//      int diameterOfBinaryTree(TreeNode* root) {
//       int res=INT_MIN;
//          solve(root, res);
//          return res;
//     }
    
    // Approach-1: 
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int l= height(root->left);
        int r= height(root->right);
        int ans= max(l, r)+1; 
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int left= diameterOfBinaryTree(root->left);
        int right= diameterOfBinaryTree(root->right);
        int combLeftRight = height(root->left) + height(root->right);
        int ans= max(left, max(right, combLeftRight));
        return ans;
    }

};