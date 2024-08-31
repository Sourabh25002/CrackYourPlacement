#include <bits/stdc++.h>
using namespace std;

// Function to convert string to integer using current letter-to-digit mapping
int getNumber(string str, unordered_map<char, int> &mapping)
{
  int num = 0;
  for (char c : str)
  {
    num = num * 10 + mapping[c];
  }
  return num;
}

// Function to check if the current mapping is valid for the puzzle
bool isValid(string send, string more, string money, unordered_map<char, int> &mapping)
{
  int numSend = getNumber(send, mapping);
  int numMore = getNumber(more, mapping);
  int numMoney = getNumber(money, mapping);
  return numSend + numMore == numMoney;
}

// Recursive function to solve the cryptarithmetic puzzle using backtracking
bool solveCryptarithmetic(string send, string more, string money,
                          unordered_set<char> &letters, vector<int> &digits,
                          unordered_map<char, int> &mapping, set<int> &usedDigits)
{
  if (mapping.size() == letters.size())
  {
    return isValid(send, more, money, mapping);
  }

  // Pick an unassigned letter
  char letter = *letters.begin();
  letters.erase(letter);

  for (int digit : digits)
  {
    if (usedDigits.find(digit) == usedDigits.end())
    {
      mapping[letter] = digit;
      usedDigits.insert(digit);

      if (solveCryptarithmetic(send, more, money, letters, digits, mapping, usedDigits))
      {
        return true;
      }

      // Backtrack
      mapping.erase(letter);
      usedDigits.erase(digit);
    }
  }

  letters.insert(letter);
  return false;
}

int main()
{
  // Puzzle: SEND + MORE = MONEY
  string send = "SEND";
  string more = "MORE";
  string money = "MONEY";

  // Find all unique letters
  unordered_set<char> letters;
  for (char c : send + more + money)
  {
    if (c != ' ')
      letters.insert(c);
  }

  // Prepare digits to be used
  vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  unordered_map<char, int> mapping;
  set<int> usedDigits;

  // Solve the cryptarithmetic puzzle
  if (solveCryptarithmetic(send, more, money, letters, digits, mapping, usedDigits))
  {
    cout << "Solution found:" << endl;
    for (const auto &p : mapping)
    {
      cout << p.first << " -> " << p.second << endl;
    }
  }
  else
  {
    cout << "No solution exists." << endl;
  }

  return 0;
}

/*
Time Complexity: O(d^l), where d is the number of digits and l is the number of unique letters. The algorithm explores all possible assignments of digits to letters.
Space Complexity: O(l + d), where l is the number of unique letters and d is the number of digits. The space is used for storing letters, digits, and the current mapping.
*/
