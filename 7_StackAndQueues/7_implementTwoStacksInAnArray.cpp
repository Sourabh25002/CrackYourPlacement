#include <bits/stdc++.h>
using namespace std;

class twoStacks
{
  int *arr;       // Array to hold the elements of both stacks
  int size;       // Size of the array
  int top1, top2; // Pointers to the tops of the two stacks

public:
  // Constructor to initialize the data structures
  twoStacks(int n)
  {
    size = n;
    arr = new int[n];
    top1 = -1;   // Stack1 starts from the beginning of the array
    top2 = size; // Stack2 starts from the end of the array
  }

  // Function to push an integer into the first stack
  void push1(int x)
  {
    // Check for overflow condition
    if (top1 < top2 - 1)
    {
      top1++;
      arr[top1] = x;
    }
    else
    {
      cout << "Stack Overflow" << endl;
      return;
    }
  }

  // Function to push an integer into the second stack
  void push2(int x)
  {
    // Check for overflow condition
    if (top1 < top2 - 1)
    {
      top2--;
      arr[top2] = x;
    }
    else
    {
      cout << "Stack Overflow" << endl;
      return;
    }
  }

  // Function to pop an element from the first stack
  int pop1()
  {
    if (top1 >= 0)
    {
      int x = arr[top1];
      top1--;
      return x;
    }
    else
    {
      return -1; // Stack Underflow
    }
  }

  // Function to pop an element from the second stack
  int pop2()
  {
    if (top2 < size)
    {
      int x = arr[top2];
      top2++;
      return x;
    }
    else
    {
      return -1; // Stack Underflow
    }
  }
};

int main()
{
  twoStacks ts(100); // Initialize two stacks in an array of size 100

  // Example 1
  ts.push1(2);
  ts.push1(3);
  ts.push2(4);
  cout << ts.pop1() << " ";  // Output: 3
  cout << ts.pop2() << " ";  // Output: 4
  cout << ts.pop2() << endl; // Output: -1

  // Example 2
  ts.push1(1);
  ts.push2(2);
  cout << ts.pop1() << " "; // Output: 1
  ts.push1(3);
  cout << ts.pop1() << " ";  // Output: 3
  cout << ts.pop1() << endl; // Output: -1

  return 0;
}

/*
Time Complexity:
- All operations (push1, push2, pop1, pop2) have a time complexity of O(1). Each operation involves only a constant amount of work.

Space Complexity:
- The space complexity is O(n), where n is the size of the array used to store the two stacks. The space is shared between the two stacks.
*/
