class TrieNode {
    public:
        vector<TrieNode*> children;
        bool isWord;

        TrieNode(){
            children = vector<TrieNode*>(60, NULL);
            isWord = false;
        }
};

class Trie {
    public:

        TrieNode* root = NULL;

        Trie(){
            root = new TrieNode();
        }

        void insertWord(string word){
            TrieNode* curr = root;
            for(char c : word){
                if(curr->children[c - 'A'] == NULL){
                    cout << c << endl;
                    curr->children[c - 'A'] = new TrieNode();
                }
                curr = curr->children[c - 'A'];
            }

            curr->isWord = true;
        }
};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();

        Trie* trie = new Trie();
        trie->insertWord(word);
        TrieNode* root = trie->root;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dfs(board, root, i, j)){
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, TrieNode* root, int x, int y){

        int m = board.size();
        int n = board[0].size();
        bool found = false;

        if(x < 0 || y < 0 || x >= m || y >= n || board[x][y] == '-'){
            return false;
        }

        if(root->children[board[x][y] - 'A']){
            root = root->children[board[x][y] - 'A'];
            if(root->isWord){
                return true;
            }

            char prev = board[x][y];

            board[x][y] = '-';
            bool found = dfs(board, root, x + 1, y) || dfs(board, root, x - 1, y) ||  dfs(board, root, x, y + 1) ||  dfs(board, root, x, y - 1);
            board[x][y] = prev;
            
            return found;
        }

        return false;
    }

};