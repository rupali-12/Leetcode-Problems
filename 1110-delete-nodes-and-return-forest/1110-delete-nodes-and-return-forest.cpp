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
    TreeNode* solve(TreeNode* root, unordered_set<int>s, vector<TreeNode*>&ans){
        if(!root) return NULL;
        
        root->left = solve(root->left, s, ans);
        root->right = solve(root->right, s, ans);
        
        // if present then store left and right and return NULL as you deleted that 
        if(s.find(root->val)!=s.end()){
            if(root->left!=NULL){
                ans.push_back(root->left);
            }
            if(root->right!=NULL){
                ans.push_back(root->right);
            }
            return NULL;   // Necessary as we deleted that node so it should return NULL as its left and right we already in ans
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>s;
        for(auto element: to_delete){
            s.insert(element);
        }
        
        vector<TreeNode*>ans;
        solve(root, s, ans);
        if(s.find(root->val)==s.end()){   // if root not in set so add this in ans as well
              ans.push_back(root);
        }
        return ans;
    }
};