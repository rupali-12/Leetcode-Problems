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
//     void solve(TreeNode* &root1, TreeNode* &root2){
//         if(root1==NULL ||  root2==NULL){
//             return;
//         }
//         if(root1->left && root2->left){
//             root1->left->val= root1->left->val + root2->left->val;
//         }
//         if(root1->left && !root2->left){
//          root1->left->val = root1->left->val + 0;
//         }
//        if(!root1->left && root2->left){
//            TreeNode* lnode= new TreeNode(root2->left->val);
//            root1->left= lnode;
//        }
      
//          // Right Traversing 
//        if(root1->right && root2->right){
//             root1->right->val= root1->right->val + root2->right->val;
//         }
//         if(root1->right && !root2->right){
//             root1->right->val = root1->right->val+0;
//         }
//          if(!root1->right && root2->right){
//            TreeNode* rnode= new TreeNode(root2->right->val);
//            root1->right= rnode;
//        }
//         solve(root1->left, root2->left);
//         solve(root1->right, root2->right);
        
//     }
//     TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
//         if(root1 && root2){
//             root1->val= root1->val + root2->val;
//         }
//         if(root1 && !root2){
//          root1->val = root1->val + 0;
//         }
//        if(!root1 && root2){
//            TreeNode* node= new TreeNode(root2->val);
//            root1= node;
//        }
//        solve(root1, root2);
//            return root1;
//     }
    
    // Approach-2 >
        TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
          if(root1==NULL || root2==NULL){
              return root1?root1:root2;
          }
        root1->val+= root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right =  mergeTrees(root1->right, root2->right);
        return root1;
    }
};