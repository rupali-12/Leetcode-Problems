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
    typedef pair<int, int>P;
    P solve(TreeNode* root){
        if(root==NULL) return {0, 0};
        auto left = solve(root->left);
        auto right = solve(root->right);

        int currDia = max((left.second+right.second), max(left.first, right.first));
        int currHeight = max(left.second, right.second)+1;
        return {currDia, currHeight};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        P ans = solve(root);
        return ans.first;
    }
};