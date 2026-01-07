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
int Sum=0;
long maxP =0;
    
    // calculate total sum 
    int totalSum(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int leftSum = totalSum(root->left);
        int rightSum = totalSum(root->right);
        int s = root->val + leftSum + rightSum;

        return s;
    }

    int findProduct(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int leftSum = findProduct(root->left);
        int rightSum = findProduct(root->right);
        long subTreeSum = root->val + leftSum + rightSum;

        long remSubTreeSum = Sum - subTreeSum;

        maxP = max(maxP, subTreeSum*remSubTreeSum);
        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        maxP=0;
        Sum = totalSum(root);
        findProduct(root);
        return maxP%1000000007;
    }
};