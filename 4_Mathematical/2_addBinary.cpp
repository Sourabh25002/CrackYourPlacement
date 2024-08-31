#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string addBinary(string a, string b)
  {
    string result = "";
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    // Add from right to left
    while (i >= 0 || j >= 0 || carry)
    {
      int sum = carry;
      if (i >= 0)
        sum += a[i--] - '0';
      if (j >= 0)
        sum += b[j--] - '0';

      result += (sum % 2) + '0'; // Add the binary digit
      carry = sum / 2;           // Update the carry
    }

    reverse(result.begin(), result.end()); // The result is in reverse order
    return result;
  }
};

int main()
{
  Solution sol;

  string a, b;
  cout << "Input the first binary string: ";
  cin >> a;
  cout << "Input the second binary string: ";
  cin >> b;

  cout << "Sum of the binary strings: " << sol.addBinary(a, b) << endl;

  return 0;
}

/*
Time Complexity: O(max(M, N)), where M and N are the lengths of the input strings a and b.
Space Complexity: O(max(M, N)), as the result string stores the binary sum.
*/
