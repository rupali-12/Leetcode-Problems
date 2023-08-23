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
    // void solve(TreeNode* root, int &mnDiff){
    //     if(root==NULL){
    //         return;
    //     }
    //     mnDiff= min(root)
    // }
    void solve(TreeNode* root, vector<int>&ans){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        solve(root->left, ans);
         solve(root->right, ans);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        // int mnDiff=0;
        // solve(root, mnDiff);
        // return mnDiff;
        
        vector<int>ans;
        solve(root, ans);
        sort(ans.begin(), ans.end());
        int res= ans[1]-ans[0];
        for(int i=2; i<ans.size(); i++){
            res=min(res, ans[i]-ans[i-1]);
        }
        return res;
    }
};