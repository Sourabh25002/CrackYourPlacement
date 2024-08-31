#include <bits/stdc++.h>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation.
class NestedInteger
{
public:
  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
private:
  vector<int> flatList; // To store the flattened list
  int index;            // To track the current position in flatList

  // A recursive function to flatten the nested list
  void flatten(const vector<NestedInteger> &nestedList)
  {
    for (const auto &ni : nestedList)
    {
      if (ni.isInteger())
      {
        flatList.push_back(ni.getInteger());
      }
      else
      {
        flatten(ni.getList());
      }
    }
  }

public:
  // Constructor that initializes the iterator with the nested list
  NestedIterator(vector<NestedInteger> &nestedList)
  {
    flatten(nestedList);
    index = 0;
  }

  // Function to return the next integer in the nested list
  int next()
  {
    return flatList[index++];
  }

  // Function to check if there are still some integers left in the nested list
  bool hasNext()
  {
    return index < flatList.size();
  }
};

int main()
{
  // Example 1
  vector<NestedInteger> nestedList1 = {/* Create nested list [[1,1],2,[1,1]] */};
  NestedIterator i1(nestedList1);
  cout << "Example 1 Output: ";
  while (i1.hasNext())
    cout << i1.next() << " "; // Expected Output: 1 1 2 1 1
  cout << endl;

  // Example 2
  vector<NestedInteger> nestedList2 = {/* Create nested list [1,[4,[6]]] */};
  NestedIterator i2(nestedList2);
  cout << "Example 2 Output: ";
  while (i2.hasNext())
    cout << i2.next() << " "; // Expected Output: 1 4 6
  cout << endl;

  return 0;
}

/*
Time Complexity: O(N), where N is the total number of integers in all the nested lists. The constructor flattens the list in a single pass.
Space Complexity: O(N), where N is the total number of integers in the nested list, since we store all the integers in flatList.
*/
