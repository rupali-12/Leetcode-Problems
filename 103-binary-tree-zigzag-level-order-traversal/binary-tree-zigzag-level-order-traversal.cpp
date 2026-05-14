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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        if(!root) return ans;
        
        queue<TreeNode*>pq;
        bool isLeftToRight =true;
        pq.push(root);
        while(!pq.empty()){
            int size=pq.size();
            vector<int>temp;
            while(size--){
                TreeNode* front= pq.front();
                pq.pop();
                temp.push_back(front->val);
                if(front->left){
                    pq.push(front->left);
                }
                if(front->right){
                    pq.push(front->right);
                }
            }
                if(!isLeftToRight){
                    reverse(temp.begin(), temp.end());
                }
                isLeftToRight = !isLeftToRight;
            ans.push_back(temp);
        }
        return ans;
    }
};