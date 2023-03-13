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
    TreeNode* solve(vector<int>& in, vector<int>& pre, int &index, int inOrderStart, int inOrderEnd, int n, map<int, queue<int>>&NodeToIndex){
        if(index>=n || inOrderStart>inOrderEnd){
            return NULL;
        }
        
        int element = pre[index++];   // index is first element of pre array in each call 
        
        TreeNode* root =new TreeNode(element);
        
        // find position of root in inorder  
        int position = NodeToIndex[element].front();
        NodeToIndex[element].pop();
        
        // call for left
      root->left = solve(in, pre, index, inOrderStart, position-1, n, NodeToIndex);
        
        // call for right
        root->right = solve(in, pre, index, position+1, inOrderEnd, n, NodeToIndex);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         int preOrderIndex=0;
        int n= preorder.size();
        map<int, queue<int>>NodeToIndex;
       for(int i=0; i<n; i++){
           NodeToIndex[inorder[i]].push(i);
       }
       
        TreeNode* ans =solve(inorder, preorder, preOrderIndex, 0, n-1, n, NodeToIndex);
        return ans;
    }
};