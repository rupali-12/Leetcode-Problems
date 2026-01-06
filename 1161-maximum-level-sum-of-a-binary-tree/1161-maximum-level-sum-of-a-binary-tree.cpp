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
    int maxLevelSum(TreeNode* root) {
        int mxSum=INT_MIN;
        int ansLevel;
        queue<pair<TreeNode*, int>>q;   // node, currentlevel
        q.push({root, 1});
        while(!q.empty()){
            int size= q.size();
            int currLevel= q.front().second;
            int sum=0;
            while(size--){
            TreeNode* currentNode= q.front().first;
            q.pop();
            sum+= currentNode->val;
            if(currentNode->left){
                q.push({currentNode->left, currLevel+1});
            } 
            if(currentNode->right){
                q.push({currentNode->right, currLevel+1});
            }
            }
            if(mxSum<sum){
                mxSum =sum;
                ansLevel = currLevel;
            }
        }
        return ansLevel;
    }
};