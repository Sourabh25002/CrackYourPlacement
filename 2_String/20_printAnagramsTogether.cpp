#include <bits/stdc++.h>
using namespace std;

// Function to return the list of anagram groups
vector<vector<string>> Anagrams(vector<string> &words)
{
  unordered_map<string, vector<string>> anagramGroups;

  // Function to get the sorted version of a string
  auto getSortedString = [](const string &str)
  {
    string sortedStr = str;
    sort(sortedStr.begin(), sortedStr.end());
    return sortedStr;
  };

  // Group words by their sorted version
  for (const string &word : words)
  {
    string sortedWord = getSortedString(word);
    anagramGroups[sortedWord].push_back(word);
  }

  // Prepare the result list
  vector<vector<string>> result;
  for (auto &group : anagramGroups)
  {
    result.push_back(group.second);
  }

  // Sort each group lexicographically
  for (auto &group : result)
  {
    sort(group.begin(), group.end());
  }

  // Sort the result list based on the first word in each group
  sort(result.begin(), result.end(), [](const vector<string> &a, const vector<string> &b)
       { return a[0] < b[0]; });

  return result;
}

int main()
{
  int N;
  cout << "Input N: ";
  cin >> N;
  vector<string> words(N);

  cout << "Input words: ";
  for (int i = 0; i < N; ++i)
  {
    cin >> words[i];
  }

  vector<vector<string>> result = Anagrams(words);

  cout << "Output:" << endl;
  for (const vector<string> &group : result)
  {
    for (const string &word : group)
    {
      cout << word << " ";
    }
    cout << endl;
  }

  return 0;
}

/*
Time Complexity: O(N * |S| * log|S|), where N is the number of words and |S| is the length of the strings.
Space Complexity: O(N * |S|), where N is the number of words and |S| is the length of the strings.
*/
