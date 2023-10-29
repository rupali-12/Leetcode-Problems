struct Trie{
    Trie* next[2];
    Trie(){
        next[0]=NULL;
        next[1]=NULL;
    }
};

class TrieNode{
    private:
    Trie* root;
    public:
    TrieNode(){
        root= new Trie();
    }
      void insert(int num){
          Trie* curr= root;
          for(int i=31; i>=0; i--){
              int bit= (num>>i)&1;
              if(curr->next[bit]==NULL){
                  curr->next[bit]=new Trie();
              }
            
                  curr= curr->next[bit];
             
          }
      }
    
    int maxXor(int num){
        Trie* curr= root;
        int ans=0;
        for(int i=31; i>=0; i--){
            int bit= (num>>i)&1;  //0
           if(curr->next[!bit]){   //1
               ans+= 1<<i;
               curr=curr->next[!bit];
           }
            else{
                curr= curr->next[bit];   //  0  if 1 not found then approach 1
            }
        }
        return ans;
    }

};

class Solution {
public:
    
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root= new TrieNode();
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            root->insert(nums[i]);
             ans= max(ans, root->maxXor(nums[i]));
        }
        return ans;
    }
};