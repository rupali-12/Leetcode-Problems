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
//     bool isBST(TreeNode* root, int &mn, int &mx){
//     if(root==NULL){
//         return true;
//     }
//     if(root->val > mn && root->val <mx){
//         bool left =isBST(root->left, mn, root->val);
//         bool right= isBST(root->right, root->val, mx);
//         return left && right;
//     }
//     return 0;
// }
    bool isValidBST(TreeNode* root, long min = LONG_MIN, long max= LONG_MAX) {
       if(root==NULL){
        return true;
    }
    if(root->val > min && root->val <max){
        bool left =isValidBST(root->left, min, root->val);
        bool right= isValidBST(root->right, root->val, max);
        return left && right;
    }
    return 0;
    }
};


