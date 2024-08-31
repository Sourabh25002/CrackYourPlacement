#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string convertToTitle(int columnNumber)
  {
    string result;
    while (columnNumber > 0)
    {
      columnNumber--; // Adjust for 1-based index
      result += char(columnNumber % 26 + 'A');
      columnNumber /= 26;
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

int main()
{
  Solution sol;

  int columnNumber;
  cout << "Input the column number: ";
  cin >> columnNumber;

  cout << "Column title: " << sol.convertToTitle(columnNumber) << endl;

  return 0;
}

/*
Time Complexity: O(log n), where n is the column number, due to the division by 26.
Space Complexity: O(log n), for storing the result string.
*/
