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
    
  // *************  NOT WORKS ******************
//     int height(TreeNode* root){
//         if(root==NULL) return 0;
//         return 1 + max(height(root->left), height(root->right));
//     }
//     int heightOpt(TreeNode* root, int &ans){
//         if(root==NULL) return 0;
//         int hl= heightOpt(root->left, ans);
//         int hr = heightOpt(root->right, ans);
//          ans =  max(ans, 1+ hl + hr);
//         return 1 + max(hl, hr);
//     }
//     int widthOfBinaryTree(TreeNode* root) {
        
// //         // Approach-1: O(N^2);
// //         if(root==NULL) return 0;
// //         int widthLeft= widthOfBinaryTree(root->left);
// //         int widthRight = widthOfBinaryTree(root->right);
// //         int width =  1+ height(root->left) + height(root->right);
// //         return max(width, max(widthLeft , widthRight));
        
//          // Approach-2: O(N)
//         int ans=0;
//         heightOpt(root, ans);
//         return ans;
//     }
    
typedef unsigned long long ll;
int widthOfBinaryTree(TreeNode* root) {
   int maxW=0;
    queue<pair<TreeNode*, ll>>q;
    q.push({root, 0});
    while(!q.empty()){
        int n= q.size();
        int L = q.front().second;
        int R = q.back().second;
        maxW = max(maxW, R-L+1);
        
        // insert left right child of element inside root 
       while(n--){
            pair<TreeNode*, ll> temp= q.front();
           q.pop();
        TreeNode* frontNode = temp.first;
        ll idx= temp.second;
        if(frontNode->left){
            q.push({frontNode->left, 2*idx+1});
        }
        if(frontNode->right){
            q.push({frontNode->right, 2*idx+2});
          }
       }
    }
    return maxW;
}

    
};