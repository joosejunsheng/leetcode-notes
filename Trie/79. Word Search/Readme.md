## 79. Word Search
Classic DFS with Backtracking Question
Added Trie into the solution to familiarize with Trie data structure.

Create a nested loop for m * n grid and DFS through all the characters on board to look for the word. Backtracking is required to revert all the visited characters when a new DFS starts on a new character.

Time complexity for Trie insertion : O(alphabet size * length of string) = O(26 * n) = O(n).