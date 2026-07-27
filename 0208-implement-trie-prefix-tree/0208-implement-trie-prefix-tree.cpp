class TrieNode{
    public: 
      char data;
      TrieNode* children[26];
      bool isTerminal;
      TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
        isTerminal = false;
      }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertUtils(TrieNode* root, string word){
       if(word.length()==0){
        root->isTerminal = true;
        return;
       }
       TrieNode* child;
       int idx = word[0]-'a';

    // case of present
       if(root->children[idx]!=NULL){
        child = root->children[idx];
       }
       else{
          child = new TrieNode(word[0]);
          root->children[idx] = child;
       }

       insertUtils(child, word.substr(1));
    }

    void insert(string word) {
        insertUtils(root, word);
    }
    
    bool searchUtils(TrieNode* root, string word){
         if(word.length()==0){
            return root->isTerminal;
         }

         TrieNode* child;
         int idx = word[0]-'a';
        
        // present
        if(root->children[idx]!=NULL){
            child = root->children[idx];
        }
        else{
            return false;
        }

        return searchUtils(child, word.substr(1));
    }

    bool search(string word) {
        return searchUtils(root, word);
    }
    
    bool prefixUtils(TrieNode* root, string prefix){
       if(prefix.length()==0){
        return true;
       }

       TrieNode* child;
       int idx = prefix[0]-'a';

    //(    present
    if(root->children[idx]!=NULL){
        child = root->children[idx];
    }
    else{
        return false;
    }

    return prefixUtils(child, prefix.substr(1));
    }

    bool startsWith(string prefix) {
        return prefixUtils(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */