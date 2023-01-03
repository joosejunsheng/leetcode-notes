## 212. Word Search II
### 51 Attack
Instead of doing DFS on every single words, it is easier to form a Trie with them. Just need to find all the words by checking on how many isWord == true are there.

Adding an extra string to keep track of completed word in TrieNode class so we don't need to pass our word down into every DFS function.

Time complexity for Trie insertion : O(alphabet size * length of string) = O(26 * n) = O(n).