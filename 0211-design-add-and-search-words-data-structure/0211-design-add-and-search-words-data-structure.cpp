class WordDictionary {
    struct Node{
        Node *links[26];
        bool flag = false;

        Node(){
            for(int i = 0 ; i < 26 ; i++){
                links[i] = NULL;
            }
        }
    };
    Node * root;
public:
    WordDictionary() {
        root = new Node();
        
    }
    
    void addWord(string word) {
        Node * node = root;
        for(char ch : word){
            int idx = ch - 'a';
            if(node->links[idx] == NULL)
                node->links[idx] = new Node();

                node = node->links[idx];

        }
        node->flag = true;
        
    }
    bool searchHelper(Node * node , string &word , int pos){
        if(pos == word.length()){
            return node->flag;
        }
        char ch = word[pos];
        if(ch == '.'){
            for(int i = 0 ; i < 26 ; i++){
                if(node->links[i] != NULL)
                    if(searchHelper(node->links[i] , word , pos+1))
                        return true;
            }
            return false;

        }
        int idx = ch - 'a';

        if(node->links[idx] == NULL) return false;

        node = node->links[idx];
        return searchHelper(node , word , pos+1);

    }
    
    bool search(string word) {
        return searchHelper(root, word , 0);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */