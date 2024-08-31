#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string simplifyPath(string path)
  {
    vector<string> stack;
    stringstream ss(path);
    string component;

    // Split the path by '/' and process each component
    while (getline(ss, component, '/'))
    {
      if (component == "." || component.empty())
      {
        continue; // Ignore current directory '.' or empty components
      }
      if (component == "..")
      {
        if (!stack.empty())
        {
          stack.pop_back(); // Move up one directory if possible
        }
      }
      else
      {
        stack.push_back(component); // Valid directory name
      }
    }

    // Rebuild the simplified path
    string simplifiedPath = "/";
    for (int i = 0; i < stack.size(); i++)
    {
      simplifiedPath += stack[i];
      if (i != stack.size() - 1)
      {
        simplifiedPath += "/";
      }
    }

    return simplifiedPath;
  }
};

int main()
{
  Solution sol;

  // Example 1
  string path1 = "/home/";
  cout << "Simplified Path: " << sol.simplifyPath(path1) << endl; // Output: "/home"

  // Example 2
  string path2 = "/home//foo/";
  cout << "Simplified Path: " << sol.simplifyPath(path2) << endl; // Output: "/home/foo"

  // Example 3
  string path3 = "/home/user/Documents/../Pictures";
  cout << "Simplified Path: " << sol.simplifyPath(path3) << endl; // Output: "/home/user/Pictures"

  // Example 4
  string path4 = "/../";
  cout << "Simplified Path: " << sol.simplifyPath(path4) << endl; // Output: "/"

  // Example 5
  string path5 = "/.../a/../b/c/../d/./";
  cout << "Simplified Path: " << sol.simplifyPath(path5) << endl; // Output: "/.../b/d"

  return 0;
}

/*
Time Complexity: O(n), where n is the length of the path.
Space Complexity: O(n), as we use a stack to store valid directories.
*/
