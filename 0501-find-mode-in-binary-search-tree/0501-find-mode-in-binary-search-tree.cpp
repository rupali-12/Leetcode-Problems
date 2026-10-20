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
    vector<int>ans;
    void solve(TreeNode* root, unordered_map<int, int>&mp){
        if(root==NULL) return;
        solve(root->left, mp);
        mp[root->val]++;
        solve(root->right, mp);
    }
    vector<int> findMode(TreeNode* root) {
        // Approach-1: unordered_map 
        unordered_map<int, int>mp;
        solve(root, mp);

        int maxFreq=0;
        for(auto m: mp){
            if(m.second > maxFreq){
                maxFreq = m.second;
                ans={};
                ans.push_back(m.first);
            }
            else if(m.second == maxFreq){
                ans.push_back(m.first);
            }
        }
        return ans;
    }
};