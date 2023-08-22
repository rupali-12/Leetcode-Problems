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
class info{
  public:
     int mn;
     int mx;
     int size;
     bool isbst;
    int sum;  
};
class Solution {
public:
    info solve(TreeNode* root, int &maxSum){
    if(root==NULL){
        return {INT_MAX, INT_MIN, 0, true, 0};
    }

    info left= solve(root->left, maxSum);
    info right= solve(root->right, maxSum);

    info currNode;
    currNode.size =left.size + right.size +1;
    currNode.mn = min(root->val, left.mn);
    currNode.mx = max(root->val, right.mx);
        currNode.sum= left.sum + right.sum + root->val;

    if(left.isbst && right.isbst && (root->val>left.mx && root->val<right.mn)){
        currNode.isbst= true;
    }
    else{
        currNode.isbst=false;
    }

    // update answer 
    if(currNode.isbst){
        maxSum= max(maxSum, currNode.sum);
    }
    return currNode;

    
}
    int maxSumBST(TreeNode* root) {
         int maxSum=0;
    info ans= solve(root, maxSum);
    return maxSum;
    }
};