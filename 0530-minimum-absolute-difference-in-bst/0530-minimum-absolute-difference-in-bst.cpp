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
#include<bits/stdc++.h>
class Solution {
public:

    void solveBrute(TreeNode* root, vector<int>&ans){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        solveBrute(root->left, ans);
         solveBrute(root->right, ans);
        return;
    }
      void solve(TreeNode* root, int &mnDiff, int &prev){
        if(root==NULL){
            return;
        }
          solve(root->left, mnDiff, prev);
       if(prev!=-1){
           mnDiff = min(mnDiff, abs(root->val- prev));
       }
          prev= root->val;
          solve(root->right, mnDiff, prev);
          return;
    }
    int getMinimumDifference(TreeNode* root) {
        // // Approach 1>>Brute Force
        // vector<int>ans;
        // solveBrute(root, ans);
        // sort(ans.begin(), ans.end());
        // int res= ans[1]-ans[0];
        // for(int i=2; i<ans.size(); i++){
        //     res=min(res, ans[i]-ans[i-1]);
        // }
        // return res;
        
        // Approach-2>> Using Recursion 
        int mnDiff=INT_MAX;
        int prevValue=-1;
        solve(root, mnDiff, prevValue);
        return mnDiff;
    }
};