#include <iostream>
#include <vector>
#include <string>

using namespace std;

void parentheses(vector<string> &ans, string s, int n, int left, int right)
{
  if (left == n && right == n)
  {
    ans.push_back(s);
    return;
  }

  if (left < n)
  {
    s += '(';
    parentheses(ans, s, n, left + 1, right);
    s.pop_back();
  }
  if (right < left)
  {
    s += ')';
    parentheses(ans, s, n, left, right + 1);
  }
}

vector<string> generateParenthesis(int n)
{
  vector<string> ans;
  string s = "";
  parentheses(ans, s, n, 0, 0);
  return ans;
}

int main()
{
  int n = 3;

  vector<string> result = generateParenthesis(n);

  cout << "Generated Parentheses Combinations:" << endl;
  for (const string &str : result)
  {
    cout << str << endl;
  }

  return 0;
}
