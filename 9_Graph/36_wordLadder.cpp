#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList)
  {
    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(beginWord);

    while (!q.empty())
    {
      string word = q.front().first;
      int steps = q.front().second;
      q.pop();

      if (word == endWord)
      {
        return steps;
      }

      for (int i = 0; i < word.size(); i++)
      {
        char original = word[i];
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
          word[i] = ch;
          if (st.find(word) != st.end())
          {
            st.erase(word);
            q.push({word, steps + 1});
          }
        }
        word[i] = original;
      }
    }
    return 0;
  }
};

int main()
{
  Solution solution;
  string beginWord = "hit";
  string endWord = "cog";
  vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

  int result = solution.ladderLength(beginWord, endWord, wordList);
  cout << "The length of the shortest transformation sequence is: " << result << endl;

  return 0;
}

/*
Time Complexity: O(N * 26^L), where N is the number of words in the wordList and L is the length of each word. The BFS explores each word by changing each character and checking the dictionary.
Space Complexity: O(N * L), where N is the number of words in the wordList and L is the length of each word. The space is used for storing the queue and the unordered_set.
*/
