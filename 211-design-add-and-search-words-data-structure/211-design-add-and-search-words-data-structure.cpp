// class Node{
//     public:
//     int ew ; int sw ; //end words& start words (pref)
//     Node* next[26];
// };

class WordDictionary {
    class Node{
        public:
        int ew ; int sw ; //end words& start words (pref)
        Node* next[26];
    };
public:
    Node* root =new Node();
    WordDictionary() {
        
    }
    void addWord(string word) {
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
            if(ch=='.'){
                for(char c='a';c<='z';c++){
                    ch=c; if(search(word)) return true;
                }
            }
            if(cur->next[ch-'a']==NULL) return false;
            cur = cur->next[ch-'a'];
        }
        if(cur->ew>0) return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */