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

// a-> 97
class Solution {
public:
    string res="";
    
    // void dfs(TreeNode* root, string curr){
//        if(root==NULL) return;
        
//         curr= char(root->val + 'a') + curr;
//         if(!root->left && !root->right){
//             if(res=="" || res>curr) res= curr;
//             return;
//         }
       
//         dfs(root->left, curr);
//         dfs(root->right, curr);    
//     }
    
    string smallestFromLeaf(TreeNode* root) {

//         // Approach-1: DFS
//         dfs(root, "");
//         return res;
        
        // Approach-2: BFS
        queue<pair<TreeNode*, string>>q;
        q.push({root, string(1, char(root->val + 'a'))});
        
        while(!q.empty()){
            auto p= q.front();
            q.pop();
            TreeNode* node= p.first;
            string curr= p.second;
            
            if(!node->left && !node->right){
                if(res=="" || res>curr){
                res= curr;
            }
            }
            
            if(node->left){
                q.push({node->left, (char(node->left->val +'a') + curr)});
            }
             if(node->right){
                q.push({node->right, (char(node->right->val +'a') + curr)});
            }
        }
        
        return res;
        
    }
};