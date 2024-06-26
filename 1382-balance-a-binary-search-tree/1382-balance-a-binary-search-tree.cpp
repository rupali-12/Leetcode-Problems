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
    void findInOrder(TreeNode* root, vector<int>&inOrder){
        if(!root) return;
        findInOrder(root->left, inOrder);
        inOrder.push_back(root->val);
        findInOrder(root->right, inOrder);
    }
    
    TreeNode* solve(int l, int r, vector<int>&inOrder){
        if(l>r) return NULL;
        
        int mid = l + (r-l)/2;
        TreeNode* root= new TreeNode(inOrder[mid]);
       root->left= solve(l, mid-1, inOrder);
        root->right = solve(mid+1, r, inOrder);
        
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        
        // Find inorder 
        vector<int>inOrder;
        findInOrder(root, inOrder);
        int l=0, r= inOrder.size()-1;
        TreeNode* ans = solve(l, r, inOrder);
        return ans;
    }
};