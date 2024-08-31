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
private:
  TrieNode *root;

public:
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
      {
        return false;
      }
      node = node->children[index];
    }
    return node->isEndOfWord;
  }

  bool startsWith(string prefix)
  {
    TrieNode *node = root;
    for (char c : prefix)
    {
      int index = c - 'a';
      if (!node->children[index])
      {
        return false;
      }
      node = node->children[index];
    }
    return true;
  }
};

int main()
{
  Trie trie;
  trie.insert("apple");
  cout << boolalpha << trie.search("apple") << endl;   // return True
  cout << boolalpha << trie.search("app") << endl;     // return False
  cout << boolalpha << trie.startsWith("app") << endl; // return True
  trie.insert("app");
  cout << boolalpha << trie.search("app") << endl; // return True

  return 0;
}

/*
Time Complexity:
- insert: O(m), where m is the length of the word.
- search: O(m), where m is the length of the word.
- startsWith: O(m), where m is the length of the prefix.

Space Complexity: O(n * m), where n is the number of words inserted and m is the average length of the words.
*/
