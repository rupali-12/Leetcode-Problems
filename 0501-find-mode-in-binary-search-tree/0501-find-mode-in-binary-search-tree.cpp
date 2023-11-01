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
    
    
    void inOrder(TreeNode* root, unordered_map<int, int>&mp){
        if(root==NULL) return;
        
        inOrder(root->left, mp);
        mp[root->val]++;
        inOrder(root->right, mp);
    }
    void dfs(TreeNode* root, int &currNum, int &currFreq, int &maxFreq, vector<int>&ans){
        if(!root) return;
        
        // left call 
        dfs(root->left, currNum,currFreq, maxFreq, ans);
        
        if(root->val == currNum){
            currFreq++;
        }
        else{
            currNum = root->val;
            currFreq=1;
        }
        
        // update max frequency 
        if(currFreq > maxFreq){
            // update  
            ans ={}; 
            maxFreq= currFreq;
        }
        
        // update ans 
        if(currFreq==maxFreq){
            ans.push_back(root->val);
        }
        
        // right call 
        dfs(root->right, currNum,currFreq, maxFreq, ans);
    }
    vector<int> findMode(TreeNode* root) {
        // base case
//        // Approach-1: Unordered_map 
          // vector<int>ans;
//         int maxFreq= 0;
//         unordered_map<int, int>mp;
//         inOrder(root, mp);
        
//         for(auto a: mp){
//             if(a.second>maxFreq){
//                 maxFreq = a.second;
//                 ans ={};    // reset ans
//                 ans.push_back(a.first);
//             }
//             else if(a.second == maxFreq){
//                 ans.push_back(a.first);
//             }
//         }
//         return ans;
        
        // Approach-2: optimized Approach 
        int currNum=0, currFreq=0, maxFreq=0;
          vector<int>ans;
        dfs(root, currNum, currFreq, maxFreq, ans);
        return ans;
    }
};