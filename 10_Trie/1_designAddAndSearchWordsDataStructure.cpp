#include <bits/stdc++.h>
using namespace std;

class WordDictionary
{
public:
  struct TrieNode
  {
    bool isEnd;
    unordered_map<char, TrieNode *> children;
    TrieNode() : isEnd(false) {}
  };

  TrieNode *root;

  WordDictionary()
  {
    root = new TrieNode();
  }

  void addWord(string word)
  {
    TrieNode *node = root;
    for (char c : word)
    {
      if (!node->children.count(c))
      {
        node->children[c] = new TrieNode();
      }
      node = node->children[c];
    }
    node->isEnd = true;
  }

  bool search(string word)
  {
    return searchInNode(word, 0, root);
  }

private:
  bool searchInNode(string &word, int index, TrieNode *node)
  {
    if (index == word.size())
      return node->isEnd;

    char c = word[index];
    if (c == '.')
    {
      for (auto &child : node->children)
      {
        if (searchInNode(word, index + 1, child.second))
        {
          return true;
        }
      }
      return false;
    }
    else
    {
      if (!node->children.count(c))
        return false;
      return searchInNode(word, index + 1, node->children[c]);
    }
  }
};

int main()
{
  WordDictionary wordDictionary;
  wordDictionary.addWord("bad");
  wordDictionary.addWord("dad");
  wordDictionary.addWord("mad");

  cout << boolalpha << wordDictionary.search("pad") << endl; // Output: false
  cout << boolalpha << wordDictionary.search("bad") << endl; // Output: true
  cout << boolalpha << wordDictionary.search(".ad") << endl; // Output: true
  cout << boolalpha << wordDictionary.search("b..") << endl; // Output: true

  return 0;
}

/*
Time Complexity:
- addWord: O(m), where m is the length of the word.
- search: O(m * 26^k), where m is the length of the word and k is the number of '.' characters in the word.

Space Complexity: O(m * n), where m is the length of the word and n is the number of words added to the dictionary.
*/
