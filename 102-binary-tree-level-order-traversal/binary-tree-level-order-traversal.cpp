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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>pq;
        vector<vector<int>>ans;

        if(!root) return ans;

        pq.push(root);
        while(!pq.empty()){
            int size=pq.size();
            vector<int>temp;
            while(size--){
                TreeNode* front =pq.front();
                pq.pop();
                temp.push_back(front->val);
                if(front->left!=NULL){
                    pq.push(front->left);
                }
                if(front->right!=NULL){
                    pq.push(front->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};