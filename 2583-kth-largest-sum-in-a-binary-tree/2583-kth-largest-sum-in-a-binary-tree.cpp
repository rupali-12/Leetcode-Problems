class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;
        priority_queue<long long, vector<long long>, greater<long long>>ans;
        queue<TreeNode*>pq;
       
        pq.push(root);
        
        while(!pq.empty()){
            int levelSize = pq.size();
            long long levelSum=0;
            
            for(int i= 0; i<levelSize; i++){
                TreeNode* top= pq.front();
                pq.pop();
                
                levelSum+= top->val;
                
                if(top->left) pq.push(top->left);
                if(top->right) pq.push(top->right);
            }
            
            ans.push(levelSum);
            
            if(ans.size() >k){
                ans.pop();
            }
        }
        
        return ans.size()==k? ans.top() : -1;
        
    }
};