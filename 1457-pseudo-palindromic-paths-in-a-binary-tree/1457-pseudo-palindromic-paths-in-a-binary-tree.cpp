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
 
    void dfs(TreeNode* root, vector<int>bitset, int &count){
        if(root==NULL) return;
     bitset[root->val]++;
        
        dfs(root->left, bitset, count);
        dfs(root->right, bitset, count);
        
         if(root->left==NULL && root->right==NULL){
            int oddcount=0;
             for(int i=1; i<=9; i++){
                 if(bitset[i]%2!=0){
                   oddcount++;  
                 }
             }
             
             if(oddcount==1 || oddcount==0){
                 count++;
             }
        }
         
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return 1;
        vector<int>bitset(10, 0);
        int count=0;
       dfs(root, bitset, count);
        return count;
    }
};