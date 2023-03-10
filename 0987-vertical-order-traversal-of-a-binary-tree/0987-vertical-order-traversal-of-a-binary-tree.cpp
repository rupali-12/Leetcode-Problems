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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
//             map<int, map<int, vector<int>>>nodes;
//         queue<pair<TreeNode*, pair<int, int>>>q;
//         vector<vector<int>>ans;
        
//         if(root==NULL){
//             return ans;
//         }
//         q.push(make_pair(root, make_pair(0,0)));
//         while(!q.empty()){
//             pair<TreeNode*, pair<int, int>>temp = q.front();
//             q.pop();
//             TreeNode* frontNode= temp.first;
//             int hd= temp.second.first;
//             int lvl = temp.second.second;
            
//             nodes[hd][lvl].push_back(frontNode->val);
            
//             if(frontNode->left){
//                 q.push(make_pair(frontNode->left,make_pair(hd-1, lvl+1)));
//             }
//             if(frontNode->right){
//                 q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
//             }
//         }
        
//            for(auto i:nodes){
//             vector<int> col;
//             for(auto j:i.second){
//                 col.insert(col.end(),j.second.begin(),j.second.end());
//             }
//             ans.push_back(col);
//         }
        
//         return ans; 
        
        
        
         map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            mp[x][y].insert(node->val);
            if(node->left){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                q.push({node->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto q:mp){
            vector<int> col;
            for(auto p:q.second){
                col.insert(col.end(),p.second.begin(),p.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};