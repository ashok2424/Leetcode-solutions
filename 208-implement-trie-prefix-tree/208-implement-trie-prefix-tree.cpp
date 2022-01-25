class Node{
    public:
    int ew ; int sw ; //end words& start words (pref)
    Node* next[26];
};
class Trie {
public:
    Node* root ;
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node* cur  = root ;
        for(auto &ch:word){
            if(cur->next[ch-'a']==NULL){
                cur->next[ch-'a'] = new Node();
            }
            cur->sw++; 
            cur = cur->next[ch-'a'];
        }
        cur->ew++;
    }
    bool search(string word) {
        Node* cur = root;
        for(auto &ch:word){
            if(cur->next[ch-'a']==NULL) return false;
            cur = cur->next[ch-'a'];
        }
        if(cur->ew>0) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for(auto &ch:prefix){
            if(cur->next[ch-'a']==NULL) return false;
            cur = cur->next[ch-'a'];
        }
        return true;
    }
};