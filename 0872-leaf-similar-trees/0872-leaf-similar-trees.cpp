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
    void dfs(TreeNode* root, vector<int>&list){
        if(root==NULL) return;
        if(!root->left && !root->right){
            list.push_back(root->val);
            return;
        }
        dfs(root->left, list);
        dfs(root->right, list);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>list1, list2;
         dfs(root1, list1);
         dfs(root2, list2);
        return list1==list2;
    }
    
    
    
};