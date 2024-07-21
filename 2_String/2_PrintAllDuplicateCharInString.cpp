#include <bits/stdc++.h>
using namespace std;

int main()
{

  string s = "geeksforgeeks";
  int n = s.size();

  sort(s.begin(), s.end());

  for (int i = 0; i < n; i++)
  {
    int cnt = 1;

    while (i < n - 1 && s[i] == s[i + 1])
    {
      cnt++;
      i++;
    }

    if (cnt > 1)
      cout << s[i] << " = " << cnt << endl;
  }

  return 0;
}

// Time Complexity = O(NlogN)
// Space Complexity = O(1)