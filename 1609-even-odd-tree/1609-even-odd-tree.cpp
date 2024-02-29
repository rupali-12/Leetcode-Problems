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
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int size=q.size();
            int prevNodeVal = (level%2==0)?INT_MIN:INT_MAX;
            while(size--){
                TreeNode* currNode=q.front();
                q.pop();
                int currVal = currNode->val;
                if(level%2==0){   //even level
                    if(currVal%2==0 || prevNodeVal>=currVal) return false;
                }
                else{   // odd level
                    if(currVal%2!=0 || prevNodeVal<=currVal) return false;
                }
                
                prevNodeVal= currVal;
                if(currNode->left){
                    q.push(currNode->left);
                }
                if(currNode->right){
                    q.push(currNode->right);
                }
            }
            level++;
        }
        return true;
    }
};