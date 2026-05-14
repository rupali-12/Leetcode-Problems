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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        queue<TreeNode*>pq;
        pq.push(root);
        while(!pq.empty()){
            int size= pq.size();
            int rightMost;
            while(size--){
                TreeNode* front = pq.front();
                pq.pop();
                rightMost = front->val;
                if(front->left) pq.push(front->left);
                if(front->right) pq.push(front->right);
            }
            ans.push_back(rightMost);
        }
        return ans;
    }
};