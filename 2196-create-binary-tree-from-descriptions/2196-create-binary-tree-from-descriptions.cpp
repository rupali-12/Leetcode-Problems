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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>s;
        
        for(auto &v: descriptions){
            int parent = v[0];
            int child = v[1];
            int isLeft= v[2];
            
            // if parent is not present in mp
            if(mp.find(parent)==mp.end()){
                mp[parent]= new TreeNode(parent);
            }
              
            // if child is not present in mp
            if(mp.find(child)==mp.end()){
                mp[child]= new TreeNode(child);
            }
            
              // check if child is left or right node of parent 
            if(isLeft){
                mp[parent]->left= mp[child];
            }
            else{
                mp[parent]->right= mp[child];
            }
            
            s.insert(child);
        }
        
        // find root 
        for(auto v: descriptions){
            int parent = v[0];
            if(s.find(parent)==s.end()){
                return mp[parent];
            }
        }
        return NULL;
    }
};