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
    void inOrder(TreeNode* root, unordered_map<int, int>&mp){
        if(root==NULL) return;
        
        inOrder(root->left, mp);
        mp[root->val]++;
        inOrder(root->right, mp);
    }
    vector<int> findMode(TreeNode* root) {
        // base case
         vector<int>ans;
       // Approach-1: Unordered_map 
        int maxFreq= 0;
        unordered_map<int, int>mp;
        inOrder(root, mp);
        
        for(auto a: mp){
            if(a.second>maxFreq){
                maxFreq = a.second;
                ans ={};    // reset ans
                ans.push_back(a.first);
            }
            else if(a.second == maxFreq){
                ans.push_back(a.first);
            }
        }
        return ans;
    }
};