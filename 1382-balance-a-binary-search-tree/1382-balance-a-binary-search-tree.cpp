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
    void inOrder(TreeNode* root, vector<int>&in){
    if(root==NULL){
        return;
    }
    inOrder(root->left, in);
    in.push_back(root->val);
    inOrder(root->right, in);
}
TreeNode* inOrderToBST(int s, int e, vector<int>&inorderVal){
    if(s>e){  
        return NULL;
    }

    int mid =(s+e)/2;
    TreeNode* root = new TreeNode(inorderVal[mid]);
    root->left = inOrderToBST(s, mid-1, inorderVal);
    root->right = inOrderToBST(mid+1, e, inorderVal);
    return root;
} 
    TreeNode* balanceBST(TreeNode* root) {
         vector<int>inorderVal;
     inOrder(root, inorderVal);
    TreeNode* ans= inOrderToBST(0, inorderVal.size()-1, inorderVal);
     return ans;
    }
};