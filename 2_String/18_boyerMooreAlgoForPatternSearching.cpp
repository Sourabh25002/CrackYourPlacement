#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 256; // Assuming ASCII character set

class BoyerMoore
{
public:
  void search(const string &pat, const string &txt)
  {
    int m = pat.length();
    int n = txt.length();

    // Bad character heuristic table
    vector<int> badCharShift(ALPHABET_SIZE, -1);
    preprocessBadChar(pat, badCharShift);

    int s = 0; // Shift of the pattern with respect to text
    while (s <= n - m)
    {
      int j = m - 1;
      // Compare pattern with text from right to left
      while (j >= 0 && pat[j] == txt[s + j])
      {
        j--;
      }

      // If the pattern is found
      if (j < 0)
      {
        cout << "Pattern found at index " << s << endl;

        // Shift the pattern so that the next character in the text aligns with the last occurrence of the mismatched character in the pattern
        s += (s + m < n) ? m - badCharShift[txt[s + m]] : 1;
      }
      else
      {
        // Shift the pattern based on the bad character heuristic
        s += max(1, j - badCharShift[txt[s + j]]);
      }
    }
  }

private:
  void preprocessBadChar(const string &pat, vector<int> &badCharShift)
  {
    int m = pat.length();
    for (int i = 0; i < m; i++)
    {
      badCharShift[pat[i]] = i;
    }
  }
};

int main()
{
  BoyerMoore bm;

  string txt1 = "THIS IS A TEST TEXT";
  string pat1 = "TEST";
  cout << "Example 1:" << endl;
  bm.search(pat1, txt1);

  string txt2 = "AABAACAADAABAABA";
  string pat2 = "AABA";
  cout << "Example 2:" << endl;
  bm.search(pat2, txt2);

  return 0;
}

/*
Time Complexity: O(n + m), where n is the length of the text and m is the length of the pattern.
Space Complexity: O(ALPHABET_SIZE), which is the size of the bad character heuristic table.
*/
