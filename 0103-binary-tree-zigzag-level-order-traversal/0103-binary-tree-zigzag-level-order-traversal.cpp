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
        vector<vector<int>>result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode*>q;
	bool leftToRight= true;
    	q.push(root);
        while(!q.empty()){
 int size= q.size();
    	    vector<int>ans(size);
    	    for(int i=0;i<size;i++){
    	        TreeNode* fNode = q.front();
    	        q.pop();
    	        
    	       // check flow
    	        int index = leftToRight?i: (size-i-1);
    	        ans[index]= fNode->val;
    	        
    	        if(fNode->left){
    	            q.push(fNode->left);
    	        }
    	        if(fNode->right){
    	            q.push(fNode->right);
    	        }
    	    }
    	    leftToRight= !leftToRight;
            result.push_back(ans);
        }
        return result;
    }
};