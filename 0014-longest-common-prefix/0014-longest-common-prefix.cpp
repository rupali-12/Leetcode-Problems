  class TrieNode{
      public:
       char data;
       TrieNode* children[26];
       int childCount;
       bool isTerminal;

       TrieNode(char ch){
           data =ch;
           for(int i=0; i<26; i++){
               children[i]=NULL;
           }
           childCount=0;
           isTerminal =false;
       }
  };
  class Trie{
      public:
      TrieNode* root;
      Trie(char ch){
          root =new TrieNode(ch);
      }
    void insertUtil(TrieNode* root, string word){
        if(word.length()==0){
            root->isTerminal =true;
            return;
        }
        int index = word[0]-'a';
        TrieNode* child;

        // present
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{       //absent
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] =child;
        }
       insertUtil(child, word.substr(1));
    }
 
     void insert(string word){
         insertUtil(root, word);
     }

     void lcp(string str, string &ans){
        for(int i=0; i<str.length(); i++){
            char ch =str[i];
            if(root->childCount==1){
                ans+= ch;
                int index= ch-'a';
                root= root->children[index];
            }
            else{
                break;
            }

            // if root->isTerminal then also break 
            if(root->isTerminal){
                break;
            }
        }
     }
  };
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
//         // approach-1 sorting
//         string ans="";
//        sort(strs.begin(), strs.end());
        
//        for(int i=0; i<strs[0].length(); i++){
//            if(strs[0][i]==strs[strs.size()-1][i]){
//                ans+= strs[0][i];
//            }
//          else{
//                break;
//          }
//        }
//       return ans;
        
        // Approach-2: UsingTrie 
         string ans="";
        int n = strs.size();
    Trie* node =new Trie('\0');
    for(int i=0; i<n; i++){
        if(strs[i]==""){
            return "";
        }
        node->insert(strs[i]);
    } 

    // make function lcp
    string first= strs[0]; 
    node->lcp(first, ans);
    return ans;
    }
};