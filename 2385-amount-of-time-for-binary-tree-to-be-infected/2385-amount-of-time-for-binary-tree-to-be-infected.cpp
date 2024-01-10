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
    TreeNode* mappingToParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&nodeToParent, int start){
        TreeNode* ans=NULL;
        queue<TreeNode*>q;
        q.push(root);
        nodeToParent[root]=NULL;
        while(!q.empty()){
            TreeNode* frontNode= q.front();
            q.pop();
            if(frontNode->val ==  start){
                ans = frontNode;
            }
            if(frontNode->left){
                nodeToParent[frontNode->left] = frontNode;
                q.push(frontNode->left);
            }
            if(frontNode->right){
                nodeToParent[frontNode->right]= frontNode;
                q.push(frontNode->right);
            }
        }
        return ans;
    }
    
   
    void solve(TreeNode* root, TreeNode* targetNode, int &timeCount, unordered_map<TreeNode*, TreeNode*>&nodeToParent){
        unordered_map<TreeNode*, bool>visited;
        queue<TreeNode*>q;
        q.push(targetNode);
        visited[targetNode]= 1;
        while(!q.empty()){
            int size= q.size();
            bool flag=false;   // to check whether we need to add or not
              TreeNode* temp;
            for(int i=0; i<size; i++){
                TreeNode* frontNode= q.front();
                temp= frontNode;
                q.pop();
                
                if(frontNode->left && !visited[frontNode->left]){
                    flag= true;
                    q.push(frontNode->left);
                    visited[frontNode->left]=true;
                }
                if(frontNode->right && !visited[frontNode->right]){
                    flag= true;
                    q.push(frontNode->right);
                    visited[frontNode->right]=true;
                }
                if(nodeToParent[frontNode] && !visited[nodeToParent[frontNode]]){
                    flag= true;
                    q.push(nodeToParent[frontNode]);
                    visited[nodeToParent[frontNode]]=true;
                }
                
            }
            if(flag){
            // outside for loop as bcoz increment by 1 only after processing all neighbours of current node 
                timeCount++; 
            }
        }
        return;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*>nodeToParent;
        int timeCount=0;
        TreeNode* targetNode = mappingToParent(root, nodeToParent, start);
        solve(root, targetNode, timeCount, nodeToParent);
        return timeCount;
    }
};