#include <bits/stdc++.h>
using namespace std;

string intToRoman(int num)
{
  vector<pair<int, string>> romanMappings = {
      {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

  string result;

  for (size_t i = 0; i < romanMappings.size(); ++i)
  {
    int value = romanMappings[i].first;
    const string &symbol = romanMappings[i].second;

    while (num >= value)
    {
      result += symbol;
      num -= value;
    }
  }

  return result;
}

int main()
{
  int num = 3749;

  cout << "Input: " << num << ", Output: " << intToRoman(num) << endl;

  return 0;
}

// Time Complexity = O(N)
// Space Complexity = O(N)