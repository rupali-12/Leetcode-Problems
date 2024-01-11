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
    void mappingToAncestor(TreeNode* root, unordered_map<int, vector<int>>&nodeToAncestor){
       if(!root->left && !root->right) return;
        if(root->left){
             nodeToAncestor[root->left->val] =  nodeToAncestor[root->val];
            nodeToAncestor[root->left->val].push_back(root->val);
            mappingToAncestor(root->left, nodeToAncestor);
        }
         if(root->right){
            nodeToAncestor[root->right->val] = nodeToAncestor[root->val]; 
            nodeToAncestor[root->right->val].push_back(root->val);
            mappingToAncestor(root->right, nodeToAncestor);
        }
        return;
    }
    int maxAncestorDiff(TreeNode* root) {
        unordered_map<int, vector<int>>nodeToAncestor;
        mappingToAncestor(root, nodeToAncestor);
       int maxDiff=INT_MIN; 
        for(auto m: nodeToAncestor){
         int d1= m.first;
            for(auto n: m.second){
                int d2= n;
                int diff = abs(d1-d2);
                maxDiff= max(maxDiff, diff);
            }
        }
        return maxDiff;
        
    }
};