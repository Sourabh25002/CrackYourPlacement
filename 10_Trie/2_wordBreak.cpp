#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
  TrieNode *children[26];
  bool isEndOfWord;

  TrieNode()
  {
    isEndOfWord = false;
    for (int i = 0; i < 26; i++)
      children[i] = nullptr;
  }
};

class Trie
{
public:
  TrieNode *root;

  Trie()
  {
    root = new TrieNode();
  }

  void insert(string word)
  {
    TrieNode *node = root;
    for (char c : word)
    {
      int index = c - 'a';
      if (!node->children[index])
      {
        node->children[index] = new TrieNode();
      }
      node = node->children[index];
    }
    node->isEndOfWord = true;
  }

  bool search(string word)
  {
    TrieNode *node = root;
    for (char c : word)
    {
      int index = c - 'a';
      if (!node->children[index])
        return false;
      node = node->children[index];
    }
    return node->isEndOfWord;
  }
};

bool wordBreakUtil(string &A, Trie &trie, int start, vector<int> &dp)
{
  if (start == A.size())
    return true;
  if (dp[start] != -1)
    return dp[start];

  TrieNode *node = trie.root;
  for (int i = start; i < A.size(); i++)
  {
    int index = A[i] - 'a';
    if (!node->children[index])
      break;
    node = node->children[index];
    if (node->isEndOfWord && wordBreakUtil(A, trie, i + 1, dp))
    {
      return dp[start] = true;
    }
  }

  return dp[start] = false;
}

int wordBreak(int n, vector<string> &B, string A)
{
  Trie trie;
  for (string word : B)
  {
    trie.insert(word);
  }

  vector<int> dp(A.size(), -1);
  return wordBreakUtil(A, trie, 0, dp) ? 1 : 0;
}

int main()
{
  int n = 12;
  vector<string> B = {"i", "like", "sam", "sung", "samsung", "mobile", "ice", "cream", "icecream", "man", "go", "mango"};
  string A = "ilike";

  cout << wordBreak(n, B, A) << endl; // Output: 1

  A = "ilikesamsung";
  cout << wordBreak(n, B, A) << endl; // Output: 1

  return 0;
}

/*
Time Complexity: O(n * l + |A|^2)
Space Complexity: O(|A| + k) where k = sum of lengths of all strings in B
*/
