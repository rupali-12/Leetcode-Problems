class TrieNode{
   public:
   char data;
   TrieNode* children[26];
   int childCount;
   bool isTerminal;
   TrieNode(char ch){
    data = ch;
    for(int i=0; i<26; i++){
        children[i]=NULL;
    }
    isTerminal = false;
    childCount=0;
   }
};

class Trie{
   public: 
   TrieNode* root;
   Trie(char ch){
    root= new TrieNode(ch);
   }

   void insertUtils(TrieNode* root, string word){
      if(word.length()==0){
         root->isTerminal = true;
         return;
      }

      TrieNode* child;
      int idx = word[0]-'a';

      if(root->children[idx]!=NULL){
        child = root->children[idx];
      }
      else{
        child = new TrieNode(word[0]);
        root->childCount++;
        root->children[idx] = child;
      }
      insertUtils(child, word.substr(1));
   }

   void insertWord(string word){
      insertUtils(root, word);
   }

   void lcp(string str, string &ans){
      for(int i=0; i<str.length(); i++){
        char ch = str[i];

        if(root->childCount==1){
           ans.push_back(ch);
           int idx = ch-'a';
           root = root->children[idx];
        }
        else{
            break;
        }

        if(root->isTerminal){
            break;
        }
      }
   }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    //     // Approach 1: Sorting
    //    string ans="";
    //    int n = strs.size();
    //    sort(strs.begin(), strs.end());
    //    string first = strs[0];
    //    for(int i=0; i<first.length(); i++){
    //       if(strs[0][i]==strs[n-1][i]){
    //         ans+= strs[0][i];
    //       }
    //       else{
    //         break;
    //       }
    //    }
    //    return ans;

    // Approach-2: using Trie
    Trie* t = new Trie('\0');
    for(int i=0; i<strs.size(); i++){
      if(strs[i]==""){
        return "";
    }  
        t->insertWord(strs[i]);
    }
    string first= strs[0];
    string ans="";
    t->lcp(first, ans);
    return ans;
    }
};