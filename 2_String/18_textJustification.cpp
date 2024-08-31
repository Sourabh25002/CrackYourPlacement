#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> fullJustify(vector<string> &words, int maxWidth)
  {
    vector<string> result;
    vector<string> line;
    int lineLength = 0;

    for (const string &word : words)
    {
      if (lineLength + line.size() + word.size() > maxWidth)
      {
        int spaces = maxWidth - lineLength;
        if (line.size() == 1)
        {
          result.push_back(line[0] + string(spaces, ' '));
        }
        else
        {
          int spaceBetweenWords = spaces / (line.size() - 1);
          int extraSpaces = spaces % (line.size() - 1);
          string lineString = line[0];
          for (int i = 1; i < line.size(); ++i)
          {
            lineString += string(spaceBetweenWords + (i <= extraSpaces ? 1 : 0), ' ') + line[i];
          }
          result.push_back(lineString);
        }
        line.clear();
        lineLength = 0;
      }
      line.push_back(word);
      lineLength += word.size();
    }

    string lastLine = accumulate(line.begin(), line.end(), string(), [](const string &a, const string &b)
                                 { return a.empty() ? b : a + " " + b; });
    lastLine += string(maxWidth - lastLine.size(), ' ');
    result.push_back(lastLine);

    return result;
  }
};

int main()
{
  Solution solution;

  vector<string> words1 = {"This", "is", "an", "example", "of", "text", "justification."};
  int maxWidth1 = 16;
  vector<string> result1 = solution.fullJustify(words1, maxWidth1);
  cout << "Output:" << endl;
  for (const string &line : result1)
  {
    cout << "\"" << line << "\"" << endl;
  }

  vector<string> words2 = {"What", "must", "be", "acknowledgment", "shall", "be"};
  int maxWidth2 = 16;
  vector<string> result2 = solution.fullJustify(words2, maxWidth2);
  cout << "Output:" << endl;
  for (const string &line : result2)
  {
    cout << "\"" << line << "\"" << endl;
  }

  vector<string> words3 = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
  int maxWidth3 = 20;
  vector<string> result3 = solution.fullJustify(words3, maxWidth3);
  cout << "Output:" << endl;
  for (const string &line : result3)
  {
    cout << "\"" << line << "\"" << endl;
  }

  return 0;
}

/*
Time Complexity: O(n), where n is the total number of characters in the words array.
Space Complexity: O(n), where n is the total number of characters in the words array.
*/
