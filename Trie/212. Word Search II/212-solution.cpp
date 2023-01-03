class TrieNode {
    public:
    vector<TrieNode*> children;
    bool isWord;
    string word;

    TrieNode(){
        children = vector<TrieNode*>(26, NULL);
        isWord = false;
        word = "";
    }
};

class Trie {
    private:
    
    TrieNode* root;

    public:
    Trie(){
        root = new TrieNode;
    }

    TrieNode* getRoot(){
        return root;
    }

    void insertWord(string word){

        TrieNode* curr = root;

        for(char c : word){
            if(curr->children[c - 'a'] == NULL){
                curr->children[c - 'a'] = new TrieNode;
            }
            curr = curr->children[c - 'a'];
        }

        curr->isWord = true;
        curr->word = word;
    }

};

class Solution {
unordered_set<string> set;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        int m = board.size();
        int n = board[0].size();
        vector<string> res;

        Trie* trie = new Trie;
        for(string word : words){
            trie->insertWord(word);
        }

        TrieNode* root = trie->getRoot();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dfs(board, root, i, j);
            }
        }

        for(auto word : set){
            res.push_back(word);
        }

        return res;
    }

    void dfs(vector<vector<char>>& board, TrieNode* root, int x, int y){
        int m = board.size();
        int n = board[0].size();

        if(x < 0 || y < 0 || x >= m || y >= n || board[x][y] == '-'){
            return;
        }

        if(root->children[board[x][y] - 'a'] == NULL){
            return;
        }

        root = root->children[board[x][y] - 'a'];
        if(root->isWord){
            set.insert(root->word);
        }

        char prev = board[x][y];
        board[x][y] = '-';

        dfs(board, root, x + 1, y);
        dfs(board, root, x - 1, y);
        dfs(board, root, x, y + 1);
        dfs(board, root, x, y - 1);
        
        board[x][y] = prev;
    }
};